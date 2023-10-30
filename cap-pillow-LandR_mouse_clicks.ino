#include <CapScroll.h>
#include <CapSlider.h>
#include <CapTouch.h>
#include <CapPin.h>
#include <Mouse.h> // Include the Mouse library

CapPin cPin_1 = CapPin(1);     // read pin 1 (TX on Flora)   - connect to NES right
CapPin cPin_12 = CapPin(12);   // read pin 12 (D12 on Flora) - connect to NES Select

#define THRESH 0.0001  // Capacitive touch threshold, adjust as needed

void setup() {
  Serial.begin(115200);
  Serial.println("start");
  Mouse.begin(); // Initialize the Mouse library
}

void loop() { 
  long leftTotal = cPin_1.readPin(2000);
  long rightTotal = cPin_12.readPin(2000);

  if (rightTotal > THRESH) {
    Serial.println("Left mouse click pressed");
    Mouse.click(MOUSE_LEFT); // Perform a left mouse click
  }

  if (leftTotal > THRESH) {
    Serial.println("Right mouse click pressed");
    Mouse.click(MOUSE_RIGHT); // Perform a right mouse click
  }

  delay(10);
}
