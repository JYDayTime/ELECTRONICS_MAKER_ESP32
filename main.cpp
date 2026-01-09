#include <Arduino.h>
#include <ESP32Servo.h>

//Input servo pins here for each finger
//static const int servoFinger1 = 15;
//static const int servoFinger2 = 2;
#define servoFinger1 15
#define servoFinger2 2
#define servoFinger3 14
#define servoFinger4 18
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int res = -99;

void setup() {
  //Set baud rate and ensure 1 second of wait time
  Serial.begin(115200);
  delay(1000);

  // ESP32 PWM module must allocate timer
  //ESP32PWM::allocateTimer(0);

  //Assign Servos to setup
  servo1.attach(servoFinger1);
  servo2.attach(servoFinger2);
  servo3.attach(servoFinger3);
  servo4.attach(servoFinger4);

}

void loop() {

  Serial.println("Finger movement begins");

  // Start moving fingers one at a time
  servo1.write(0);
  delay(1000);
  servo2.write(0);
  delay(1000);
  servo3.write(0);
  delay(1000);
  servo4.write(0);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo2.write(90);
  delay(100);
  servo3.write(90);
  delay(1000);
  servo4.write(90);
  delay(1000);
  servo1.write(0);
  delay(1000);
  servo2.write(0);
  delay(1000);
  servo3.write(0);
  delay(1000);
  servo4.write(0);
  Serial.println("Code Complete.");
  delay(10000);
}