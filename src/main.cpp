#include <Arduino.h>

const int SR = 2; // Red switch
const int SY = 3; // Yellow switch
const int SW = 4; // White switch
const int SG = 5; // Green switch
const int SB = 6; // Blue switch

// Determining if switches have been pressed
void output(boolean, boolean, boolean, boolean, boolean);

// Setput serial communication and pins 
void setup() {
  Serial.begin(115200);
  pinMode(SR, INPUT);
  pinMode(SY, INPUT);
  pinMode(SW, INPUT);
  pinMode(SG, INPUT);
  pinMode(SB, INPUT);
}

// The main operation
void loop() {
  boolean red, yellow, white, green, blue;

  red = digitalRead(SR);
  yellow = digitalRead(SY);
  white = digitalRead(SW);
  green = digitalRead(SG);
  blue = digitalRead(SB);

  output(red, yellow, white, green, blue);

  delay(100);
}

void output(boolean red, boolean yellow, boolean white, boolean green, boolean blue) {
  if(red == HIGH) {
    Serial.println("SR");
  } 

  if(yellow == HIGH) {
    Serial.println("SY");
  } 

  if(white == HIGH) {
    Serial.println("SW");
  } 
  
  if(green == HIGH) {
    Serial.println("SG");
  } 
  
  if(blue == HIGH) {
    Serial.println("SW");
  }
}