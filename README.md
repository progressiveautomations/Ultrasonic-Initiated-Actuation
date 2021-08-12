# Ultrasonic-Initiated-Actuation
Controlling an actuator based on the distance of an object from the ultrasonic sensor

Required Components: 
12VDC Power Supply (https://www.progressiveautomations.com/products/ps-20-12) 
Arduino Mega (https://store.arduino.cc/usa/mega-2560-r3)
MegaMoto (https://www.progressiveautomations.com/products/lc-80)
Ultrasonic Sensor (https://www.progressiveautomations.com/products/lc-217)
Actuator (12VDC with max. 20A current draw) (https://www.progressiveautomations.com/pages/mini-linear-actuators) USB Cable Type A/B Jumper Wires

Connections: 
MegaMoto stacked on Arduino  
MegaMoto + to 12VDC
MegaMoto - to GND

MegaMoto Jumper A2 and A3 shorted

Motor+ to MegaMoto A
Motor- to MegaMoto B 

VCC to 5V Arduino
GND to GND Arduino
Trig to Pin 35 Arduino 
Echo to Pin 40 Arduino


-Guninder M
