#include "config.h"

// Note: G++ seems to require that these are in the proper order (same as declared).
const Config CONFIG = {
	.runtable = {    // Run the pump for 1min every 15min from 7:00 to 20:00
		.active_start = {.hour = 7, .minute = 0, .second = 0},
		.active_stop = {.hour = 20, .minute = 15, .second = 0},
		.period_on = {.hour = 0, .minute = 1, .second = 0},
		.period_off = {.hour = 0, .minute = 15, .second = 0},
	},
	.pump = {
		.low_level_height_mm = 400,
		.threshold_water_up_s = 10,
	},
	.timezone_h = 3,
};
