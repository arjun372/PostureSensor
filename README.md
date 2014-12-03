
Objective
The purpose of this project is to design and build a wireless-capable, wearable sensor/actuator combination for biofeedback.  We intend to create a sensor that actively detects the posture of a user to generate a response (based on preset values of posture) in near real time. This information is then transmitted to an actuator (vibration motor, LED) that provides feedback to the user about their current orientation. This we hope will enable the user to be mindful, and possibly improve their posture over time.

Principle of operation
FIG 1.1 above illustrates a basic schematic of the proposed sensing and feedback devices. The two devices can be expressed as finite state machines as  :

WEARABLE SENSOR


Components ::

A
Adafruit Trinket - 16MHz - 5V
B
3.7V LiPo 240 mAh battery
C
KEDSUM HC-06 Bluetooth v2.0 
D
Strain Gauge- Resistive sensor



BIOFEEDBACK DEVICE

Components ::

A
Adafruit Trinket - 16MHz - 5V
B
3.7V LiPo 240 mAh battery
C
KEDSUM HC-06 Bluetooth v2.0 
D
Momentary Push Button
E
3.3V vibration motor
F
10mm LED




Biofeedback Device - Master


CONNECT MODE : 
Using a toggle switch, biofeedback turns on, Adafruit microcontroller (A) enables (via serial interface) Bluetooth module (C) to search for, pair with, and connect as MASTER to a BT device with a preset MAC address (known to be that of sensor).

DEEP SLEEP MODE :
Adafruit goes into deep sleep mode. Bluetooth device is suspended. Adafruit waits for an interrupt generated by a button press event (C) . Goes to CONNECT MODE when pressed.

QUERY SENSOR :
If connection is active, biofeedback device requests resistor value from the sensor. If value has changed from previous request, actuators (E) (F) are updated based on the new value.

SEND THRESHOLD CMD :
Essentially a recalibration feature, biofeedback device requests the current input value to be set as the threshold value for sensor.







Sensor - Slave


DEEP SLEEP & WAIT FOR BT : 
Using a toggle switch, sensor turns on, Adafruit microcontroller (A) enables (via serial interface) Bluetooth module (C) to pair as slave with any device that provides the correct pairing code (predetermined eg. 0000, 0372). Bluetooth remains pairable but not discoverable.

SLEEP & LISTEN FOR REQUEST :
Adafruit goes into deep sleep mode until the biofeedback device (MASTER) connects with the SLAVE Bluetooth module (on sensor) AND requests sensor event information.

READ SENSOR VALUE :
Upon event request, Adafruit reads and processes resistance values produced by the bending strain gauge (D). If the resistance is above a preset THRESHOLD value, the posture is determined to be slouched, and a bend value is calculated (based on change in resistance as a function of bend) by the Adafruit controller and relayed to the Bluetooth module, which sends it to the biofeedback device.

THRESHOLD CHANGED :
Additionally, the sensor will respond to ‘CHANGE_THRESHOLD’ command received from the MASTER biofeedback device by setting the bend threshold value as the new value received from the biofeedback device.

Functions to implement
Factors such as design complexity, and the possibility of running into unforeseen issues mandate a modular design approach and an accelerated development timeline. Bearing this in mind, the overall design process will be divided into two main stages. During Stage One, we propose to program the sensors and prototype the electronics until they are functional ‘as a proof of concept’. Stage Two will focus on code optimization, wearability and packaging. Specifically, the two stages are partitioned as :


Stage One 
Week 5 
Finalize project design (complete)
Sensor and transducer circuit design and performance measurement (complete) 
Program Bluetooth serial communication layer with microcontroller (in progress)
Get parts needed for Stage One (complete)

Week 6
Prototype using components, breadboard and MyDAQ equipment
Stable power supply design using passives and microcontroller
Interface transducers with microcontroller software 
Attach strain gauge to clothing and collect data

Week 7
Power circuits using batteries. Measure reliability and performance. 
Successfully transmit posture signal from sensor to biofeedback device.
If signal successfully transmits and an event is generated on the biofeedback device, then Stage One is complete.
Stage Two 
Week 8
Design wearable attachments and housing for sensor
Calibrate sensor, optimize signal transmission and processing
Documentation for final project report. Begin final report.

Week 9
Preparation for final demonstration.
Record mock demonstration
Complete project report

Week 10
Demo



Parts List ::  
We currently have all the parts that we need for Stage One. This includes the sensors, microcontrollers, transreceivers and passive components. We do not need any additional components at this time.
