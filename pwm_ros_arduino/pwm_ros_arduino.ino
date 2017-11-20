#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
#include <Servo.h>

Servo myservo;

int pos = 0;

std_msgs::Float32 input_1;
std_msgs::Float32 input_2;

ros::NodeHandle nh;

void led_on(const std_msgs::Float32& input_1){
  if (input_1.data == 3)
  {
    digitalWrite(3, HIGH-digitalRead(3));
  }
  if (input_1.data == 4)
  {
    digitalWrite(4, HIGH-digitalRead(4));
  }
  if (input_1.data == 5)
  {
    digitalWrite(5, HIGH-digitalRead(5));
  }
  if (input_1.data == 6)
  {
    digitalWrite(6, HIGH-digitalRead(6));
  }
}

void led_on_2(const std_msgs::Float32& input_2){
  if (input_2.data == 3)
  {
    digitalWrite(3, HIGH-digitalRead(3));
  }
  if (input_2.data == 4)
  {
    digitalWrite(4, HIGH-digitalRead(4));
  }
  if (input_2.data == 5)
  {
    digitalWrite(5, HIGH-digitalRead(5));
  }
  if (input_2.data == 6)
  {
    digitalWrite(6, HIGH-digitalRead(6));
  }
}

ros::Subscriber<std_msgs::Float32> led_1("input_1", &led_on);
ros::Subscriber<std_msgs::Float32> led_2("input_2", &led_on_2);

char stringinput[100];

void setup() {
  // put your setup code here, to run once:


  nh.initNode();
  nh.subscribe(led_1);
  nh.subscribe(led_2);
  myservo.attach(9);
  myservo.attach(10);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
  delay(1);
}
