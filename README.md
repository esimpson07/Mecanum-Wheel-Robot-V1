November 2021

This is my Mecanum Wheel Robot code & live video

- The robot has a Jetson Nano and Arduino, and uses OpenCV to detect people.

- Using serial communication between the Jetson and the Arduino to see how far off center the person is, and then serial print it to the Arduino
which changes the motor speed and then changes the left and right speeds accordingly.

- On the Jetson Nano, OpenCV is running on python and is using the Coco 2018 dataset to detect any people, and it takes the outer edges and 
averages them to find the center point.

- On the Arduino, the Serial Monitor is being listened to and the motors are being driven, and the x from center is subtracted from one side 
and added to the other to adjust the side it is driving.

- On the robot, in total there is 1 Jetson Nano, 1 camera, 1 voltage regulator, 1 Arduino Mega, 1 prototype board for connected 5v and grounds, 2 motor
drivers, 4 motors, 4 wheels, and 4 rotary encoders.
