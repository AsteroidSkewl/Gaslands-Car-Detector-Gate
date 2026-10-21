#include <ABLocks_TimerFreeTone.h>

void setup()
{
  	pinMode(7, INPUT);
	pinMode(2, INPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(2, OUTPUT);

	digitalWrite(3, LOW);
	digitalWrite(4, LOW);
	digitalWrite(5, LOW);

}


void loop()
{

  	if (digitalRead(7)) {
  		if ((!digitalRead(2))) {
  			digitalWrite(3, LOW);
  			digitalWrite(4, HIGH);
  			TimerFreeToneRtttl(6,(const char *)String("s:d=4,o=5,b=200:c,g#,c,c#,d,d#,e,c,g#,c,c#,d,d#,e,c,g#,c,c#,d,d#,e").c_str());
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
  		TimerFreeTone(2,200,500);
  		digitalWrite(5, LOW);
  		digitalWrite(4, HIGH);
  		TimerFreeTone(2,200,500);
  		digitalWrite(4, LOW);
  		digitalWrite(3, HIGH);
  		TimerFreeTone(2,200,500);
  		delay(100000);
  	}

}