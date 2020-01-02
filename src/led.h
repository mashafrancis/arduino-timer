#ifndef ARDUINO_TIMER_SRC_LED_H
#define ARDUINO_TIMER_SRC_LED_H

#include "simple_timer.h"

/** Simple class that will blink the led in cycle of long-short*N, where N is the status given */
class Led
{
	constexpr static const int INTERVAL_SHORT = 200;
	constexpr static const int INTERVAL_LONG = 700;

public:
	void setup(int pin);
	void loop();
	void set_status(int blinks);

protected:
	SimpleTimer timer;
	int pin{};
	int blinks{};
	int blink_loop{};
};

#endif //ARDUINO_TIMER_SRC_LED_H
