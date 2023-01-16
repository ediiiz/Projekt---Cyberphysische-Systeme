#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Wire.h>
#include <PubSubClient.h>

#define NUM_VALUES 60     // Number of values to average over
#define POLL_INTERVAL 500 // poll interval in milliseconds

int values[NUM_VALUES];         // Array to store the last 60 db values
int currentIndex = 0;           // Current index in the array
unsigned long lastPoll = 0;     // variable to store the time of the last poll
const char *ssid = "Ediz-M20P"; // replace with your wifi ssid and wpa2 key
const char *pass = "12345678";
const char *mqtt_server = "192.168.43.192";
const int mqtt_port = 1883;                 
const char *mqtt_topic = "soundlevelmeter"; 
const char *mqtt_username = "ediz";
const char *mqtt_password = "ediz";
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

// Clients
WiFiClient wifiClient;
PubSubClient mqttclient(mqtt_server, mqtt_port, wifiClient);

//Main

void setup()
{
  Serial.begin(115200); // Serial comms
  delay(2000);          // wait 2 seconds

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  mqttclient.setServer(mqtt_server, mqtt_port);
  
  for (int i = 0; i < NUM_VALUES; i++) // Resetting the Array
  {
    values[i] = 0;
  }
}

void loop()
{
  unsigned long startMillis = millis(); // Start of sample window
  float peakToPeak = 0;                 // peak-to-peak level

  unsigned int signalMax = 0;    // minimum value
  unsigned int signalMin = 1024; // maximum value

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(0); // get reading from microphone
    if (sample < 1024)      // toss out spurious readings
    {
      if (sample > signalMax)
      {
        signalMax = sample; // save just the max levels
      }
      else if (sample < signalMin)
      {
        signalMin = sample; // save just the min levels
      }
    }
  }
  peakToPeak = signalMax - signalMin;         // max - min = peak-peak amplitude
  float db = map(peakToPeak, 0, 600, 25, 80); // calibrate for deciBels

  values[currentIndex] = db; // Add the current db value to the array
  currentIndex++;            // Increment the current index

  if (currentIndex >= NUM_VALUES)
  {
    currentIndex = 0;
  }

  int sum = 0;
  for (int i = 0; i < NUM_VALUES; i++)
  {
    sum += values[i];
  }

  float avg = (float)sum / NUM_VALUES; // Calculate the average of the values in the array

  sendToMQTT(avg); // Sends the average value to the mqtt broker if more than 500ms have passed

  delay(50);
}

void reconnect()
{
  // Loop until we're reconnected
  while (!mqttclient.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect with authentication
    if (mqttclient.connect("ArduinoClient", mqtt_username, mqtt_password))
    {
      Serial.println("connected");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(mqttclient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void sendToMQTT(float avg)
{
  if (!mqttclient.connected())
  {
    reconnect();
  }

  mqttclient.loop();

  if (millis() - lastPoll >= POLL_INTERVAL)
  {
    lastPoll = millis();
    // Publish the average db value to the MQTT topic
    char avgStr[10];
    dtostrf(avg, 6, 2, avgStr);
    mqttclient.publish(mqtt_topic, avgStr);
  }
}
