// COMP-10184 – Mohawk College 
// PIR Sensor Test Application 
// Turn on the blue LED with motion is detected. 

/*
  "StAuth10184: I Jesse Em, 000295218 certify that this material is my original work. 
  No other person's work has been used without due acknowledgement. 
  I have not made my work available to anyone else."
*/

// STAGE 5 (?)

// Blinks only from 4 to 6 seconds, BUT THE STAGE 5 BUTTON FUNCTIONALITY IS THERE.

// Edit: I just noticed there were tons of tips in the assignment instructions but I hadn't scrolled down.
// I'm going to submit this though because I think this is the best you can do with absolute minimal code.
// and functions.


 
#include <Arduino.h> 
 
// digital input pin definitions 
#define PIN_PIR D5 
#define PIN_BUTTON D6 
#define BLINK_DELAY 125
 
 
// ************************************************************* 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure the LED output 
  pinMode(LED_BUILTIN, OUTPUT); 
 
  // PIR sensor is an INPUT 
  pinMode(PIN_PIR, INPUT); 
 
  // Button is an INPUT 
  pinMode(PIN_BUTTON, INPUT_PULLUP); 

  // start with the LED off
  digitalWrite(LED_BUILTIN, HIGH);  

} 
 
// ************************************************************* 
void loop() { 
  
  bool bPIR = false; 
  bool button = false;
 
  bPIR = digitalRead(PIN_PIR); 
  button = digitalRead(PIN_BUTTON);
  

  // two states, waiting for motion and no motion

  // waiting for motion
  if (bPIR) {
    Serial.print("motion detected");

  // if the button is pushed
    if (!button) {
      Serial.print("turning off");
      digitalWrite(LED_BUILTIN, HIGH); 
      //arbitrary value to "turn it off"
      delay(4000000);                       
    } 
    // otherwise the button is not pushed, blink
    else {
      digitalWrite(LED_BUILTIN, LOW); 
      delay(BLINK_DELAY);                      
      digitalWrite(LED_BUILTIN, HIGH); 
      delay(BLINK_DELAY); 
    }

  // keep the light on once the motion blinking has ended
    digitalWrite(LED_BUILTIN, LOW);  
    Serial.println("motion ended"); 
  } 

}