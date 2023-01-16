# Dokumentation zur Planung eines Systems zur Überwachung und Steuerung des Klassenraumlärms

## 1. Einführung

Das Ziel dieses Projekts ist es, ein cyberphysischen System zu planen und zu realisieren, das die Überwachung und Steuerung des Klassenraumlärms ermöglicht. Das System soll dazu beitragen, die Konzentration und Leistungsfähigkeit der Schüler zu fördern und den Unterrichtsablauf zu verbessern.

## 2. Anforderungsanalyse

Die Anforderungen an das System werden wie folgt festgelegt:

- Das System soll die Lautstärke im Klassenraum messen und die Schüleraktivität überwachen.
- Es soll möglich sein, Sollwerte für die Lautstärke im Klassenraum festzulegen.
- Das System soll die Sensordaten mittels Microcontrollern und entsprechenden Sensoren messen und übertragen.
- Die Übertragung der Sensordaten soll mittels WLAN, LAN oder 2,4 GHz Funk erfolgen.
- Die Sensordaten sollen mit einem mqtt broker erfasst werden.
- Die Sensordaten sollen in einer MySQL-Datenbank gespeichert werden.
- Die Sensordaten sollen in einer selbstprogrammierten Anwendung verarbeitet und Sollwerte ermittelt werden.
- Die Sollwerte sollen an Aktoren übertragen werden.
- Der aktuelle Zustand und der zeitliche Verlauf sollen visualisiert und im Browser interagiert werden können.

## 3. Systemarchitektur

Die Systemarchitektur des Klassenraumlärm-Überwachungssystems wird wie folgt aussehen:

- Microcontroller und Sensoren werden im Klassenraum installiert, um die Lautstärke und Schüleraktivität zu messen.
- Die Sensordaten werden mittels WLAN, LAN oder 2,4 GHz Funk an einen mqtt broker übertragen.
- Der mqtt broker leitet die Sensordaten an eine MySQL-Datenbank weiter, in der sie gespeichert werden.
- Eine selbstprogrammierte Anwendung verarbeitet die Sensordaten und ermittelt Sollwerte.
- Die Sollwerte werden über mqtt an die Aktoren im Klassenraum übertragen, um die Lautstärke anzuzeigen.
- Eine Web-App ermöglicht es, den aktuellen Zustand und den zeitlichen Verlauf der Lautstärke im Klassenraum zu visualisieren und zu interagieren.

## 4. Funktionsbeschreibung

Das Klassenraumlärm-Überwachungssystem wird folgende Funktionen ausführen:

- Messung der Lautstärke im Klassenraum mittels Microcontrollern und Sensoren.
- Übertragung der Sensordaten mittels WLAN, LAN oder 2,4 GHz Funk an einen mqtt broker.
- Erfassung der Sensordaten durch den mqtt broker und Weiterleitung an eine MySQL-Datenbank.
- Verarbeitung der Sensordaten in einer selbstprogrammierten Anwendung und Ermittlung von Sollwerten.
- Übertragung der Sollwerte an Aktoren im Klassenraum mittels mqtt.
- Visualisierung des aktuellen Zustands und des zeitlichen Verlaufs der Lautstärke im Klassenraum in einer Web-App und Möglichkeit zur Interaktion.

## 5. Implementierung

Die Implementierung des Klassenraumlärm-Überwachungssystems erfolgt in mehreren Schritten:

1. Auswahl und Beschaffung der Hardware, wie Microcontroller, Sensoren, Aktoren und WLAN-Module.
2. Programmierung der Microcontroller und Sensoren für die Messung der Lautstärke und Übertragung der Daten.
3. Einrichtung und Konfiguration des mqtt brokers und der MySQL-Datenbank.
4. Entwicklung der selbstprogrammierten Anwendung zur Verarbeitung der Sensordaten und Ermittlung von Sollwerten.
5. Programmierung der Aktoren für die Steuerung der Lautstärke mittels mqtt.
6. Erstellung der Web-App zur Visualisierung und Interaktion.
7. Integration und Test aller Komponenten.
8. Deployment des Systems im Klassenraum.

## 6. Projektplan

Der Projektplan für die Realisierung des Klassenraumlärm-Überwachungssystems sieht wie folgt aus:

1. Woche: Programmierung der Microcontroller und Sensoren sowie Einrichtung und Konfiguration des mqtt brokers und der MySQL-Datenbank.
2. Woche: Entwicklung der selbstprogrammierten Anwendung und Programmierung der Aktoren. Erstellung der Web-App. Integration und Test aller Komponenten. Deployment im Klassenraum.

### Gantt Diagramm


## 7. Zusammenfassung

Das Klassenraumlärm-Überwachungssystem ist eine Automatisierung und Steuerung, die dazu beitragen soll, die Konzentration und Leistungsfähigkeit der Schüler zu fördern und den Unterrichtsablauf zu verbessern. Das System wird die Lautstärke im Klassenraum messen und die Schüleraktivität überwachen. Es wird möglich sein, Sollwerte für die Lautstärke im Klassenraum festzulegen. Die Sensordaten werden mittels Microcontrollern und Sensoren gemessen und übertragen. Die Übertragung der Sensordaten wird mittels WLAN, LAN oder 2,4 GHz Funk erfolgen. Die Sensordaten werden mit einem mqtt broker erfasst und in einer MySQL-Datenbank gespeichert. Die Sensordaten werden in einer selbstprogrammierten Anwendung verarbeitet und Sollwerte ermittelt. Die Sollwerte werden an Aktoren im Klassenraum übertragen, um die Lautstärke zu steuern. Der aktuelle Zustand und der zeitliche Verlauf der Lautstärke im Klassenraum werden visualisiert und im Browser interagiert werden können. Das System wird in mehreren Schritten implementiert, wobei jeder Schritt sorgfältig geplant und überwacht wird, um mögliche Risiken zu minimieren. Das Projekt wird innerhalb von 3 Wochen abgeschlossen sein.
