# edgeSensor
Arduino code for use on edge device
Use this code to send mq-135 air quality sensor data to a FireBse server. Note some devices have different breakout arrangements, mainly note the GND and VCC might have different locations based on the manufacturer.
Connection order is 
  NodeMCU GND to sensor GND
  NodeMCU Vin (5V) to sensor VCC
  NodeMCU A0 to sensor Aout
