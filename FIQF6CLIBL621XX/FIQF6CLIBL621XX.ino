

#include <Wire.h>
#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle nh;

int LED = 8;
int x = 0;

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


ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageLED);

void setup() 
{
  Wire.begin(); 
  Serial.begin(57600);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() 
{
  Wire.beginTransmission(9); 
  Wire.write(x);             
  Wire.endTransmission();    
 
  nh.spinOnce();
  delay(50);
}

