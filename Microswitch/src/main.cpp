#include <Arduino.h>
#define LED D13
#define SWITCH D7

int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button
int ledState;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(SWITCH,INPUT_PULLUP);
pinMode(LED,OUTPUT);
currentButtonState = digitalRead(SWITCH);
}

void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(SWITCH); // read new state


    if(lastButtonState == LOW && currentButtonState == HIGH) {
    Serial.println("The button is pressed");
    Serial.println(digitalRead(LED));
    // change angle of servo motor
    if(digitalRead(LED) == 0){
       ledState=1;
       Serial.println("Grasp");
    }
    else if(digitalRead(LED) == 1){
      ledState=0;
       Serial.println("UnGrasp");
    }
  }
   digitalWrite(LED,ledState);
   delay(50);
}
    // control servo motor arccoding to the angle
  
  // put your main code here, to run repeatedly:
// digitalWrite(LED,1);
// delay(500);
// digitalWrite(LED,0);
// delay(500);
// Serial.println(digitalRead(SWITCH));
// delay(50);
