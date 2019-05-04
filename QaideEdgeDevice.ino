/*
 * edgeSensor code, written by the memebers of Team openQuaid. 
 * To use this code, hookup a QM135 gas sensor in the following way:
 * A0 to the Analog pin
 * Vin (5V) to the VCC pin
 * GND to the GND pin
 * Allow the sensor some 10 minutes to heat up for stable reading.
 * See more at https://github.com/quaidapps
 * */


// Add dependencies for wifi connectivity
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>


// Define FireBase dependencies
#define FIREBASE_HOST "<My project>.firebaseio.com"
#define FIREBASE_AUTH "<My authentication>"

//Define password details
#define WIFI_SSID "WiFi network name"
#define WIFI_PASSWORD "WiFi PAssword"

// Define the Firebase object
FirebaseData fireBaseData;
// Define FireBase path and variable name
String path = "/ESP8266_Test";
int gauge = 0;

void setup()
// Setup wifi connection
{
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.print("Connected to Host: ");
  Serial.println(FIREBASE_HOST);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  Firebase.reconnectWiFi(true);
  Serial.println("------------------------------------");
}

void loop()
{
  // read the input on analog pin 0:
  double sensorValue = analogRead(A0);
  // calibrate a 10 bit to be in the range 0-100 not 0-1024
  gauge = sensorValue/1024*100;
  //Print the gauge value for arduino IDE debug
  Serial.println(gauge);
  // Attempt to write gauge value on FireBase
  if (!Firebase.setDouble(firebaseData, path + "/gauge", gauge))
  {
    Serial.println("Faile: " + path + "/gauge" + ", Reason:" + firebaseData.errorReason());
  }
  delay (100);
}
