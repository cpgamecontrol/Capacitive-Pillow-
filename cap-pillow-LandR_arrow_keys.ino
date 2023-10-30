#include <CapScroll.h>
#include <CapSlider.h>
#include <CapTouch.h>
#include <CapPin.h>
#include <Keyboard.h>

CapPin cPin_1 = CapPin(1);     // read pin 1 (TX on Flora)   - connect to NES right
CapPin cPin_12 = CapPin(12);   // read pin 12 (D12 on Flora) - connect to NES Select

#define THRESH 0.001  // Capacitive touch threshold, adjust as needed

void setup() {
  Serial.begin(115200);
  Serial.println("start");
  Keyboard.begin();
}

void loop() { 
  long leftTotal = cPin_1.readPin(2000);
  long rightTotal = cPin_12.readPin(2000);

  if (leftTotal > THRESH) {
    Serial.println("Left arrow key pressed");
    Keyboard.press(KEY_LEFT_ARROW);
  } else {
    Keyboard.release(KEY_LEFT_ARROW);
  }

  if (rightTotal > THRESH) {
    Serial.println("Right arrow key pressed");
    Keyboard.press(KEY_RIGHT_ARROW);
  } else {
    Keyboard.release(KEY_RIGHT_ARROW);
  }

  delay(5);
}
