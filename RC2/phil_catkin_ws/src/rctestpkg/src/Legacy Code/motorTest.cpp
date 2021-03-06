/*
motorTest.cpp
motor_control ROS node definition
Phil Sisk
6/15/2018
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <unistd.h>			// Standard UNIX functions
#include "rs232.h"			// Defines r232 interface
#include "ros/ros.h"			// ROS functionality
#include <rctestpkg/Motor_data.h>	// Motor data ROS message (publication)
//#include <um_acc/Lidar_data.h>		// Lidar data ROS message (subscription)
#include <std_msgs/Float32.h>		// motor command ROS message (subscription)

#define DELAY 10000		// # of microseconds between motor commands

// Initialize motor data message to all zeros
// Due to the way that callback functions work, this argument must be global
// at the moment. I am looking into how to pass multiple arguments to a
// callback function.
rctestpkg::Motor_data msg;
char currentStr[50] = "TC=0.0\r";


/*
class motor_communicator
Defines constants and input/output functions for communicating
with the ELMO motor
*/
class motor_communicator {
private:
	std::stringstream ss;
	unsigned char buf[128];
	const int CPORT_NR;		// /dev/ELMO, defined in rs232.cpp
	const int BDRATE;		// baud rate
	const std::string MODE;
public:
	// Constructor
	motor_communicator() : ss(""), CPORT_NR(0), BDRATE(115200), MODE("8N1") {
		ss << std::setprecision(3) << std::fixed;		
	}

	// Open communications with the motor and set the mode
	bool setup() {
		// Open communications with the motor
		if(RS232_OpenComport(CPORT_NR, BDRATE, MODE.c_str())) {
			std::cout << "Can not open comport\n";
			return false;
		}
		else {
			std::cout << "comport open\n";
		}

		// Enable the motor
		std::string str = "MO=1\r";
		send_msg(str.c_str());
		RS232_PollComport(CPORT_NR, buf, 127);
		usleep(DELAY);

		// Set the mode to current control
		str = "UM=1\r";
		send_msg(str.c_str());
		RS232_PollComport(CPORT_NR, buf, 127);
		return true;
	}

	// Send message to the motor
	void send_msg(const char * str) {
		//std::cout << "STRING: " << str << std::endl;
		RS232_cputs(CPORT_NR, str);
	}

	// Read velocity, position, and current data from the motor	
	bool read_data(rctestpkg::Motor_data & md_msg) {
		std::string junk;
		int n = RS232_PollComport(CPORT_NR, buf, 127);
		if(n > 0) {
			buf[n-1]='\0';
			buf[2]=' ';
			ss << buf;
			std::cout << "Stringstream: " << ss.str() << std::endl;
			switch (buf[0]){
				case 'V':  ss >> junk >> md_msg.countPerSecond;
				md_msg.countPerSecond *= -1;
				break;

				case 'P':  ss >> junk >> md_msg.position;
				md_msg.position *= -1;
				break;

				case 'I':  ss >> junk >> md_msg.current;
				md_msg.current *= -1;
				break;

				default: break;
			}
			ss.clear();
		       	ss.str("");
			return false; // NotUpdated = false;
		}
		else{
			std::cout << "Not received\n";
			return true;  // NotUpdated = true;
		}
	}
};
	

/**********************************************************************/
/** Callback function definitions (functions used by ROS subscribers) */
void motorCallback(const std_msgs::Float32::ConstPtr& Rmsg)
{
	sprintf(currentStr, "TC=%0.3lf\r", -Rmsg->data);
	std::cout << currentStr << std::endl;
}

/* TODO: add new parameter for motor data message to this function
void lidarCallback(const um_acc::Lidar_data::ConstPtr& Rmsg)
{
	msg.h = Rmsg->h;
	msg.hdot = Rmsg->hdot;
}
/**********************************************************************/



int main(int argc, char **argv) {
	msg.position = 0;
	msg.countPerSecond = 0;
	msg.current = 0;
	msg.h = 0;
	msg.hdot = 0;
	// Initialize motor node, handle, publisher and subscribers
	ros::init(argc, argv, "motor2");
	ros::NodeHandle nh;
	ros::Publisher motor_pub = nh.advertise<rctestpkg::Motor_data>("Motor_data2", 1000);
	ros::Subscriber motor_sub = nh.subscribe("Motor_command2", 1, motorCallback);
//	ros::Subscriber lidar_sub = nh.subscribe("Lidar_data2", 1, lidarCallback);
	
	// Loop at 80 Hz
	ros::Rate loop_rate(80);

	std::cout << "start\n";
	
	motor_communicator mc;
	if (!mc.setup()) return 1;
	usleep(DELAY);
	
	// Gets the maximum current allowed by the motor
	std::string str1 = "MC\r";
	mc.send_msg(str1.c_str());
	mc.read_data(msg);
	loop_rate.sleep();

	
	// Main ROS loop
	while(ros::ok()){
		// Send current command
		mc.send_msg(currentStr);
		mc.read_data(msg);
		loop_rate.sleep();
		
		/*Position*/
		std::string str = "PX\r";
		mc.send_msg(str.c_str());
		mc.read_data(msg);
		loop_rate.sleep();

		/*velocity*/
		str = "VX\r";
		mc.send_msg(str.c_str());
		mc.read_data(msg);
		loop_rate.sleep();	

		/*Current*/
		str = "IQ\r";
		mc.send_msg(str.c_str());
		mc.read_data(msg);
		loop_rate.sleep();

		/*Publish data*/
    		motor_pub.publish(msg);
		
		// Current gets updated	
		ros::spinOnce();
	}

	return 0;
}
