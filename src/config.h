#pragma once

#include <stdint>
#include <type_traits>

template<typename E>
constexpr auto to_integral(E e) -> typename std::underlying_type<E>::type {
	return static_cast<typename std::underlying_type<E>::type>(e);
}

// User configurations are provided as structs so that it will be easier to
// change and to read.

struct Config_run_table_time {
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
};

struct Config_run_table {
	Config_run_table_time active_start;
	Config_run_table_time active_stop;
	Config_run_table_time period_on;
	Config_run_table_time period_off;
};

struct Config_pump {
	uint16_t low_level_height_mm;
	uint8_t threshold_water_up_s;
};

struct Config {
	Config_run_table runtable;
	Config_pump pump;
	uint8_t timezone_h;
};

extern const Config CONFIG;

// Hardware configurations fixed

#define PIN_RTC_SCL 14
#define PIN_RTC_SDA 12
#define PIN_LED     15
#define PIN_PUMP    4
#define PIN_SWITCH  16
#define PIN_TRIGGER 2
#define PIN_ECHO    5
#define PIN_WDETECT 13

