#ifndef SENSORJOY_H
#define SENSORJOY_H

#include<string.h>

#include"ros/ros.h"
#include"sensor_msgs/Joy.h"
#include"geometry_msgs/Twist.h"

namespace SJ {

	class SensorJoy
	{
	private:
		int forward_button_,angular_button_,control_button_;  
		int mult_speed_button_;

		std::string pub_topic_,sub_topic_;

		ros::Publisher pub;
		ros::Subscriber sub;

	public:
		SensorJoy(ros::NodeHandle& yn);
		~SensorJoy();
		void JoyCallback(const sensor_msgs::Joy::ConstPtr& joy);
	};
}
#endif