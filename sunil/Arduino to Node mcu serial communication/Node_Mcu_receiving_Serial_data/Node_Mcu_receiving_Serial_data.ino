#include <SoftwareSerial.h>
SoftwareSerial s(D6,D5);
int data;
void setup() {
s.begin(9600);
Serial.begin(115200);
}
 
void loop() {
  s.write("s");
 
  data=s.parseInt();
    Serial.println(data);
    Serial.println("ss");
    //delay(2000);
  
 
 
}
