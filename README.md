# 🚗 Arduino Self-Driving Car with HC-SR04

This is an **Arduino-based self-driving car** that uses an **HC-SR04 ultrasonic sensor** to detect obstacles and navigate autonomously. The car moves forward until it detects an obstacle within a certain range, then it stops, reverses, and turns before continuing.

## 📌 Features
- **Obstacle detection** using an ultrasonic sensor.
- **Automatic movement** (forward, reverse, left turn, right turn).
- **Collision avoidance** with real-time distance measurement.

---

## 🛠 Components Required
| Component          | Quantity |
|-------------------|---------|
| Arduino Uno       | 1       |
| HC-SR04 Ultrasonic Sensor | 1       |
| L298N Motor Driver Module | 1       |
| DC Motors        | 2       |
| Wheels           | 2       |
| Power Source (Battery Pack) | 1       |
| Jumper Wires     | As needed |

---

## ⚙️ Circuit Diagram
Connect the components as follows:

### **Ultrasonic Sensor (HC-SR04) to Arduino**
| HC-SR04 Pin | Arduino Pin |
|------------|-------------|
| VCC        | 5V          |
| GND        | GND         |
| TRIG       | 11          |
| ECHO       | 12          |

### **Motor Driver (L298N) to Arduino**
| L298N Pin | Arduino Pin |
|-----------|-------------|
| ENA       | 9           |
| IN1       | 8           |
| IN2       | 7           |
| IN3       | 6           |
| IN4       | 5           |
| ENB       | 10          |
| GND       | GND         |
| VCC       | Battery (e.g., 7.4V-12V) |

---

## 🔧 Installation & Setup
1. **Connect** the components as per the circuit diagram.
2. **Download & Install** the Arduino IDE if not already installed: [Arduino IDE](https://www.arduino.cc/en/software)
3. **Clone this repository**:
   ```sh
