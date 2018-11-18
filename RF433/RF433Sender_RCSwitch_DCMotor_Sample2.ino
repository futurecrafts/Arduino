
#include <RCSwitch.h>
int analogPin = 1;
int analogPin1 = 2;
int val = 0;
int hal = 0;
int plus = 9;
int minus = 8;

RCSwitch mySwitch = RCSwitch();

void setup() {
pinMode(plus,OUTPUT);
pinMode(minus,OUTPUT);
pinMode(13,OUTPUT);
digitalWrite(plus,HIGH);
digitalWrite(minus,LOW);
  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);

}

void loop() {
   digitalWrite(13,0);
val = analogRead(analogPin);
 hal = analogRead(analogPin1);

if (val < 200) { 
  mySwitch.send(21, 24); 
  digitalWrite(13,1);
}
else if (hal < 200) 
{
  digitalWrite(13,1);
mySwitch.send(22, 24);
}
else if (hal >800) 
{
  digitalWrite(13,1);
mySwitch.send(23, 24);
}
else if (val > 800) 
{
  digitalWrite(13,1);
mySwitch.send(24, 24);
}
else if (val > 400 && val < 700 && hal > 400 && hal < 700 ){
    mySwitch.send(25, 24);
}
  
}
