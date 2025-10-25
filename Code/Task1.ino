// C++ code
//
void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
}


void switch_led_on(int led){
  switch (led){
    case 0:
    	digitalWrite(0, 1);
    	digitalWrite(1, 0);
    	digitalWrite(2, 0);
    	break;
    case 1:
    	digitalWrite(0, 0);
    	digitalWrite(1, 1);
    	digitalWrite(2, 0);
    	break;
    case 2:
        digitalWrite(0, 0);
    	digitalWrite(1, 0);
    	digitalWrite(2, 1);
    	break;
  }
}

int state = 0;
int previous_state = 0;

void loop()
{
  switch (state) {
    case 0:
    	switch_led_on(0);
    	previous_state = state;
    	state = 1;
    	break;
    case 1:
    	switch_led_on(1);
        if (previous_state == 0){
          previous_state = state;
          state = 2;
        } else if (previous_state == 2){
          previous_state = state;
          state = 0;
        }
    	break;
    case 2:
    	switch_led_on(2);
    	previous_state = state;
    	state = 1;
    	break;
  }
  delay(1000);
}
