#include "Arduino.h"

#include "led.h"

Led LED; // NOLINT(cert-err58-cpp)

// the setup function runs once when you press reset or power the board
void setup() {
  LED.setup(13);
  LED.set_status(2);
}

// the loop function runs over and over again forever
void loop() {
  LED.loop();
}
