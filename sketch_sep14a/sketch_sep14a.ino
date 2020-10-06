#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
// #include <FirebaseArduino.h>
// #include <ArduinoJson.h>
 #include <ESP8266HTTPClient.h>

// Set these to run example.
#define FIREBASE_HOST "lively-epsilon-285117.firebaseio.com/"
#define FIREBASE_AUTH "PdD7Cc4jds8enASFrvsDWcHfJtXdAOUb5EDuOdxA"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "shenbasunil"

String myString;
int vr = A0; // variable resistor connected 
int sdata = 0; // The variable resistor value will be stored in sdata.

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(vr ,INPUT);
  // connect to wifi.
  pinMode(D0,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

   Firebase.setString("Variable/Value","fahad");
}

void loop()
{

sdata = analogRead(vr);
myString = String(sdata); 
Serial.println(myString); 
Firebase.setString("Variable/Value",myString);
delay(1000);            
}
