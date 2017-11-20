// Chapter 7 - Communications
// I2C Slave
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C
#include <Wire.h>
#include <Servo.h>


Servo myservo;

int servo_ad = 9;
int LED = 8;
int x = 0;
int pos = 0;

void setup() {
  Wire.begin(9); 
  Wire.onReceive(receiveEvent);
  myservo.attach(servo_ad); 
  pinMode(LED, OUTPUT);
}

void receiveEvent(int bytes) {
  x = Wire.read();
  pos = x;
}

void loop() {
//  if (x != 0) 
//  {
//    digitalWrite(LED, HIGH);
//  }
//  else
//  {
//    digitalWrite(LED, LOW);
//  }

//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//  // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(10);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(10);                       // waits 15ms for the servo to reach the position
//  }
   delay(50);
}

