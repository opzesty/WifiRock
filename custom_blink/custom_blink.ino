/*
  Blink

  This is a change by Zach
Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

#include <ESP8266WiFi.h>

const char* ssid     = "YOUR ROUTER SSID";
const char* password = "YOUR PASSORD";   

int wifiStatus;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(D1, OUTPUT);
      
  Serial.begin(115200);\
  delay(200);
 
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Your are connecting to;");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(D1, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(500);                       // wait for a second
  //digitalWrite(D1, LOW);    // turn the LED off by making the voltage LOW
  //delay(500);                       // wait for a second

  wifiStatus = WiFi.status();
  if(wifiStatus == WL_CONNECTED){
     Serial.println("");
     Serial.println("Your ESP is connected!");  
     Serial.println("Your IP address is: ");
     Serial.println(WiFi.localIP());  
  }
  else{
    Serial.println("");
    Serial.println("WiFi not connected");
  }
  delay(1000); // check for connection every once a second
}
