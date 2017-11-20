#include <Wire.h>
#include <Servo.h>
#include <ros.h>
#include <std_msgs/Float32.h>

ros::NodeHandle nh;
Servo myservo;

char buff[100];
int servo_ad = 4;
int x = 0;
int default_delay = 50;

void sub_led(const std_msgs::Float32& toggle_led){
//  digitalWrite(3, HIGH-digitalRead(3));
  dtostrf(toggle_led.data, 4, 6, buff);
  nh.loginfo(buff);
  x = toggle_led.data;
  nh.loginfo("Master print");
  
}

ros::Subscriber<std_msgs::Float32> turn_on("toggle_led", &sub_led);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(57600);
  nh.initNode();
  nh.subscribe(turn_on);

//  myservo.attach(servo_ad);
}

void loop() {
//  myservo.write(x);
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  nh.spinOnce();

  
//  delay(default_delay);
//  digitalWrite(4, HIGH-digitalRead(4));
//  delay(default_delay);
//  digitalWrite(4, HIGH-digitalRead(4));
  delay(50);
}


