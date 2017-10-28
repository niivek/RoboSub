// Chapter 7 - Communications
// I2C Master
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C


#include <Wire.h>
#include <ros.h>
#include <std_msgs/Empty.h>
// required ros headers

ros::NodeHandle nh;
// initialize ros NodeHandle

int LED = 8;
int x = 0;
// sets x variable to 0

void messageLED( const std_msgs::Empty& toggle_led)
{
  if (x == 0)
  {
    x = 1;
  }
  else
  {
    x = 0;
  }
}
// method that runs each time ros subscriber is called
// changes x value to 1 if 0
// changes x value to 0 if 1


ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageLED);
// initialize the ros subscriber that takes in Empty

void setup() 
{
  // Start the I2C Bus as Master
  Wire.begin(); 
  Serial.begin(57600);
  nh.initNode();
  nh.subscribe(sub);
  // calls ros NodeHandle
  // and subscribes to sub message
}

void loop() 
{
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
 
//  x++; // Increment x
//  if (x > 5) x = 0; // `reset x once it gets 6

  nh.spinOnce();
  delay(50);
}

