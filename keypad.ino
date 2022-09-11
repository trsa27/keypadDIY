/*
  This example is in the public domain.
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardLogout
*/

#define WINDOWS 1

#include "Keyboard.h"

// change this to match your platform:
int platform = WINDOWS;

const int logOutBTN = 2;
const int shiftLockBTN = 3;
void setup() {
  // make pin 2 an input and turn on the pull-up resistor so it goes high unless
  // connected to ground:
  pinMode(logOutBTN, INPUT_PULLUP);
  pinMode(shiftLockBTN, INPUT);
  Keyboard.begin();
}
void loop() {
  int Flag_shiftLock = 0;

  if(digitalRead(logOutBTN) == HIGH){
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_DELETE);
      delay(100);
      Keyboard.releaseAll();
      // ALT-l:
      delay(100);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('l');
      Keyboard.releaseAll();
      break;
  }
  if(digitalRead(shiftLockBTN) == HIGH ){
    Flag_shiftLock = !Flag_shiftLock;
  }
  if(flag_shiftLock == 1){
      Keyboard.press(KEY_LEFT_SHIFT);
  }
}
