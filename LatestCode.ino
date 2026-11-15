#include <ABLocks_TimerFreeTone.h>

boolean b_Stop;
boolean b_Go;

void STOP() {
	while (digitalRead(9)) {
		Serial.println(String("S1"));
		if ((!digitalRead(2))) {
			digitalWrite(3, LOW);
			digitalWrite(4, HIGH);
			TimerFreeToneRtttl(6,(const char *)String("s:d=4,o=5,b=200:c,g#,c,c#,d,d#,e,c,g#,c,c#,d,d#,e,c,g#,c,c#,d,d#,e").c_str());
			delay(2000);
			digitalWrite(4, LOW);
			digitalWrite(5, HIGH);
		}

		b_Stop = false;
	}
}
void GO_() {
	while ((!digitalRead(9))) {
		Serial.println(String("S2"));
	}
}

void setup()
{
  	pinMode(9, INPUT);
	pinMode(2, INPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(11, INPUT);

	Serial.begin(9600);
	Serial.flush();
	while(Serial.available()>0)Serial.read();

	digitalWrite(3, LOW);
	digitalWrite(4, LOW);
	digitalWrite(5, HIGH);
	b_Go = true;
	b_Stop = false;

}


void loop()
{

  	if (((!digitalRead(9)) && b_Go)) {
  		delay(5000);
  		digitalWrite(5, HIGH);
  		TimerFreeTone(6,200,500);
  		digitalWrite(5, LOW);
  		delay(200);
  		digitalWrite(4, HIGH);
  		TimerFreeTone(6,200,500);
  		digitalWrite(4, LOW);
  		delay(200);
  		digitalWrite(3, HIGH);
  		TimerFreeTone(6,500,500);
  		b_Go = false;
  		b_Stop = true;
  	}

  	if ((b_Stop && ((!digitalRead(11)) && digitalRead(9)))) {
  		digitalWrite(3, LOW);
  		digitalWrite(4, HIGH);
  		TimerFreeToneRtttl(6,(const char *)String("s:d=4,o=5,b=200:c,g#,c,c#,d,d#,e,c,g#,c,c#,d,d#,e,c,g#,c,c#,d,d#,e").c_str());
  		delay(2000);
  		digitalWrite(4, LOW);
  		digitalWrite(5, HIGH);
  		b_Stop = false;
  	}

}