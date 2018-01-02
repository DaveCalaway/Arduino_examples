/*
  KeyboardAndMouseControl

  Schematic: https://goo.gl/Q6ESqC

  Controls the mouse from five pushbuttons on an Arduino Leonardo, Micro or Due.
  No resistors need!

  Hardware:
  - five pushbuttons attached to D2, D3, D4, D5, D6

  The mouse movement is always relative. This sketch reads four pushbuttons, and
  uses them to set the movement of the mouse.

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created by Tom Igoe
  update by Davide Gariselli ( https://github.com/DaveCalaway )

  This example code is in the public domain.
*/

#include "Keyboard.h"
#include "Mouse.h"

// set pin numbers for the five buttons:
const int upButton = 2;
const int downButton = 3;
const int leftButton = 4;
const int rightButton = 5;
const int mouseButton = 6;

void setup() { // initialize the buttons' inputs:
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(mouseButton, INPUT_PULLUP);

  Serial.begin(9600);
  // initialize mouse control:
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  // use serial input to control the mouse:
  if (Serial.available() > 0) {
    char inChar = Serial.read();

    switch (inChar) {
      case 'u':
        // move mouse up
        Mouse.move(0, -40);
        break;
      case 'd':
        // move mouse down
        Mouse.move(0, 40);
        break;
      case 'l':
        // move mouse left
        Mouse.move(-40, 0);
        break;
      case 'r':
        // move mouse right
        Mouse.move(40, 0);
        break;
      case 'm':
        // perform mouse left click
        Mouse.click(MOUSE_LEFT);
        break;
    }
  }

  // use the pushbuttons to control the keyboard:
  if (digitalRead(upButton) == LOW) {
    Keyboard.write('u');
  }
  if (digitalRead(downButton) == LOW) {
    Keyboard.write('d');
  }
  if (digitalRead(leftButton) == LOW) {
    Keyboard.write('l');
  }
  if (digitalRead(rightButton) == LOW) {
    Keyboard.write('r');
  }
  if (digitalRead(mouseButton) == LOW) {
    Keyboard.write('m');
  }

}
