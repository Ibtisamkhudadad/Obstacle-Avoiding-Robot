# Autonomous Obstacle-Avoiding Robot

An Arduino-based autonomous robot that detects obstacles using an ultrasonic sensor and automatically navigates around them by choosing the clearer path (left or right).

Built as a group project for the **Introduction to Robotics** course at the Department of Computer Science, Fatima Jinnah Women University, Rawalpindi.

## 👥 Group Members

- Aqsa Fida
- Ibtisam
- Irza Hameed
- Mishal Raziq
- Rabbia Noor

**Course Instructor:** Ms. Ghazal Jalali

## 📌 Abstract

This project presents the design and execution of an autonomous obstacle detection and avoidance robot. The system uses an Arduino Uno as its core processing unit, an HC-SR04 ultrasonic sensor for real-time space scanning, and an SG90 servo motor to steer the sensor's field of view. When the robot detects an obstacle within a 15–20 cm threshold, it stops, backs up to clear room, scans left and right, and switches direction toward the more open path. Two TT gear motors, driven by an L298N motor driver and powered by a 4-cell battery pack, handle the physical movement.

## 🎯 Objectives

- Design a fully functional, autonomous wheeled robotic platform
- Interface an ultrasonic distance sensor with an Arduino Uno for real-world environmental feedback
- Implement a reactive C/C++ algorithm for real-time steering decisions
- Detect obstacles and prevent collisions automatically
- Demonstrate autonomous navigation and apply core robotics concepts from the course

## 🛠️ Hardware Components

| Component | Quantity | Purpose |
|---|---|---|
| Arduino Uno R3 | 1 | Main microcontroller running the control logic |
| HC-SR04 Ultrasonic Sensor | 1 | Measures distance to obstacles using sound waves |
| SG90 Servo Motor | 1 | Rotates the ultrasonic sensor to scan left/right |
| L298N Motor Driver Module | 1 | Drives the two DC gear motors |
| TT Gear Motors | 2 | Left and right wheel drive |
| Caster Wheel | 1 | Third wheel for balance |
| Battery Holder + 4 Cell Batteries | 1 | Powers the system (6–9V) |
| Jumper Wires (M-M & F-M) | 35–40 | Wiring connections |
| USB Cable | 1 | Uploading code from computer to Arduino |

## 🔌 Pin Mapping

| Component & Pin | Arduino Pin | Signal Type |
|---|---|---|
| HC-SR04 Trig Pin | Pin 9 | Digital Output (triggers ultrasonic pulse) |
| HC-SR04 Echo Pin | Pin 8 | Digital Input (reads echo duration) |
| SG90 Servo Signal | Pin 10 | PWM Output (controls sweep angle) |
| L298N IN1 (Left Motor a) | Pin 4 | Digital Output |
| L298N IN2 (Left Motor b) | Pin 5 | Digital Output |
| L298N IN3 (Right Motor a) | Pin 6 | Digital Output |
| L298N IN4 (Right Motor b) | Pin 7 | Digital Output |
| All component GNDs | GND | Common ground reference |

## ⚙️ How It Works

1. Servo keeps the ultrasonic sensor facing forward while the robot drives straight
2. If the measured distance drops to ~20 cm or less, the robot:
   - Stops and briefly reverses to create turning space
   - Sweeps the servo left (150°) and right (30°) to measure open space on each side
   - Compares both readings and turns toward the side with more clearance
3. Loop repeats continuously

## 🔧 Build Notes

- **Board recognition:** Budget Arduino clone boards use a CH340 USB-to-Serial chip, which may need its dedicated driver installed before the board is recognized by your computer (creates a stable COM port for uploading code).
- **Solderless wiring:** Male-to-male jumper wires were modified by stripping ~1 cm of insulation and twisting the exposed copper around the motor terminals, then insulated with electrical tape — avoiding the need for soldering.

## 📂 Files

| File | Description |
|---|---|
| `obstacle_avoiding_robot.ino` | Full Arduino sketch — sensor reading, movement control, and obstacle-avoidance decision logic |

## 🔧 How to Run

1. Open `obstacle_avoiding_robot.ino` in the Arduino IDE
2. Wire up the components according to the pin mapping table above
3. Upload to the Arduino board
4. Power the robot — it will drive forward and autonomously avoid obstacles

## 🚀 Future Enhancements

- **Steering calibration:** Fine-tune the turn duration parameter for sharper or subtler pivot adjustments depending on the environment
- **Lateral sensors:** Add side-facing IR or ultrasonic sensors to prevent side-swipe collisions in narrow corridors
- **Power upgrade:** Move to a rechargeable 7.4V Li-ion battery pack with a buck converter for more stable power delivery

## 👤 My Contribution

Worked as part of a 5-member team on the obstacle-detection and navigation logic, including the left/right comparison decision for choosing the clearer path.

