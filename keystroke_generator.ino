/*********************************** 
  This program will simulate a key press, 
   as if coming from a keyboard stroke.
  The output is between 7 and 14 minutes. 
  April 24, 2022
***********************************/
// Use "Arduino Lenardo" for board.
#include <Keyboard.h>

int data;
long delayTime;

void setup() {
  // put your setup code here, to run once:
  // Initiate random number from pin 0 input. 
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  // This will generate an ASCII printable characters from space to delete.
  data = random(32, 127); // arduino random number in range

  // Send keyboard stroke.
  Keyboard.press(data);
  // Clear keyboard stroke by releasing.
  Keyboard.releaseAll();
  
  /* Backpace over the typed character to erase it. */
  // Delay 1 second to allow seeing the character before backspacing over,
  // then backspace, and clear keyboard stroke by releasing.
  //delay(1000);
  //Keyboard.press(8);
  //Keyboard.releaseAll();

  // Random delay time between 7 & 14 minutes.
  delayTime = random(420000, 840000);
  //delayTime = 60000; //1 minute for diagnostics.

  delay(delayTime);
  
}
