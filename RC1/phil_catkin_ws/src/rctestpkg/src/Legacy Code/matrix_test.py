#!/usr/bin/env python

import rospy
from std_msgs.msg import String, UInt16, Float32, Float64
from rctestpkg.msg import Motor_data, IMUdata, CarState
from rctestpkg.srv import MPC_LK, MPC_CC
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3
from sensor_msgs.msg import LaserScan

from scipy.integrate import ode
import numpy as np
import math
import matplotlib.pyplot as plt
from getLatDynMat import *

def CarState_callback(data):
    global X, Y, yaw, h, vl, u, y, v, psi, r, rd
    X = data.x_global
    Y = data.y_global
    yaw = data.yaw_global
    h = data.h
    vl = data.vl
    u = data.u
    y = data.y
    v = data.v
    psi = data.psi
    r = data.r
    rd = data.rd

def Control_callback(data):
    global manual_steer, right_lane, manual_v, stop, command_v
    manual_steer = data.manual_steer
    right_lane = data.right_lane
    manual_v = data.manual_v
    stop = data.stop
    command_v = data.command_v

X = 0.0 # Global X
Y = 0.0 # Global Y
yaw = 0.0 # Global yaw
h = 8.0
vl = 0.0
u = 0.0
y = 0.0
v = 0.0
psi = 0.0
r = 0.0
rd = 0.0
prev_i = 0.0
prev_s = 0.0
servoRatio = 8.9479e-04
SERVOMID = 1537
LANEWIDTH = 0.6
VMAX = 0.5

manual_steer = True
right_lane = True
manual_v = True
stop = False
command_v = 0.0

rospy.init_node('matrix_test')
servo_pub = rospy.Publisher("servo", UInt16, queue_size=10)
motor_pub = rospy.Publisher("Motor_command2", Float32, queue_size=10)

rospy.Subscriber("car_state", CarState, CarState_callback)

print "Servo ratio: ", servoRatio

servoMsg = UInt16()
servoMsg.data = SERVOMID
rate = rospy.Rate(1.0)

while not rospy.is_shutdown():
	rate.sleep()
	u_current = 0.5
	A,B,E = getLatDynMat(u_current)
	print A
	print B
	print E
