# Sumo Robot Competition - BatmanAmman

## Overview

Welcome to the repository for the BatmanAmman Sumo Robot, a project designed for a sumo robot competition. Our team engineered a robot that could compete in sumo  matches by detecting opponents and making strategic moves.

## Project Details

### Team Name
**BatmanAmman**

### Design and Components

- **3D Modeling**: Designed using Fusion 360
- **Main Controller**: Raspberry Pi 5 Model B (initially planned)
- **Programming Languages**: Python (initially), Arduino C++ (final implementation)
- **Computer Vision**: Custom model for opponent detection (planned, but not completed)
- **Motor and Wheels**: JSumo Titan 200 RPM with rubber wheels
- **Sensors**: 
  - 6 IR sensors SUMO JS200XF INFRARED LONG RANGE SENSOR
  - 4 QTR sensors for edge detection
  - RASPBERRY PI CAMERA MODULE 3 NOIR - WIDE ANGLE
- **Motor Drivers**: 2 Dual H-Bridge drivers
- **Microcontroller**: Arduino Mega
- **Switches**: 4 Postion DIP Switch
- **Batteries**:
  - 3000 mAh LiPo Battery
  - 9V LiPo Battery

### Project Timeline and Changes

1. **Initial Setup**:
   - We started with a Raspberry Pi 5 Model B and programmed our robot using Python.
   - A computer vision model was being developed to enhance attack accuracy.

2. **Challenges**:
   - The Coral TPU, essential for our computer vision model, did not arrive on time.
   - Due to this, we switched to Arduino for the final implementation.

3. **Final Setup**:
   - We implemented the robot using Arduino Mega with 2 Dual H-Bridge drivers.
   - Completed the code using Arduino C++.

4. **Future Plans**:
   - Reinforcement learning was planned to be integrated but was not completed due to the delayed arrival of the TPU and time constraints.

## Design Showcase

![Sumo Robot Prototype](images/prototype.jpg)  


## Installation and Usage

### Hardware Setup

1. **Assemble the robot** using the designed parts and sensors.
2. **Connect the components** according to the wiring diagrams provided in the hardware files.
3. **Install the batteries**:
   - Connect the 3000 mAh LiPo battery for powering the motors.
   - Connect the 9V LiPo battery for powering the Arduino.

### Software Setup

1. **Arduino Code**:
   - Upload the code to the Arduino Mega using the Arduino IDE. The code can be found in the `arduino` directory.

2. **Python Code** (planned):
   - The Python code for reinforcement learning and advanced features is under development .


## Contact

For questions or further information, please reach out to us at [hasweh03@gmail.com].
