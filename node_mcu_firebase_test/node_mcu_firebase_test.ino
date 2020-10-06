


//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
//#include <FirebaseArduino.h>

#define FIREBASE_HOST "lively-epsilon-285117.firebaseio.com/" //Without http:// or https:// schemes
#define FIREBASE_AUTH "PdD7Cc4jds8enASFrvsDWcHfJtXdAOUb5EDuOdxA"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "sunilshenba"


//Define FirebaseESP8266 data object
FirebaseData firebaseData;

FirebaseJson json;

void printResult(FirebaseData &data);

int a;

void setup()
{

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //Firebase.reconnectWiFi(true);
}

void loop()
{
  a=Firebase.getInt("/led");
  Serial.println(a);
  delay(1000);
}
}
