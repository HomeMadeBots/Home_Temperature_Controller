# Home_Temperature_Controller

This repository defines a package containing a software composition that realize the software
functions required by the Arduino board of the Home Temperature Controller
[system](https://github.com/HomeMadeBots/Home-Temperature-Controller-System).

The package is designed following
[this meta-model](https://github.com/HomeMadeBots/Embedded_Software_Meta_Model) and implemented
according to [these C language
patterns](https://github.com/HomeMadeBots/C-language-patterns-for-Embedded-Software-Meta-Model).

## Content

![Content](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Home_Temperature_Controller/master/doc/content.puml)

## Overview

### Mode_Manager overview

![Mode_Manager overview](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Home_Temperature_Controller/master/doc/Mode_Manager_overview.puml)

### Boiler_Manager overview

![Boiler_Manager overview](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Home_Temperature_Controller/master/doc/Boiler_Manager_overview.puml)

## Dependencies

![Packages dependencies](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.github.com/HomeMadeBots/Home_Temperature_Controller/master/doc/dependencies.puml)

The following packages shall be retrieved :
* [Arduino_Pins](https://github.com/HomeMadeBots/Arduino_Pins)
* [ATmega_One_Wire](https://github.com/HomeMadeBots/ATmega_One_Wire)
* [Bits_Management](https://github.com/HomeMadeBots/Bits_Management)
* [Button_Events](https://github.com/HomeMadeBots/Button_Events)
* [Delays](https://github.com/HomeMadeBots/Delays)
* [DS18B20_Ambient_Air_Temperature_Sensor](https://github.com/HomeMadeBots/DS18B20_Ambient_Air_Temperature_Sensor)
* [Electrical_Relay](https://github.com/HomeMadeBots/Electrical_Relay)
* [Embedded_C_Framework](https://github.com/HomeMadeBots/Embedded_C_Framework)
* [Five_Buttons_Keypad](https://github.com/HomeMadeBots/Five_Buttons_Keypad)
* [Hardware_IO_Interfaces](https://github.com/HomeMadeBots/Hardware_IO_Interfaces)
* [LCD_HD44780_Actuator](https://github.com/HomeMadeBots/LCD_HD44780_Actuator)
* [LCD_Interfaces](https://github.com/HomeMadeBots/LCD_Interfaces)
* [One_Wire_Interfaces](https://github.com/HomeMadeBots/One_Wire_Interfaces)
* [Physical_Quantities_Interfaces](https://github.com/HomeMadeBots/Physical_Quantities_Interfaces)
* [Time_Measurement](https://github.com/HomeMadeBots/Time_Measurement)
* [Timers](https://github.com/HomeMadeBots/Timers)

## Use

### With the Arduino IDE

This repository shall be clone within the _Arduino sketchbook folder_.