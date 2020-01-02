#include <climits>
#include "catch.hpp"
#include "Arduino.h"

#include "simple_timer.h"

TEST_CASE("Basic timer", "[timer]") {
  SimpleTimer timer;

  SECTION("Normal functionality") {
	REQUIRE(timer.check(10));
	timer.reset();
	REQUIRE(!timer.check(10));
	millis_fake.return_val = 1 << 10;
	REQUIRE(timer.check(10));
  }
  SECTION("Overflow") {
	millis_fake.return_val = ULLONG_MAX - 1;
	timer.reset();
	millis_fake.return_val = ULLONG_MAX;
	REQUIRE(!timer.check(10));

	millis_fake.return_val = 10;
	REQUIRE(timer.check(10));

	// Then check the case where we wait for whole timer to go all around over.
	timer.reset();
	REQUIRE(!timer.check(10));
	millis_fake.return_val =
		0; // and the timer went overflow without any check in between
	REQUIRE(timer.check(10));
  }

  SECTION("Reset with carry normal and overflow") {
	const unsigned long start_value[] = {0, ULLONG_MAX - 500};
	for (int start_loop = 0; start_loop < 2; start_loop++) {
	  millis_fake.return_val = start_value[start_loop];
	  timer.reset();
	  REQUIRE(!timer.check(500));
	  millis_fake.return_val += 1000;
	  REQUIRE(timer.check(500));
	  timer.reset_with_carry(450);
	  REQUIRE(timer.check(500));
	}
  }

};
