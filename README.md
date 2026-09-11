Smart Home Device Simulator

Description

A simple C++ program that simulates a smart home system with different devices such as:

- Light
- Fan
- AC

The program allows the user to select a device and turn it ON or OFF. Each device has its own operating behavior.

OOP Concepts Used

- Inheritance — "Light", "Fan", and "AC" inherit from the "SmartDevice" base class.
- Encapsulation — Device status and other device-specific data are kept inside the classes.
- Polymorphism — The "display()" function behaves differently for each device.

Features

- Select a smart home device.
- Turn the selected device ON or OFF.
- Set fan speed.
- Set AC temperature.
- Display the current device status and operating behavior.

Sample Input

Choose Device:
1. Light
2. Fan
3. AC
Choice: 2
Enter Speed: 3
Enter 1 to turn ON or 0 to turn OFF: 1

Sample Output

----- SMART HOME -----
Device: Fan
Status: ON
Speed : 3
Fan is running at speed level 3

How It Works

1. The user selects a device.
2. The program creates the corresponding device object.
3. Device-specific settings are entered.
4. The user chooses whether to turn the device ON or OFF.
5. The device status and behavior are displayed.

File

smart_home.cpp

Concepts Demonstrated

SmartDevice
├── Light
├── Fan
└── AC
