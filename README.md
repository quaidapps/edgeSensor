# edgeSensor
Arduino code for use on edge device
Use this code to send mq-135 air quality sensor data to a FireBse server. Note some devices have different breakout arrangements, mainly note the GND and VCC might have different locations based on the manufacturer.

##HW setup
Connection order is 
  NodeMCU GND to sensor GND
  NodeMCU Vin (5V) to sensor VCC
  NodeMCU A0 to sensor Aout
##Environment setup
There are severla installation steps: [see here for a great explenations, missing step 4 here](https://github.com/FirebaseExtended/firebase-arduino/tree/master/examples/FirebaseRoom_ESP8266)
1. Install ESP  8266 Arduino IDE package - follow instructions in step 2 [here](https://dzone.com/articles/programming-the-esp8266-with-the-arduino-ide-in-3)
2. install the siliconLabs USB to UART bridge as describrd [here](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)

At this point you should be able to communicate with the NodeMCU and load sinple "blink" style ino code. To communicate with Firebase also inatall the following package and dependency
3. download the nodeMCU firebase zip file (see first link here)
4. NOTE: the documentation is missing to note that you will also need to install the [arduinojson](https://arduinojson.org/?utm_source=meta&utm_medium=library.properties) package.
