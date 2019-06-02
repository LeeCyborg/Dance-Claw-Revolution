/*

   Motor Driver 1: X and Y (Yellow Tape and Blue Tape)
  Arduino D2  - Motor Driver PWM 1 Input
  Arduino D3  - Motor Driver DIR 1 Input
  Arduino D4  - Motor Driver PWM 2 Input
  Arduino D5 - Motor Driver DIR 2 Input
  Arduino GND - Motor Driver GND
   Motor Dfriver 2: Z and Claw (Red Tape and Weird Connector)
  Arduino D6  - Motor Driver PWM 1 Input
  Arduino D7  - Motor Driver DIR 1 Input
  Arduino D8  - Motor Driver PWM 2 Input
  Arduino D9 - Motor Driver DIR 2 Input
  Arduino GND - Motor Driver GND
  Big Red Butt
   Arduino 10 -- Butt >> +
   DDR:
  Arduino D22 - Up
  Arduino D23 - Down
  Arduino D24 - Left
  Arduino D25 - Right
  Arduino D26 - Top Right
  Arduino D27 - Top Left
  Arduino D28 - Bottom Right
  Arduino D29 - Bottom Left
*/
#include "CytronMotorDriver.h"
#include <Adafruit_NeoPixel.h>

#define stepDuration 100
#define bigRedButt 10
#define lights 13
int DDRPins[8] = {22, 23, 24, 25, 26, 27, 28, 29};
CytronMD x(PWM_DIR, 2, 3);
CytronMD y(PWM_DIR, 4, 5);
CytronMD z(PWM_DIR, 6, 7);
CytronMD claw(PWM_DIR, 8, 9);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, lights, NEO_GRB + NEO_KHZ800);
void setup() {
  strip.begin();
  strip.show();
  Serial.begin(9600);
  for (int i = 0; i < 9; i++) {
    pinMode(DDRPins[i], INPUT);
    Serial.println(DDRPins[i]);
  }
  pinMode(10, INPUT_PULLUP);
}

void loop() {
  checkDDR();
}

void checkDDR() {
  for (int i = 0; i < 9; i++) {
    Serial.println(digitalRead(DDRPins[i]));
  }
}
void GoX(int dir) {
  x.setSpeed(dir);
  delay(stepDuration);
  x.setSpeed(0);
}
void GoY(int dir) {
  y.setSpeed(dir);
  delay(stepDuration);
  y.setSpeed(0);
}
void GoZ(int dir) {
  z.setSpeed(dir);
  delay(stepDuration);
  z.setSpeed(0);
}


