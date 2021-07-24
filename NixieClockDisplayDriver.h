#pragma once

#include "NixieTubeDriver.h"
#include "pin_definition.h"

class NixieClockDisplayDriver
{
public:
	NixieClockDisplayDriver() :
		_tube_minute_upper(PIN_7, PIN_5, PIN_4, PIN_6),
		_tube_minute_lower(PIN_0, PIN_2, PIN_3, PIN_1),
		_tube_hour_upper(PIN_7, PIN_5, PIN_4, PIN_6),
		_tube_hour_lower(PIN_0, PIN_2, PIN_3, PIN_1)
	{
		pinMode(PIN_SELECT_MINUTE, OUTPUT);
		pinMode(PIN_SELECT_HOUR, OUTPUT);
	}

	void displayHour(int hour) {
		// select the 74LS373 for the hour digits display
    
    digitalWrite(PIN_SELECT_HOUR, LOW);
    digitalWrite(PIN_SELECT_MINUTE, LOW);    
    
		int upper_digit = hour / 10;
		int lower_digit = hour % 10;
		_tube_hour_upper.displayDigit(upper_digit);
		_tube_hour_lower.displayDigit(lower_digit);
    digitalWrite(PIN_SELECT_HOUR, HIGH);
    digitalWrite(PIN_SELECT_MINUTE, LOW);

		digitalWrite(PIN_SELECT_HOUR, LOW);
		digitalWrite(PIN_SELECT_MINUTE, LOW);
	}

	void displayMinute(int minute) {
		// select the 74LS373 for the minute digits display
    
    digitalWrite(PIN_SELECT_HOUR, LOW);
    digitalWrite(PIN_SELECT_MINUTE, LOW);

		int upper_digit = minute / 10;
		int lower_digit = minute % 10;
		_tube_minute_upper.displayDigit(upper_digit);
		_tube_minute_lower.displayDigit(lower_digit);
    digitalWrite(PIN_SELECT_HOUR, LOW);
    digitalWrite(PIN_SELECT_MINUTE, HIGH);
		
		digitalWrite(PIN_SELECT_HOUR, LOW);
		digitalWrite(PIN_SELECT_MINUTE, LOW);
	}

	void displayTime(int hour, int minute) {
		displayHour(hour);
		displayMinute(minute);

	}

private:
	NixieTubeDriver _tube_minute_upper;
	NixieTubeDriver _tube_minute_lower;
	NixieTubeDriver _tube_hour_upper;
	NixieTubeDriver _tube_hour_lower;
};
