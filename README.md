# Plane Stabilization Rig
A flight stabilization test rig utilizing an Arduino UNO, an MPU-6050 and two SG90 digital servos.
It is a systems project designed to simulate the working of ailerons on an aircraft. 

## Materials used:
As the micro-controller, I used an Arduino UNO. As the accelerometer, an MPU-6050, and the ailerons are controlled by the movement of two counteractive SG90 servos. As the power source for the servos, I used a 2A power bank which was hooked up to the breadboard via a spliced USB power breakout.

## Working of the setup:
The MPU-6050 uses the accelerometer to control the servos. Basically, if the setup tilts towards the right, the MPU-6050 detects the change in the roll accelerometer values, and the micro-controller then maps these values to servo angles, which are then written to the respective servo. For the other servo's angle, I simply subtract the first servo's angle from 180, and this simulates a counter-steering effect. Through this, ailerons on an aircraft are successfully simulated. 

## Limitations, Tweaks in V2 and Possible Solutions:
I initially wanted to incorporate a working PID loop, by utilizing the gyroscope on the MPU-6050, to ensure smooth mapping of the servos. Once I finally got the logic down and started testing my code, I found some unusual results. The servos kept jittering, and when I looked deeper into the actual values coming from the MPU, I came to the conclusion that my chip had a defect. I constantly faced initialization drifts, or at least that was the best explanation for this erratic behavior. Hence, I had to shift to the accelerometer roll values to map the servo angles. The major problem with this approach is that the accelerometer reads values based on the gravity, and those raw values aren't that dependable. There is a little jitter and I couldn't find a solution for this, except for using better hardware.

My initial design needed two servos to show the functioning of the ailerons. But, due to a cascading failure in my robotic arm project, I lost two out of three of my available servos. I couldn't buy a new servo because I had gone well over my 3,000 rupee budget, and the hike in the prices of electronics in the closest hobby market, I had to think of a more robust solution for the demonstration. After researching some designs of a few aircrafts, I decided on the design of fighter jets. In a standard aircraft, the ailerons are situated far apart. But in a fighter jet, the ailerons are closer to each other. So, by changing the design of the aircraft to one similar to an F-20 Raptor, the horn of the servo, and two aluminum wires, I successfully simulated the same effect as two servos with one. 


[(Click here to go back to main repository)](https://github.com/aarizMohammad-9129/MIT-Maker-Portfolio_Mohammad-Aariz/blob/main/README.md)
