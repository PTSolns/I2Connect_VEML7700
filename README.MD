# PTSolns *I2Connect: VEML7700* Library

![Arduino Library](https://img.shields.io/badge/Arduino-Library-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Sensor](https://img.shields.io/badge/Sensor-Ambient_Light-yellow)

Library for the PTSolns *I2Connect: VEML7700* module. Available through both the Arduino Library Manager and the PTSolns IDE Library Manager, this library provides a simple and reliable way to add light sensing capabilities to embedded systems. 

---

## Overview

The PTSolns *I2Connect: VEML7700* is a compact ambient light sensing module based on the VEML7700 digital sensor. The sensor communicates over the industry standard I2C interface and delivers ambient light measurements in lux (lx) with minimal software overhead.

The *I2Connect: VEML7700* is intended for hobby and educational applications where ambient light monitoring is required. Typical applications include automatic display brightness control, smart lighting systems, day and night detection, weather stations, environmental monitoring systems, and general purpose data acquisition projects. 

Like all *I2Connect* modules, the *I2Connect: VEML7700* is fully assembled and ready to use out of the box. Dual Qwiic® compatible connectors allow the module to be easily integrated into existing I2C systems without soldering, while the preinstalled right angle header provides direct access to the I2C bus for breadboard based prototyping. 

---

## *I2Connect* Series

The PTSolns *I2Connect* Series is a family of plug and play expansion modules designed to simplify the integration of sensors, displays, user interfaces, and other peripherals into embedded systems. Built around the industry standard I2C communication protocol and featuring convenient Qwiic compatible connectors (4 pin, 1 mm JST SH), *I2Connect* modules can be quickly connected without soldering or complex wiring.

Each module is fully assembled and includes a preinstalled male header that is compatible with standard solderless breadboards, enabling immediate use and rapid prototyping. Designed to work seamlessly with a wide range of microcontroller platforms, I2Connect modules combine compact hardware, comprehensive documentation, and easy to use software libraries. The _I2Connect_ Series enables makers, students, educators, and professionals to rapidly prototype, evaluate, and develop reliable electronic systems.

The following modules are part of the *I2Connect* Series:

* [**AHT20**](https://ptsolns.com/products/i2connect-aht20) — Temperature & Humidity
* [**VEML7700**](https://ptsolns.com/products/i2connect-veml7700) — Light & Lux
* [**EEPROM**](https://ptsolns.com/products/i2connect-eeprom) — 2Mbit Memory
* **Buttons** — User Input via 4x4 Matrix of Buttons
* **Digit Display** — 2x 7-Segment Displays
* **ICO-20100** — Pressure & Temperature
* **KXTJ3-1057** — 3-Axis Accelerometer
* **MUX** — 4-Channel I2C Multiplexer
* **OLED** — 0.96" 128x64 OLED Display
* **I2C Doctor** — Improve I2C Bus
* **...and more!**

---

## Key Features

* Ambient light measurements in lux (lx)
* Compatible with both 3.3 V and 5 V systems
* Fixed 0x10 I2C address
* Dual Qwiic® compatible connectors (4 pin, 1 mm JST SH) for daisy-chaining.
* Breadboard friendly right angle male header
* Dedicated software library for easy configuration and reading
* Integrated power LED with a physical disconnect pad on the rear.

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

This connector follows the widely adopted Qwiic® standard, allowing modules and compatible boards to be connected without soldering.

For maximum compatibility, the module also includes a preinstalled angled male header, allowing use with virtually any 3.3 V or 5 V microcontroller system that supports I2C communication, even if a Qwiic® compatible connector is not available.

---

## Module Specifications

| Parameter               | Value                        |
| ----------------------- | ---------------------------- |
| Sensor                  | VEML7700           |
| Measurement             | Light, Lux         |
| Interface               | I2C                |
| I2C Address             | 0x10          |
| Supply Voltage          | 3.3 V and 5 V compatible |
| Length                  | 23.2 mm          |
| Width                   | 22.9 mm          |
| Weight                  | 3 g              |

---

## Address Selection

The *I2Connect: VEML7700* module uses a fixed I2C address of `0x10`. 

This address cannot be modified. If multiple VEML7700 modules are required in the same system, an I2C multiplexer must be used. The PTSolns *I2Connect: MUX* module provides four independent I2C channels, allowing up to four VEML7700 modules with the same fixed I2C address to be connected to a single microcontroller.

---

## *PTSolns IDE*

The [*PTSolns IDE*](https://ptsolns.com/ide) is a free desktop application for programming PTSolns microcontroller development boards and compatible Arduino platforms.

This library is available directly through both the PTSolns IDE Library Manager and the Arduino Library Manager.

To install:

1. Open the PTSolns IDE (or Arduino IDE).
2. Open the Library Manager.
3. Search for:

```text
I2Connect_VEML7700
