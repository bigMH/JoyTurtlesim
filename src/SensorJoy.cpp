#include "SensorJoy.h"

SJ::SensorJoy::SensorJoy(ros::NodeHandle& yn) {

	/*Get the parameters from parameter master.*/
	yn.getParamCached("forward_button", forward_button_);
	yn.getParamCached("angular_button", angular_button_);
	yn.getParamCached("control_button", control_button_);
	yn.getParamCached("mult_speed_button", mult_speed_button_);
	
	/*Get the topic_name from parameter master.*/
	yn.getParamCached("pub_topic_", pub_topic_);
	yn.getParamCached("sub_topic_", sub_topic_);

	/*Initialize the publisher and subscriber.*/
	pub = yn.advertise<geometry_msgs::Twist>(pub_topic_, 1);

	sub = yn.subscribe<sensor_msgs::Joy>(sub_topic_, 10, &SJ::SensorJoy::JoyCallback, this);
}

SJ::SensorJoy::~SensorJoy() {

}

void SJ::SensorJoy::JoyCallback(const sensor_msgs::Joy::ConstPtr& joy) {

	geometry_msgs::Twist tur_twist;
	/*When the control_button is on ,you can manipulate the joystick*/
	if(joy->buttons[control_button_] == true) {
		/*When muli_speed_button is true, speed double*/
		if (joy->buttons[mult_speed_button_] == true) {

			tur_twist.angular.z = 2 * joy->axes[angular_button_];
			tur_twist.linear.x = 2 * joy->axes[forward_button_];
		}
		else {

			tur_twist.angular.z = joy->axes[angular_button_];
			tur_twist.linear.x = joy->axes[forward_button_];
		}
		pub.publish(tur_twist);
	}

	/*warning:manipulate joystick without control button. */
	if (joy->buttons[control_button_]==0 && joy->axes[angular_button_]!=0)
	{
		ROS_INFO("You can't manipulate the joystick without enter the control_button.");
	}
}