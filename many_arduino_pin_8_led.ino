/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

#include <ros.h>
#include <std_msgs/Empty.h>
// we need to include ros.h as with any other ROS Arduino program
// we also include the header files for messages, in this case, the Empty message.

ros::NodeHandle nh;
// we need to instantiate the node handle, which allows our program to create prublishers and subscribers.
// the node handle also takes care of serial port communications

void messageCb8( const std_msgs::Empty& toggle_8){
  digitalWrite(8, HIGH-digitalRead(8));
}
// we then create the callback function for our subscriber, in this case would be called toggle_8



/*
void messageCb2( const std_msgs::Empty& toggle_2){
  digitalWrite(2, HIGH-digitalRead(2));
}
void messageCb3( const std_msgs::Empty& toggle_3){
  digitalWrite(3, HIGH-digitalRead(3));
}
void messageCb4( const std_msgs::Empty& toggle_4){
  digitalWrite(4, HIGH-digitalRead(4));
}
void messageCb_b( const std_msgs::Empty& toggle_b){
  digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));
}
*/


ros::Subscriber<std_msgs::Empty> sub("toggle_8", &messageCb8);
// we need to instantiate the publisher and subscribers that we will be using.
// here we instantiate a subscriber with a topic name of "toggle_8"

/*
ros::Subscriber<std_msgs::Empty> sub1("toggle_2", &messageCb2);
ros::Subscriber<std_msgs::Empty> sub2("toggle_3", &messageCb3);
ros::Subscriber<std_msgs::Empty> sub3("toggle_4", &messageCb4);
ros::Subscriber<std_msgs::Empty> sub_b("toggle_b", &messageCb_b);
*/

// the setup function runs once when you press reset or power the board

void setup() {
  Serial.begin(57600);
  pinMode(8, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
  // in the arduino setup function you need to initialize your ROS node handle, advertise any topics being published
  // and subscribe any topics you wish to listen to
  
  
  /*
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  nh.subscribe(sub3);
  nh.subscribe(sub_b);
  */
}

// the loop function runs over and over again forever
void loop() {
  nh.spinOnce();
  delay(1);
  // finally, in the loop function we call ros::spinOnce() aka nh.spinOnce where all of the ROS communication callbacks are handled.
  // we dont need to do any additional processing in the loop(), since spinOnce(() will handle passing messages to the subscriber callback
}
