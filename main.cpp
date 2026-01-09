#include <Arduino.h>

// put function declarations here:
void change();

int redNS = 4;
int yellowNS = 5;
int greenNS = 34;
int redEW = 35;
int yellowEW = 12;
int greenEW = 13;
int button = 0;  //Possible increase of code by the use of a push button
// we need two sets of variables in which there are red, yellow, and green
// NS = North/South Directions and EW = East/West Directions

void setup() {
  // put your setup code here, to run once:
    pinMode(redNS, OUTPUT);
    pinMode(yellowNS, OUTPUT);
    pinMode(greenNS, OUTPUT);
    pinMode(redEW, OUTPUT);
    pinMode(yellowEW, OUTPUT);
    pinMode(greenEW, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /* If there is a pushbutton, place the pushbutton code here, 
    as of now, leave this commented for future experimentation with pushbutton
    if (digitalRead(button) == HIGH)
    {
        delay(15);
        if (digitalRead(button) == HIGH) 
        {
            change();
        }
    }
    */
  change();
}

// put function definitions here:
void change()
{
    // First, NorthSouth Green and Yellow must be ON for 9 seconds total
    // Green for 6 seconds and Yellow for 3, Meanwhile, EastWest Red is all ON
    digitalWrite(greenNS, HIGH);
    digitalWrite(yellowNS, LOW);
    digitalWrite(redNS, LOW);
    digitalWrite(greenEW, LOW);
    digitalWrite(yellowEW, LOW);
    digitalWrite(redEW, HIGH);
    delay(6000);
    digitalWrite(greenNS, LOW);
    digitalWrite(yellowNS, HIGH);
    digitalWrite(redNS, LOW);
    digitalWrite(greenEW, LOW);
    digitalWrite(yellowEW, LOW);
    digitalWrite(redEW, HIGH);
    delay(3000);
    // Now for the lateral part of the intersection
    // Next, East West Green and Yellow must be ON for 9 seconds total
    // Green for 6 seconds and Yellow for 3, Meanwhile, NorthSouth Red is all ON
    digitalWrite(greenNS, LOW);
    digitalWrite(yellowNS, LOW);
    digitalWrite(redNS, HIGH);
    digitalWrite(greenEW, HIGH);
    digitalWrite(yellowEW, LOW);
    digitalWrite(redEW, LOW);
    delay(6000);
    digitalWrite(greenNS, LOW);
    digitalWrite(yellowNS, LOW);
    digitalWrite(redNS, HIGH);
    digitalWrite(greenEW, LOW);
    digitalWrite(yellowEW, HIGH);
    digitalWrite(redEW, LOW);
    delay(3000);
    //this is the largest part of our code. It does all the work and changes the led
    //you can change the "delay" values to customize the duration of your stoplight.
}