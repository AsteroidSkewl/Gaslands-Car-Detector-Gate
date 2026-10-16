#include <ABLocks_TimerFreeTone.h>

void setup()
{
  	pinMode(2, INPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(5, OUTPUT);

	digitalWrite(3, LOW);
	digitalWrite(4, LOW);
	digitalWrite(5, HIGH);

}


void loop()
{

  	if (digitalRead(2)) {
  		if ((!digitalRead(2))) {
  			digitalWrite(3, LOW);
  			digitalWrite(4, HIGH);
  			TimerFreeToneRtttl(6,(const char *)String("RickRoll:d=4,o=5,b=114:64c5,16p,64c5,16p,64c5,16p,64c5,16p,64a4,16a#3,64a4,64a#3,32g#3.,64p,64f4,32f#3.,64p,64f4,16f3,64p,4c#7,64p,16c#7.,64p,2d#7,8g#6,4d#7.,4f7.,64p,16g#7,16f#7,16f7,4c#7.,32c#7.,4d#7,64p,16d#7.,64p,2g#6.,32c#7,32g#6,32c#7,16g#6.,32c#7,32g#6,32c#7,32g#6,32c#7,32g#6,32c#7,32g#6,32c#7,64g#6,32p,4c#7,64p,16c#7.,64p,2d#7,8g#6,4d#7.,4f7.,64p,16g#7,16f#7,16f7,4c#7.,32c#7.,4d#7,64p,16d#7.,64p,2g#6.,32c#7,32g#6,32c#7,16g#6.,32c#7,32g#6,32c#7,32g#6,32c#7,32g#6,32c#7,32g#6,32c#7,64g#6").c_str());
  			delay(2000);
  			digitalWrite(4, LOW);
  			digitalWrite(5, HIGH);
  		}
  		else if (digitalRead(2)) {
  			digitalWrite(5, LOW);
  			digitalWrite(4, LOW);
  			digitalWrite(3, HIGH);
  		}

  	}
  	else {
  		delay(5000);
  		tone(6,200);
  		delay(200);
  		noTone(6);
  		digitalWrite(5, LOW);
  		digitalWrite(4, HIGH);
  		tone(6,200);
  		delay(200);
  		noTone(6);
  		digitalWrite(4, LOW);
  		digitalWrite(3, HIGH);
  		tone(6,600);
  		delay(200);
  		noTone(6);
  		delay(10000000);
  	}

}