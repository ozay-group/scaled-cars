#define CPS2V 0.004653//countPerSecond to velocity
#define MAXCURRENT 0.25
#define SERVOMID 1537
#define SERVOMAXAMP 200 //Maximal servo amplitude
#define CARID 2

#include <iostream>
#include "ros/ros.h"
#include <rctestpkg/LKdata.h>
#include <rctestpkg/Motor_data.h>
#include <rctestpkg/CarState.h>

class car_state {
private:
	rctestpkg::CarState state_msg;
public: 
	void set_lk_data(const rctestpkg::LKdata::ConstPtr& msg);
	void set_motor_data(const rctestpkg::Motor_data::ConstPtr& msg);
	rctestpkg::CarState get_state_msg() { return state_msg; }
};

void car_state::set_lk_data(const rctestpkg::LKdata::ConstPtr& msg) {
	state_msg.y = msg->y;		// Lateral position
	state_msg.v = msg->vl;		// Lateral velocity
	state_msg.psi = msg->psi;	// Yaw
	state_msg.r = msg->r;		// Yaw rate
	state_msg.rd = msg->rd;		// Road disturbance
	// Setting all constants not important for lanekeeping to 0 (for now);
	state_msg.time = 0;
	state_msg.x_global = 0;
	state_msg.y_global = 0;
	state_msg.yaw_global = 0;
	state_msg.h = 0;
}

void car_state::set_motor_data(const rctestpkg::Motor_data::ConstPtr& msg) {
	state_msg.u = msg->countPerSecond*CPS2V;
}

car_state cs;

void motor_callback(const rctestpkg::Motor_data::ConstPtr& msg) {
	std::cout << "motor_callback\n";
	cs.set_motor_data(msg);
}

void LK_callback(const rctestpkg::LKdata::ConstPtr& msg) {
	std::cout << "LK_callback " << "\n";
	cs.set_lk_data(msg);
}

int main(int argc, char ** argv) {
	ros::init(argc, argv, "CarStatePublisher");
	ros::NodeHandle n;
	ros::Publisher state_pub = n.advertise<rctestpkg::CarState>("car_state", 10);
	ros::Subscriber motor_sub = n.subscribe("Motor_data2", 10, motor_callback);
	ros::Subscriber lk_sub = n.subscribe("lk_data", 10, LK_callback);
	ros::Rate loop_rate(50);
	ros::spinOnce();
	while(ros::ok()) {
		std::cout << "In main loop\n";
		state_pub.publish(cs.get_state_msg());
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
	
