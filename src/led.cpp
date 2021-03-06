#include <Arduino.h>

#include "led.h"

void Led::setup(int pin) {
  this->blink_loop = 0;
  this->blinks = 0;
  this->pin = pin;
  pinMode(pin, OUTPUT);
  digitalWrite(pin, 1);
  this->timer.reset();
}

void Led::loop() {
  int interval = 0;
  if (this->blinks == 0) {
	interval = INTERVAL_LONG;
  } else {
	interval = INTERVAL_SHORT;
  }

  if (!this->timer.check(interval))
	return;

  this->timer.reset();
  this->blink_loop += 1;

  if (this->blink_loop >= 2*blinks)    // accept equal, since with one blink we have long-short, long-short
	this->blink_loop = 0;

  digitalWrite(pin, (this->blinks & 0x01));
}

void Led::set_status(int blinks) {
  if (this->blinks == blinks)
	return;

  this->blink_loop = 0;
  this->blinks = blinks;
}
