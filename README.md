
# 🕹️ Button-Controlled RC Car using Arduino Nano and NRF24L01

## 🔍 Overview

This project is a wireless remote-controlled car system operated using physical push buttons. When the user presses directional buttons (forward, backward, left, right), commands are sent wirelessly via NRF24L01 from a transmitter module to the car, which then executes motor control using an L298N driver and Arduino Nano.

## ⚙️ System Components

### 🔹 Transmitter (Remote Control)
- Arduino Nano
- Push Buttons (Forward, Backward, Left, Right)
- NRF24L01 Module
- Power Supply: 5V

### 🔹 Receiver (Car)
- Arduino Nano
- NRF24L01 Module
- L298N Motor Driver
- 4 DC Gear Motors
- Power Supply: 7.4V Li-ion Battery

## 🛠️ Features

- Control directions: Forward, Backward, Left, Right, Stop
- Real-time wireless transmission using NRF24L01 (2.4GHz)
- Simple and stable communication between two Arduino Nano boards
- Easy-to-build PCB with Proteus schematic support

## 📦 Project Structure

```
📦 button-controlled-car/
 ┣ 📂 Transmitter/        # Code for remote control (button input)
 ┣ 📂 Receiver/           # Code for car (motor output)
 ┣ 📂 schematic/          # Proteus schematics and PCB layout
 ┣ 📄 README.md           # Project documentation
```

## ⚡ Power Supply

| Module         | Voltage | Notes                            |
|----------------|---------|----------------------------------|
| Arduino Nano   | 5V      | Powered via LM2596 or USB        |
| NRF24L01       | 3.3V    | Powered via LM1117-3.3 Regulator |
| L298N Driver   | 5V-12V  | For logic and motors             |
| DC Motors      | 6–9V    | Draw ~110-140mA each             |

## 📡 Communication

- **Transceiver Module:** NRF24L01
- **Frequency Band:** 2.4GHz
- **Range:** ~10–20 meters in open space
- **Data Rate:** 250 Kbps

## 🚧 Limitations

- Basic control only: No speed modulation, no obstacle avoidance
- Limited range due to standard NRF24L01 without external antenna
- No feedback mechanism from the car (one-way communication)

## 🚀 Future Improvements

- Add camera module for FPV
- Upgrade to ESP32 for mobile app control
- Add obstacle detection using ultrasonic sensors
- Use NRF24L01+PA+LNA to extend range


