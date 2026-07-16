# PTSolns *I2Connect: VEML7700* Library

![Arduino Library](https://img.shields.io/badge/Arduino-Library-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Sensor](https://img.shields.io/badge/Sensor-Ambient_Light-yellow)

[cite_start]Library for the PTSolns *I2Connect: VEML7700* module[cite: 6]. [cite_start]Available through both the Arduino Library Manager and the PTSolns IDE Library Manager, this library provides a simple and reliable way to add light sensing capabilities to embedded systems[cite: 7, 148]. 

---

## Overview

[cite_start]The PTSolns *I2Connect: VEML7700* is a compact ambient light sensing module based on the VEML7700 digital sensor[cite: 6]. [cite_start]The sensor communicates over the industry standard I2C interface and delivers ambient light measurements in lux (lx) with minimal software overhead[cite: 8].

[cite_start]The *I2Connect: VEML7700* is intended for hobby and educational applications where ambient light monitoring is required[cite: 16]. [cite_start]Typical applications include automatic display brightness control, smart lighting systems, day and night detection, weather stations, environmental monitoring systems, and general purpose data acquisition projects[cite: 17]. 

[cite_start]Like all *I2Connect* modules, the *I2Connect: VEML7700* is fully assembled and ready to use out of the box[cite: 9]. [cite_start]Dual Qwiic® compatible connectors allow the module to be easily integrated into existing I2C systems without soldering, while the preinstalled right angle header provides direct access to the I2C bus for breadboard based prototyping[cite: 10]. 

---

## *I2Connect* Series

[cite_start]The PTSolns *I2Connect* Series is a family of plug and play expansion modules designed to simplify the integration of sensors, displays, user interfaces, and other peripherals into embedded systems[cite: 39]. [cite_start]Built around the industry standard I2C communication protocol and featuring convenient Qwiic compatible connectors (4 pin, 1 mm JST SH), *I2Connect* modules can be quickly connected without soldering or complex wiring[cite: 40].

[cite_start]Each module is fully assembled and includes a preinstalled male header that is compatible with standard solderless breadboards, enabling immediate use and rapid prototyping[cite: 41]. [cite_start]Designed to work seamlessly with a wide range of microcontroller platforms, I2Connect modules combine compact hardware, comprehensive documentation, and easy to use software libraries[cite: 42]. [cite_start]The _I2Connect_ Series enables makers, students, educators, and professionals to rapidly prototype, evaluate, and develop reliable electronic systems[cite: 43].

The following modules are part of the *I2Connect* Series:

* [cite_start][**AHT20**](https://ptsolns.com/products/i2connect-aht20) — Temperature & Humidity [cite: 45]
* [cite_start][**VEML7700**](https://ptsolns.com/products/i2connect-veml7700) — Light & Lux [cite: 46]
* [cite_start][**EEPROM**](https://ptsolns.com/products/i2connect-eeprom) — 2Mbit Memory [cite: 47]
* [cite_start]**Buttons** — User Input via 4x4 Matrix of Buttons [cite: 48]
* [cite_start]**Digit Display** — 2x 7-Segment Displays [cite: 48]
* [cite_start]**ICO-20100** — Pressure & Temperature [cite: 49]
* [cite_start]**KXTJ3-1057** — 3-Axis Accelerometer [cite: 49]
* [cite_start]**MUX** — 4-Channel I2C Multiplexer [cite: 50]
* [cite_start]**OLED** — 0.96" 128x64 OLED Display [cite: 50]
* [cite_start]**I2C Doctor** — Improve I2C Bus [cite: 50]
* [cite_start]**...and more!** [cite: 50]

---

## Key Features

* [cite_start]Ambient light measurements in lux (lx) [cite: 8]
* [cite_start]Compatible with both 3.3 V and 5 V systems [cite: 11, 15]
* [cite_start]Fixed 0x10 I2C address [cite: 96, 97]
* [cite_start]Dual Qwiic® compatible connectors (4 pin, 1 mm JST SH) [cite: 105]
* [cite_start]Breadboard friendly right angle male header [cite: 113]
* [cite_start]Dedicated software library for easy configuration and reading [cite: 146, 147]

---

## I2Connect Ecosystem

The *I2Connect: VEML7700* is part of the PTSolns I2Connect ecosystem.

All *I2Connect* modules utilize a standardized 4 pin JST SH 1.0 mm connector carrying:

| Pin | Function |
| --- | -------- |
| 1   | GND      |
| 2   | VCC      |
| 3   | SDA      |
| 4   | SCL      |

[cite_start]This connector follows the widely adopted Qwiic® standard, allowing modules and compatible boards to be connected without soldering[cite: 133].

[cite_start]For maximum compatibility, the module also includes a preinstalled angled male header, allowing use with virtually any 3.3 V or 5 V microcontroller system that supports I2C communication, even if a Qwiic® compatible connector is not available[cite: 134].

---

## Module Specifications

| Parameter               | Value                        |
| ----------------------- | ---------------------------- |
| Sensor                  | [cite_start]VEML7700 [cite: 6]           |
| Measurement             | [cite_start]Light, Lux [cite: 2]         |
| Interface               | [cite_start]I2C [cite: 8]                |
| I2C Address             | [cite_start]0x10 [cite: 96, 97]          |
| Supply Voltage          | [cite_start]3.3 V and 5 V compatible [cite: 11, 15] |
| Length                  | [cite_start]23.2 mm [cite: 173]          |
| Width                   | [cite_start]22.9 mm [cite: 179]          |
| Weight                  | [cite_start]3 g [cite: 182]              |

---

## Address Selection

[cite_start]The *I2Connect: VEML7700* module uses a fixed I2C address of `0x10`[cite: 96, 97]. 

[cite_start]This address cannot be modified[cite: 98]. [cite_start]If multiple VEML7700 modules are required in the same system, an I2C multiplexer must be used[cite: 98]. [cite_start]The PTSolns *I2Connect: MUX* module provides four independent I2C channels, allowing up to four VEML7700 modules with the same fixed I2C address to be connected to a single microcontroller[cite: 99].

---

## *PTSolns IDE*

[cite_start]The [*PTSolns IDE*](https://ptsolns.com/ide) is a free desktop application for programming PTSolns microcontroller development boards and compatible Arduino platforms.

[cite_start]This library is available directly through both the PTSolns IDE Library Manager and the Arduino Library Manager[cite: 148].

To install:

1. Open the PTSolns IDE (or Arduino IDE).
2. Open the Library Manager.
3. Search for:

```text
I2Connect_VEML7700
