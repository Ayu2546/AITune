#include <Arduino.h>

const int SR = 2; // Red switch
const int SY = 3; // Yellow switch
const int SW = 4; // White switch
const int SG = 5; // Green switch
const int SB = 6; // Blue switch

String str;
boolean red, yellow, white, green, blue;

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
  str = "";

  red = digitalRead(SR);
  yellow = digitalRead(SY);
  white = digitalRead(SW);
  green = digitalRead(SG);
  blue = digitalRead(SB);

  output(red, yellow, white, green, blue);
  Serial.println(str);

  delay(10);
}

void output(boolean red, boolean yellow, boolean white, boolean green, boolean blue) {
  if(red == HIGH) {
    str += "R,";
  } 

  if(yellow == HIGH) {
    str += "Y,";
  } 

  if(white == HIGH) {
    str += "W,";
  } 

  if(green == HIGH) {
    str += "G,";
  } 
  
  if(blue == HIGH) {
    str += "B,";
  }

  if(str.endsWith(",")) {
    str = str.substring(0, str.length() - 1);
  }

  if(str.length() == 0) {
    str = "NONE";
  }

  return;
}