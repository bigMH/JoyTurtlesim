#include"SensorJoy.h"
#include"ros/ros.h"

int main(int argc,char** argv)
{
	ros::init(argc,argv,"Joy_turtle");
	ros::NodeHandle n;
	
	SJ::SensorJoy joy_turtle (n);
	
	ROS_INFO("Let's paly a game!");
	ROS_INFO("Please enter the 'Y' button and then you can manipulate the joystick.");
	ros::spin();
	return 0;
}