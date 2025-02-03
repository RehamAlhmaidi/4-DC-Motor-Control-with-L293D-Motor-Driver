# 4-DC-Motor-Control-with-L293D-Motor-Driver



## 📌 Overview
This project demonstrates how to control **four DC motors** using **two L293D motor drivers** and an **Arduino Uno**. The motors execute a predefined sequence of movements based on time intervals



### **🛠 Movements Sequence**
1. **Move forward** for **30 seconds**.
2. **Move backward** for **60 seconds**.
3. **Alternate turning right and left** every **30 seconds** for **1 minute**.
4. **Stop all motors** after completing the sequence.

The entire movement is controlled using **timers (millis function)** instead of `delay()` to ensure smooth transitions.


---

## 🎯 **Project Objectives**
- Understand how to control **multiple DC motors** using **L293D motor drivers**.
- Implement **timing-based motor control** without blocking program execution.
- Utilize **PWM (Pulse Width Modulation)** to control motor speed.
- Learn **circuit connections** using **Arduino Uno** and a **breadboard**.

---

## 🔧 **Components Required**
| Quantity | Component |
|----------|------------|
| 1 | Arduino Uno |
| 4 | DC Motors |
| 2 | L293D Motor Drivers |
| 1 | Breadboard |
| 1 | 9V Battery |
| 1 | Battery Snap Connector |
| 10+ | Jumper Wires |

---


## 🏗 **Circuit Diagram**
Below is the **wiring setup** for the project:

![Image Description](4%20DC%20Motor%20Control%20with%20L293D%20Motor%20Driver.png)





### **📝 Wiring Details**
Each **L293D driver** controls **two motors**:
- **Enable Pins**: Connected to PWM pins on Arduino for speed control.
- **Input Pins (IN1 - IN4, IN5 - IN8)**: Control direction of rotation.
- **9V Power Supply**: Provides sufficient power to the motors.

---

## 🖥 **Arduino Code**
The project is programmed using Arduino, and the full code is provided in [📜 View the Arduino Code](4_dc_motor_control_with_l293d_motor_driver1.ino)



### **📜 Code Explanation**
1. **Pin Setup**: Defines motor driver pins for Arduino.
2. **Motor Functions**:
   - `moveForward()`
   - `moveBackward()`
   - `moveRight()`
   - `moveLeft()`
   - `stopMotors()`
3. **Timing Logic**: Uses `millis()` to manage motor transitions without blocking execution.
4. **Loop Execution**: Executes movement in the predefined order.

---

## 🚀 **How to Use**
1. **Assemble the circuit** as per the diagram.
2. **Connect the Arduino Uno** to your PC and upload the code.
3. **Power the setup** using a **9V battery** or an **external power supply**.
4. **Observe the motors executing movements** in the specified sequence.

---

## 🎥 **Expected Output**
- Motors move **forward** for **30 seconds**.
- Motors move **backward** for **60 seconds**.
- Motors turn **right for 30 seconds**, then **left for 30 seconds** (total **1 minute**).
- Motors **stop** after completing the sequence.

---

## 🛠 **Modifications & Enhancements**
Want to improve the project? Here are some ideas:
- **Speed Control**: Modify PWM values (`analogWrite()`) to adjust motor speed dynamically.
- **Obstacle Detection**: Integrate **ultrasonic sensors** to avoid collisions.
- **Bluetooth/WiFi Control**: Add an **HC-05 Bluetooth module** or an **ESP8266** to control motors wirelessly.
- **Remote Control**: Use a **joystick module** or **IR remote** to manually control the motors.

---

