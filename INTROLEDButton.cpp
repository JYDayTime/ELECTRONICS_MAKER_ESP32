
/**********************************************************************
  Filename    : One of the First Lessons to Introduce Students to the
                Idea of Electronics, This should be one of the first
                lessons to be with
  Description : Control LED by button, a simple task for kids.
  Auther      : Carl Jeong  (I need to see a doctor... the ghost is tal
                talking...)
  Modification: 2025/12/23
**********************************************************************/
#include <Arduino.h>
#define PIN_LED    2
#define PIN_BUTTON 13
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin PIN_LED as an output.
  pinMode(PIN_BUTTON, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    delay(20);
    if (digitalRead(PIN_BUTTON) == LOW) {
      reverseGPIO(PIN_LED);
    }
    while (digitalRead(PIN_BUTTON) == LOW);
    delay(20);
    //while (digitalRead(PIN_BUTTON) == LOW);
  }
}

void reverseGPIO(int pin) {
  digitalWrite(pin, !digitalRead(pin));

}
