// Chapter 7 - Communications
// I2C Master
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C


#include <Wire.h>
#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Float32.h>

ros::NodeHandle nh;

int pos = 0;
int LED = 8;
char buff[100];

std_msgs::Float32 input_1;


int x = 0;

byte userinput[] = {0,0}; 


void servo_cont(const std_msgs::Float32& servo_input)
{
  nh.loginfo("testing servo");
  dtostrf(servo_input.data, 4, 6, buff);
  nh.loginfo(buff);
  userinput[1] = (int)servo_input.data;
}


ros::Subscriber<std_msgs::Float32> servo("servo_input", &servo_cont);
// initialize the ros subscriber that takes in Empty

void messageLED( const std_msgs::Empty& toggle_led)
{
  nh.loginfo("testing led");
  if (userinput[0] == 0)
  {
    userinput[0] = 1;
  }
  else
  {
    userinput[0] = 0;
  }
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &messageLED);

void setup() 
{
  // Start the I2C Bus as Master
  Wire.begin(); 
  Serial.begin(57600);
  nh.initNode();
  nh.subscribe(servo);
  nh.subscribe(sub);
  // calls ros NodeHandle
  // and subscribes to sub message
}

void loop() 
{
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(userinput[0]);
  Wire.write(userinput[1]); 
  Wire.endTransmission();    // stop transmitting

  nh.spinOnce();
  delay(1);
}

