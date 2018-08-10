/*
Phil Sisk
6/19/2018

motorCommand.cpp
basic code for reading in motor commands from the keyboard.
Based roughly on teleop_turtle_key.cpp, which defines the "teleop_turtle" ROS node:
http://docs.ros.org/groovy/api/turtlesim/html/teleop__turtle__key_8cpp_source.html
*/

#include "ros/ros.h"
#include <string>
#include <sstream>
#include <std_msgs/Float32.h>
#include <rctestpkg/Motor_data.h>	// Motor command
#include <std_msgs/UInt16.h>		// Servo command
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <termios.h>

// KEYCODE definitions
#define KEYCODE_R 0x43	// right arrow
#define KEYCODE_L 0x44	// left arrow
#define KEYCODE_U 0x41	// up arrow
#define KEYCODE_D 0x42	// down arrow
#define KEYCODE_Q 0x71	// 'Q' key

#define CURRENT		4.0	// Current constant (4.0 AMPS)
#define STRAIGHT_PWM	1537 	// Number of microseconds per pulse for straight wheels
#define MAX_PWM 	1837
#define MIN_PWM		1237

// class TeleopCar - defines functions for controlling car via keyboard
class TeleopCar {
private:
	// Private member variables+
	int kfd; // File descriptor for keyboard input, is equal to stdin = 0
	const float FWD_CURRENT, RVS_CURRENT;
	struct termios oldt, newt;
	ros::NodeHandle n;
	ros::Publisher command_pub;
	ros::Publisher servo_pub;
	std_msgs::Float32 motor_cmd_msg;
	std_msgs::UInt16 servo_cmd_msg;
	ros::Rate loop_rate; // Loops at 10 Hz (this isn't currently used)


	// Private member functions
	void send_forward_cmd();
	void send_reverse_cmd();
	void send_stop_cmd();
	void send_left_cmd();
	void send_straight_cmd();
	void send_right_cmd();

	
public:
	// Constructor
	TeleopCar() :	kfd(STDIN_FILENO),		// fd for the keyboard (STDIN_FILENO = 0)
			FWD_CURRENT(CURRENT),		// 3.0 AMPS
			RVS_CURRENT(-CURRENT),		// -3.0 AMPS
			loop_rate(20)			// loop at 20 Hz
	{
		// Update keyboard input settings
		tcgetattr(kfd, &oldt);			// Save old input mode for resetting input
		newt = oldt;				// Begin with old input settings
		newt.c_lflag &=~ (ICANON | ECHO);	// Turn off canonical buffering/echoing
		newt.c_cc[VMIN] = 0;			// No min number of read bytes needed
		newt.c_cc[VTIME] = 0;			// don't wait before returning from read
		tcsetattr(kfd, TCSANOW, &newt);		// Apply new attributes

		// ROS setup
		command_pub = n.advertise<std_msgs::Float32>("Motor_command2", 1);
		servo_pub = n.advertise<std_msgs::UInt16>("servo", 1);
		servo_cmd_msg.data = 1537;

	}
	// Destructor
	~TeleopCar() {
		// Stop the car if it is still going
		send_stop_cmd();
		servo_cmd_msg.data = STRAIGHT_PWM;
		servo_pub.publish(servo_cmd_msg);
		// Reset input mode (otherwise wonky terminal behavior occurs)
		tcsetattr(kfd, TCSANOW, &oldt);
	}
	void keyLoop();
	
}; // class TeleopCar

// Keyboard input loop
void TeleopCar::keyLoop() {
	char c, dummy;
	int count = 0;	// Keeps track of successive inputs to avoid jerky control
	bool forward = 0, reverse = 0, left = 0, right = 0;
	std::cout << "Use the arrow keys to control the car or use Cntl-C to quit.\n";
	while (ros::ok()) {
		// Reads one character from the input
		if (!(read(kfd, &c, 1) > 0)) { 
			send_stop_cmd();
			send_straight_cmd();
			std::cout << "\33[2K\rStop" << std::flush;
			forward = reverse = false;
			left = right = false;
			count = 0;
			loop_rate.sleep();
			continue;
		}
		
		/* A single press of an arrow key sends three characters
		to the buffer - '\027', '\091', and one of the keycodes defined
		at the beginning of this file. These if statements detect that
		pattern
		*/
		// Looking for an arrow key
		if (c == 27) { // esc character
			read(kfd, &c, 1);
			if (c == 91) { // '[' character
				read(kfd, &c, 1);
			}
		}


		// Parse keyboard input
		switch(c) {

		case KEYCODE_L:
			left = true;
			send_left_cmd();
			send_forward_cmd();
			std::cout << "\33[2K\rLeft" << std::flush;
			break;
		case KEYCODE_R:
			right = true;
			send_right_cmd();
			send_forward_cmd();
			std::cout << "\33[2K\rRight" << std::flush;
			break;
		case KEYCODE_U:	// Up arrow pressed
			if (reverse) {
				reverse = false;
				count = 0;
			}
			forward = true;
			if (count > 0) {
				send_forward_cmd();
				send_straight_cmd();
				std::cout << "\33[2K\rForward" << std::flush;

			}
			else { 
				++count;
				send_stop_cmd();
			}
			break;
		case KEYCODE_D: // Down arrow pressed
			if (forward) {
				forward = false;
				count = 0;
			}
			reverse = true;
			if (count > 0) {
				send_reverse_cmd();
				send_straight_cmd();
				std::cout << "\33[2K\rReverse" << std::flush;

			}
			else { 
				++count;
				send_stop_cmd();
			}
			break;
		default: // send stop command if anything else is pressed
			send_stop_cmd();
			send_straight_cmd();
			std::cout << "\33[2K\rStop" << std::flush;
			forward = reverse = false;
			left = right = false;
		} // switch(c)

		tcflush(kfd, TCIFLUSH);

		// Spin for callback functions
		ros::spinOnce();
		loop_rate.sleep();
	} // while(ros::ok())
}

// Publish forward command to Motor command ROS topic
void TeleopCar::send_forward_cmd() {
	motor_cmd_msg.data = FWD_CURRENT;
	command_pub.publish(motor_cmd_msg);
}

// Publish reverse command to Motor command ROS topic
void TeleopCar::send_reverse_cmd() {
	motor_cmd_msg.data = RVS_CURRENT;
	command_pub.publish(motor_cmd_msg);
}

// Publish stop command to Motor command ROS topic
void TeleopCar::send_stop_cmd() {
	motor_cmd_msg.data = 0.0;
	command_pub.publish(motor_cmd_msg);
}

void TeleopCar::send_left_cmd() {
	if (servo_cmd_msg.data > MIN_PWM) {
		servo_cmd_msg.data -= 20;
	}
	servo_pub.publish(servo_cmd_msg);
}

void TeleopCar::send_right_cmd() {
	if (servo_cmd_msg.data < MAX_PWM) {
		servo_cmd_msg.data += 20;
	}
	servo_pub.publish(servo_cmd_msg);
}

void TeleopCar::send_straight_cmd() {
	if (servo_cmd_msg.data > STRAIGHT_PWM) {
		servo_cmd_msg.data -= 20;
	}
	else if (servo_cmd_msg.data < STRAIGHT_PWM) {
		servo_cmd_msg.data += 20;
	}
	servo_pub.publish(servo_cmd_msg);
}


int main(int argc, char **argv) {
	ros::init(argc, argv, "motorCommand");
	TeleopCar tc;
	tc.keyLoop();
	return 0;
}
