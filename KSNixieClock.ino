/*
 Name:		KSNixieClock.ino
 Created:	1/10/2020 2:09:56 PM
 Author:	Kuangyuan
*/

//#include "NixieTubeDriver.h"
//#include "pin_definition.h"
#include "NixieClockDisplayDriver.h"

//NixieTubeDriver driver0(PIN_A, PIN_B, PIN_C, PIN_D);

NixieClockDisplayDriver clockDisplay;

void setup() {
	// put your setup code here, to run once:


}

void loop() {
	// put your main code here, to run repeatedly:
	for (int hour = 0; hour < 60; ++hour) {
		clockDisplay.displayHour(hour);
		for (int minute = 0; minute < 60; ++minute) {
			//clockDisplay.displayTime(hour, minute);
			clockDisplay.displayMinute(minute);
      //clockDisplay.displayHour(10 + minute % 10);
      delay(1000);
		}
   
	}
}
