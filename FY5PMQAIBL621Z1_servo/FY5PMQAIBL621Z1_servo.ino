// Chapter 7 - Communications
// I2C Slave
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C
#include <Wire.h>
#include <Servo.h>


Servo myservo;

int servo_ad = 7;
int LED = 8;
int x = 0;
int y = 0;

void setup() {
  
  Wire.begin(9); 
  Wire.onReceive(receiveEvent);
  myservo.attach(servo_ad); 
  pinMode(LED, OUTPUT);
}

void receiveEvent(int bytes) {
  x = Wire.read();
  y = Wire.read();
}

void loop() {
  myservo.write(y); 
  if (x != 0) 
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
   delay(50);
}

