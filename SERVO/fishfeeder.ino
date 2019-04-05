#include <Servo.h>

Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 

// 1 second :     1000;
// 1 min :       60000;
// 1 hour :    3600000;
// 6 hours :  21600000;
// 8 hours :  28800000;
// 10 hours : 36000000;
long FISHFEEDER = 28800000;
long endtime; 
long now;

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
}
 
void loop() 
{ 
  now = millis();
  endtime = now + FISHFEEDER;
  
  while(now < endtime) {
   now = millis();   
  }
  
  //myservo.attach(9);
  //delay(15);

  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 

  myservo.write(90);
  // myservo.detach();
  // delay(15);
  // myservo.detach();
  // delay(15);
}
