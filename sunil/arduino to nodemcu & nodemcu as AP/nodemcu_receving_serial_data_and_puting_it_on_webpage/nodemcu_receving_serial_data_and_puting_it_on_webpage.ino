#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"

#include <Wire.h>

// Set your access point network credentials
const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";
AsyncWebServer server(80);

SoftwareSerial s(D6,D5);
int data;
void setup() {
s.begin(9600);
Serial.begin(9600);

Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", s.read().c_str());
  });

}
 
void loop() {
  s.write("s");
  if (s.available()>0)
  {
    data=s.read();
    Serial.println(data);
    Serial.println("ss");
  }
 
 
}
