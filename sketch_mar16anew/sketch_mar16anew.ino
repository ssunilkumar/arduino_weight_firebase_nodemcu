#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Redmi";
const char* password = "shenbasunil";

#define TOKEN "uFzbi1OG3QecmSZYiurv" //Access token of device Display
char ThingsboardHost[] = "demo.thingsboard.io";

WiFiClient wifiClient;
PubSubClient client(wifiClient);
int status = WL_IDLE_STATUS;

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("connected to");
  Serial.println(ssid);
  client.setServer( ThingsboardHost, 1883 );
}

void loop()
{
if ( !client.connected() ) 
{
    reconnect();
}
getAndSendTemperatureAndHumidityData();
  delay(5000);
}

void getAndSendTemperatureAndHumidityData()
{
  
 
  // Prepare a JSON payload string
  String payload = "{";
 payload += "\"Humidity\":";payload += 60; payload += ",";
 payload += "\"Temperature\":";payload += 25; 
  payload += "}";

  char attributes[1000];
  payload.toCharArray( attributes, 1000 );
  client.publish( "v1/devices/me/telemetry",attributes);
  Serial.println( attributes );
   
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    status = WiFi.status();
    if ( status != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("Connected to AP");
    }
    Serial.print("Connecting to ThingsBoard node ...");
    // Attempt to connect (clientId, username, password)
    if ( client.connect("ESP8266", TOKEN, NULL) ) {
      Serial.println( "[DONE]" );
    } else {
      Serial.print( "[FAILED] [ rc = " );
      Serial.println( " : retrying in 5 seconds]" );
      delay( 500 );
    }
  }
}
