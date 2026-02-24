#include <Arduino.h>

#define LED_PIN 48

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  Serial.println("led on");
  //digitalWrite(LED_PIN, HIGH);
  //neopixelWrite(LED_PIN, 255, 255, 255); // White
  neopixelWrite(LED_PIN, 127, 127, 127); // White
  delay(1000);
  Serial.println("led off");
  //digitalWrite(LED_PIN, LOW);
  neopixelWrite(LED_PIN, 0, 0, 0); // Off
  delay(1000);
  Serial.println("red");
  //neopixelWrite(LED_PIN, 255, 0, 0); // Red
  neopixelWrite(LED_PIN, 127, 0, 0); // Red
  delay(1000);
  Serial.println("green");
  //neopixelWrite(LED_PIN, 0, 255, 0); // Green
  neopixelWrite(LED_PIN, 0, 127, 0); // Green
  delay(1000);
  Serial.println("blue");
  //neopixelWrite(LED_PIN, 0, 0, 255); // Blue
  neopixelWrite(LED_PIN, 0, 0, 127); // Blue
  delay(1000);
}
