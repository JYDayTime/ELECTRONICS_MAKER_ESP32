/**********************************************************************
  Filename    : Serial Communication for Networking
  Description : Use UART send some data to PC, and show them on serial monitor.
                Use this for testing communication with other devices
                
  Auther      : Carl Jeong
  Modification: 2026 / 01 / 02
**********************************************************************/
#include <Arduino.h>
String inputString = "";      //a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

// put function declarations here:
int myFunction(int, int);

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}

void setup() {
  Serial.begin(115200);
  Serial.println(String("\nESP32 initialization completed!\n")
                + String("Please input some characters,\n")
                + String("select \"Newline\" below and click send button. \n"));
}

void loop() {
  if (Serial.available()) {         // judge whether data has been received
    char inChar = Serial.read();         // read one character
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
  if (stringComplete) {
    Serial.printf("inputString: %s \n", inputString);
    inputString = "";
    stringComplete = false;
  }
}