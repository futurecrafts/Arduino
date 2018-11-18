#include <RCSwitch.h>
int napred = 7;
int napred1 = 8;
int levo = 9;
int levo1 = 10;
int pwmnazad = 5;
int pwmnapred =6;
int led = 13;
RCSwitch mySwitch = RCSwitch();

void setup() {
   pinMode(napred, OUTPUT);
   pinMode(led, OUTPUT);
     pinMode(pwmnazad, OUTPUT);
      pinMode(pwmnapred, OUTPUT);
     pinMode(napred1, OUTPUT);
      pinMode(levo, OUTPUT);
       pinMode(levo1, OUTPUT);
  Serial.begin(9600);
    analogWrite(pwmnazad,60);
    analogWrite(pwmnapred,60);
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
}

void loop() {
  digitalWrite(led,LOW);
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 21) {
   
  digitalWrite(napred,HIGH);
   digitalWrite(napred1,LOW);
   digitalWrite(levo,HIGH);
   digitalWrite(levo1,LOW);
   digitalWrite(led,HIGH);
    }  
    else if (value == 22){
      
      digitalWrite(levo,HIGH);
   digitalWrite(levo1,LOW);
   digitalWrite(led,HIGH);
    }
   else if (value == 23){
        
       digitalWrite(napred,HIGH);
   digitalWrite(napred1,LOW);
   digitalWrite(led,HIGH);
    }
     else if (value == 24){
       digitalWrite(led,HIGH);
   digitalWrite(napred,LOW);
   digitalWrite(napred1,HIGH);
   digitalWrite(levo,LOW);
   digitalWrite(levo1,HIGH);
   
    }
      else if (value == 25){
        digitalWrite(led,HIGH);
  digitalWrite(napred1,LOW);
   digitalWrite(napred,LOW);
   digitalWrite(levo1,LOW);
   digitalWrite(levo,LOW);
    }
    mySwitch.resetAvailable();
  }
}
