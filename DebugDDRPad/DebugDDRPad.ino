#include <Adafruit_NeoPixel.h>

#define PIN 13

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin();
  strip.show(); 
  Serial.begin(9600);
  for (int i = 3; i < 11; i++) {
    pinMode(i, INPUT);
    Serial.println(i);
  }
}

void loop() {
  for (int i = 3; i < 11; i++) {
    Serial.print(" This is pin: ");
    Serial.println(i);
    Serial.print("And it is: ");
    Serial.println(digitalRead(i));
    if (digitalRead(i) == LOW) {
      strip.setPixelColor(i, strip.Color(255, 0, 255));
      strip.show();
    }
    else { 
          strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
    }
  }
}
