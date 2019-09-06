# LEDClock

Bau einer Uhr mit LED und einem Arduino.

### Eingesetzte Hardware
- Arduino Nano v3
- <a href="https://www.ebay.de/itm/DS3231-AT24C32-Erinnerung-Modul-Arduino-IIC-Präzision-RTC-Real-Time-Clock-RLD537/142905177651">DS3231 RTC Real Time Clock</a>
- <a href="https://www.ebay.de/itm/60-Bits-Ring-Wall-Clock-WS2812-5050-RGB-LED-Ultra-Bright-Lamp-Panel-For-Arduino/401709639961">60 Bits Ring WS2812 5050 RGB LED</a>
- <a href="https://www.amazon.de/gp/product/B002ZHELBA/">Deckel von dieser Holz-Box</a>
- <a href="https://www.amazon.de/gp/product/B07TPSB35N/">LED Strip (Abschnitte abgeschnitten und neu verbunden)</a>
- <a href="https://www.ebay.de/itm/10-Stck-127-Werte-Ohm-Sortiment-1-Ohm-1-MOhm-Widerstand-Metallfilm-Widerstände/142446356352">470 Ohm Widerstand für LED</a>
- <a href="https://www.amazon.de/gp/product/B00IJWQ7P8/">LIR-2032 Knopfzelle für den DS3231</a>
- Sonstiges (nach Bedarf): Stromversorgung (bspw. kleine Powerbank), Kabel, Klebeband, An-/Ausknopf

### Verbindung zwischen Arduino und RTC
Das DS3231 Modul verfügt über 6 PIN’s welche wiefolgt am Arduino Nano angeschlossen werden:

- 32K – ohne Belegung
- SQW – ohne Belegung
- SCL – analog PIN A5
- SDA – analog PIN A4
- VCC – 5V
- GND – GND

### Anleitung
- Installieren der Bibliotheken "Adafruit Neopixel" und "RTClib", beides von Adafruit
- LEDs (Data) mit den Digitalen Pins vom Arduino verbinden (hier werden die Widerstände zwischengeschaltet)
- Stromversorgung: 5V und GND (aufgesplittet) geht an die LED Strips und Ring
- LEDClock.ino aufspielen. Beim ersten hochladen wird die Uhr des DS3231 automatisch eingestellt (zum reseten muss die Batterie für 3 Sekunden rausgenommen werden).

Weitere Beschreibung/Anleitung folgt.