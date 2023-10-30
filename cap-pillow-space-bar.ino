#include <CapScroll.h>
#include <CapSlider.h>
#include <CapTouch.h>
#include <CapPin.h>
#include <Keyboard.h> // Include the Keyboard library

CapPin cPin_1 = CapPin(1);     // read pin 1 (TX on Flora)   - connect to NES right
CapPin cPin_12 = CapPin(12);   // read pin 12 (D12 on Flora) - connect to NES Select

#define THRESH 0.0001  // Capacitive touch threshold, adjust as needed

void setup() {
  Serial.begin(115200);
  Serial.println("start");
  Keyboard.begin(); // Initialize the Keyboard library
}

void loop() { 
  long leftTotal = cPin_1.readPin(2000);
  long rightTotal = cPin_12.readPin(2000);

  // if (leftTotal > THRESH) {
  //   Serial.println("Left spacebar pressed");
  //   Keyboard.press(32); // Press the spacebar key (ASCII value)
  // } else {
  //   Keyboard.release(32); // Release the spacebar key (ASCII value)
  // }

  if (rightTotal > THRESH) {
    Serial.println("Right spacebar pressed");
    Keyboard.press(32); // Press the spacebar key (ASCII value)
  } else {
    Keyboard.release(32); // Release the spacebar key (ASCII value)
  }

  delay(1);
}

