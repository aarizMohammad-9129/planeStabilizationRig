# Plane Stabilization Rig
A flight stabilization test rig utilizing an Arduino UNO, an MPU-6050 and two SG90 digital servo.
It is a systems project designed to simulate the working of ailerons on an aircraft. 

## Materials used:
As the micro-controller, I used an Arduino UNO. As the accelerometer, an MPU-6050, and the ailerons are controlled by the movement of two counteractive SG90 servos. As the power source for the servos, I used a 2A power bank which was hooked up to the breadboard via a spliced USB power breakout.

## Notable Details:
I originally intended to use a PID control algorithm with error handling to control the actuation. But, due to the gyroscope not giving proper readings and constant initialization drift, I could not generalize a condition to control the servos. Hence, I had to shift to more robust approach which involved utilizing raw accelerometer values from the roll axis to control the servos. After I built my prototype, I moved on to another project, in which two out of three SG90 servos got damaged (refer robo arm git link insert here). Due to this, I had to modify my design to control two ailerons with one servo. After some testing, I realized I could repurpose the code intended for two servos. For my design, the code for 'servoB' (attached at pin 10) worked best. Since one SG90 servo pulls a max of 750mA for heavy loads, I deduced I could safely use the Arduino itself as my power source.    
