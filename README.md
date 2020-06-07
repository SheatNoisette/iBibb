# iBibb
A old project using hydroponics made between 2016 - 2017.
This project was a simple hydroponics farm made using an Arduino.
It use Seeed Studio Groove interface to connect modules on the Arduino (Mega).

`Firmware` contains the original Arduino code.

`AndroidApp` contains the re-made Android App to control de hydroponic system. 
The original Java Application source code is unusable and only the MIT Inventor App is present in this repository. To import to App Inventor, you need to compress as a zip file the content of the folder `AndroidApp` (Not the folder, but what is inside the folder). You should have three folders in the root of the zip archive. Then change to file extension to `aia` (Example: `app.zip` should be `app.aia`). Thus, you should be able to load the app into App Inventor.

A lot of comments was written in French and will not be translated.

# Modules used and building the firmware

There are the modules used to do this project :
* Arduino Mega
* Grove Base Shield for Arduino Mega 
* Groove DHT11 Module
* Waterproof DS18B20 based temperature sensor
* Grove Ultrasound sensor V2
* Grove HLS8L-DC3V-S-C Relay (for water pump)
* DFROBOT SEN0161 pHMeter
* Grove SI1145 Light sensor
* HC-06 Bluetooth module
* Grove OLED Display 0.96

In the firmware source code, the DS1307 library is required as a dependency but is not used.
Only basic time reading is supported and therefore is unused.

SI114X, OneWire, SeeedOLED, Adafruit DHT11 Lib and DS1307 libraries are required to build the firmware.

# License
See `LICENSE` for details.
The iBibb logo is under the CC 4.0 BY-SA license.
