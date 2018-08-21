#include <iostream>
#include <ros/ros.h>
#include <std_msgs/Float32.h>		// Motor command
#include <std_msgs/Float64.h>		
#include <std_msgs/UInt16.h>		// Servo command
#include <rctestpkg/Motor_data.h>	// Data from the motor
#include <rctestpkg/MPC_LK.h>		// Lanekeeping service
#include <rctestpkg/CarState.h>		// Car state information

#define SERVO_RATIO 0.00089479
#define SERVO_MID 1537
#define LANEWIDTH 0.3
#define VMAX 0.5

void car_state_callback(const rctestpkg::CarState::ConstPtr & msg) {
}

int main(int argc, char ** argv) {
	ros::init(argc, argv, "central_control2");
	ros::NodeHandle n;
	ros::Publisher motor_pub = n.advertise<std_msgs::Float32>("Motor_command2", 10);
	ros::Publisher servo_pub = n.advertise<std_msgs::UInt16>("servo", 10);
	ros::Subscriber motor_sub = n.subscribe("car_state", 1, car_state_callback);
	ros::ServiceClient lk_client = n.serviceClient<rctestpkg::MPC_LK>("MPC_LK2");
	std::cout << "Servo ratio: " << SERVO_RATIO << std::endl;
	ros::Rate loop_rate(10);
	while (ros::ok()) {
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}