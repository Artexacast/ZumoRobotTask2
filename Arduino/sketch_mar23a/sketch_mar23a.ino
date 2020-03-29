#include <Zumo32U4.h>
#include "Keyboard.h"
#include <Wire.h>
//Serial1 communicates over XBee
//Serial communicates over USB cable

Zumo32U4Motors motors;
Zumo32U4ProximitySensors proximitySensors;
Zumo32U4LineSensors lineSensors;
Zumo32U4Buzzer buzzer;


int motorsSpeed = 75;
int Serialdata=0;

void setup() {
  // put your setup code here, to run once:

  
  Serial.begin(9600);
  Serial1.begin(9600);

}

void forward(){
  //delay(1000);
  motors.setSpeeds(motorsSpeed, motorsSpeed);
  delay(1000);
  stopMotor();
}

void stopMotor(){
  motors.setSpeeds(0,0);
  delay(1000);
}

void left(){
  stopMotor();
        delay(1000);
        motors.setSpeeds(-100, 100);
        delay(950);
        stopMotor();
}

void oneEighty(){
      motors.setSpeeds(-100, 100);
      delay(2000);
      stopMotor();
}

void right(){
       stopMotor();
       delay(1000);
       motors.setSpeeds(100, -100);
       delay(950);
       stopMotor();
}

void reverse(){
        motors.setSpeeds(-motorsSpeed, -motorsSpeed);
        delay(500);
        stopMotor();
        delay(5000);
}
    
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  char inChar = Serial.read();

  if(inChar == '1') {
     forward();
    }

   if(inChar == '2') {
     reverse();
    }

   if(inChar == '3') {
     left();
    }

   if(inChar == '4') {
     right();
    }

   if(inChar == '5') {
     oneEighty();
    }
    
   if(inChar == '6') {
     Serial.println("In here");
     String aCharArray = Serial.readString();
     motorsSpeed = aCharArray.toInt();
    }
  }
}
