//The following code is for a plane stablising rig as part of my MIT Maker's Protfolio 

#include <Wire.h> 
#include <Servo.h>

const int mpu = 0x68;
Servo servoA;
Servo servoB;

int16_t AccX, AccY, AccZ;

void setup() {
  Wire.begin();
  Wire.beginTransmission(mpu);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  Serial.begin(9600);
  servoA.attach(9);
  servoB.attach(10);
  servoA.write(90); // start at center position
  servoB.write(90);
}

void loop() {
  Wire.beginTransmission(mpu);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(mpu, 6, true);

  AccX = Wire.read() << 8 | Wire.read();
  AccY = Wire.read() << 8 | Wire.read();
  AccZ = Wire.read() << 8 | Wire.read();

  int angleA = map(AccX, -15000, 15000, 0, 180);  //Maps the value obtained form accelerometer to the servo 
  int angleB = 180-angleA;
  
  angleA = constrain(angleA, 0, 180);
  angleB = constrain(angleB, 0, 180)

  servoA.write(angleA);
  servoB.write(angleB);
  
  Serial.print("MPU Value: "); Serial.print(AccX);
  Serial.print("   Servo Angle A: "); Serial.println(angleA);  //for debugging purposes
  Serial.print("   Servo Angle B: "); Serial.println(angleB);

  delay(50);
}
