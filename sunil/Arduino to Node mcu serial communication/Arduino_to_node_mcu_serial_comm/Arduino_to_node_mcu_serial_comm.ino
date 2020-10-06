//Arduino code
#include <SoftwareSerial.h>
SoftwareSerial s(1,2);
 
void setup() {
Serial.begin(115200);
s.begin(9600);
}
 
void loop() {
  
int data=258;
s.print(data);
Serial.println(data);
delay(2000);
}
