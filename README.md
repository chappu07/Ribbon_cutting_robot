# Bluetooth Controlled Automatic Ribbon Cutting Robot

## Overview

The **Bluetooth Controlled Automatic Ribbon Cutting Robot** is an Arduino-based robotic system developed to automate ribbon-cutting ceremonies during inaugurations, events, and special occasions. The robot is remotely controlled using a Bluetooth-enabled smartphone and is equipped with a DC motor-driven cutting mechanism to cut ribbons precisely.

The system allows the operator to navigate the robot to the ribbon location and activate the cutter wirelessly, eliminating the need for manual ribbon cutting.

---

# Features

* Bluetooth-based wireless control
* Forward and backward movement
* Left and right turning
* Smooth motor acceleration
* Remote-controlled ribbon cutting mechanism
* Independent cutter motor control
* Emergency stop functionality
* Compact and portable design

---

# Hardware Requirements

| Component                       | Quantity |
| ------------------------------- | -------- |
| Arduino Uno/Nano                | 1        |
| HC-05/HC-06 Bluetooth Module    | 1        |
| Motor Driver Module             | 1        |
| DC Gear Motors                  | 4        |
| cutting mechanism               | 1        |
| Robot Chassis                   | 1        |
| Battery Pack                    | 1        |
| Wheels                          | 4        |
| HW-039 motor driver             | 2        |
| l298n motor driver              | 1        |
---

# Pin Configuration

## Bluetooth Module

| Arduino Pin | Function |
| ----------- | -------- |
| D10         | RX       |
| D11         | TX       |

## Left Drive Motor

| Arduino Pin | Function    |
| ----------- | ----------- |
| D9          | Forward PWM |
| D6          | Reverse PWM |

## Right Drive Motor

| Arduino Pin | Function    |
| ----------- | ----------- |
| D5          | Forward PWM |
| D2          | Reverse PWM |

## Ribbon Cutter Motor

| Arduino Pin | Function      |
| ----------- | ------------- |
| D11         | Enable (PWM)  |
| D12         | Direction IN1 |
| D13         | Direction IN2 |

---

# Bluetooth Commands

| Command | Function             |
| ------- | -------------------- |
| **F**   | Move Forward         |
| **B**   | Move Backward        |
| **L**   | Turn Left            |
| **R**   | Turn Right           |
| **S**   | Stop Robot           |
| **X**   | Start Ribbon Cutter  |
| **Y**   | Reverse Cutter Motor |
| **Z**   | Stop Cutter          |

---

# Working Principle

1. Switch on the robot and pair the Bluetooth module with a smartphone.
2. Use a Bluetooth controller application to send movement commands.
3. Navigate the robot to the ribbon.
4. Position the cutting mechanism accurately.
5. Send the cutter command to activate the blade.
6. The ribbon is cut remotely, completing the inauguration process safely and efficiently.

---

# Software Requirements

* Arduino IDE
* SoftwareSerial Library

---

# Applications

* Inauguration ceremonies
* College and university events
* Government functions
* Corporate product launches
* Exhibition openings
* Cultural and public events
* Smart event automation
