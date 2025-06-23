# 🚗 ESP32 Parking Slot Monitoring System

A Wi-Fi-based parking slot monitoring system using **ESP32** and **IR sensors**, with a real-time web dashboard for slot occupancy display.

---

## 📷 Dashboard Preview

![Dashboard Screenshot](Screenshot%202025-06-23%20130847.png)

---

## 🛠️ Project Overview

This project uses 10 IR sensors connected to an ESP32 board to detect parking slot occupancy. It runs a lightweight web server to show live slot status on any browser in the same Wi-Fi network.

---

## 🔧 Hardware Required

| Component           | Quantity |
|--------------------|----------|
| ESP32 Dev Board     | 1        |
| IR Sensors (active LOW) | 10       |
| Breadboard / PCB    | 1        |
| Jumper Wires        | As needed |
| USB Cable           | 1        |

---

## ⚙️ GPIO Pin Configuration

| Slot | ESP32 GPIO |
|------|------------|
| 1    | 2          |
| 2    | 4          |
| 3    | 5          |
| 4    | 12         |
| 5    | 13         |
| 6    | 14         |
| 7    | 15         |
| 8    | 16         |
| 9    | 17         |
| 10   | 18         |

> Internal pull-ups are used to avoid floating pin states.

---

## 🌐 Features

- Real-time web dashboard
- Color-coded display (🔴 Occupied / 🟢 Free)
- Auto-refresh every 5 seconds
- Simple and mobile-friendly layout

---


---

## 🔌 Setup Instructions

1. **Clone the Repo**
   ```bash
   git clone https://github.com/Arjunros/ESP32-Parking-Slot-Monitor.git

## Open in Arduino IDE

- Open SmartParkingSystem.ino
- Set board to ESP32 Dev Module
-Update WiFi Credentials

## Replace this part of the code:
const char* ssid = "ARJUNA_BHAVAN";
const char* password = "Arjunabhavan#";

## Upload and Run
- Upload the code to your ESP32
- Open Serial Monitor (baud: 115200)
- Note the IP address

## Open Dashboard
Enter the IP in your browser (e.g., http://192.168.1.37)


