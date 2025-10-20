// C++ code
//

enum Leds {
  CAR_GREEN,
  CAR_YELLOW,
  CAR_RED,
  PEDESTRIAN_GREEN,
  PEDESTRIAN_RED
};

void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT_PULLUP);
}

void switch_led(int led){
  switch (led){
    case 0:
    	digitalWrite(CAR_GREEN, 1);
    	digitalWrite(CAR_YELLOW, 0);
    	digitalWrite(CAR_RED, 0);
      digitalWrite(PEDESTRIAN_GREEN, 0);
      digitalWrite(PEDESTRIAN_RED, 1);
    	break;
    case 1:
    	digitalWrite(CAR_GREEN, 0);
    	digitalWrite(CAR_YELLOW, 1);
    	digitalWrite(CAR_RED, 0);
      digitalWrite(PEDESTRIAN_GREEN, 0);
      digitalWrite(PEDESTRIAN_RED, 1);
    	break;
    case 2:
    	digitalWrite(CAR_GREEN, 0);
    	digitalWrite(CAR_YELLOW, 0);
    	digitalWrite(CAR_RED, 1);
      digitalWrite(PEDESTRIAN_GREEN, 1);
      digitalWrite(PEDESTRIAN_RED, 0);
    	break;
  }

}


int button;
int last_button;
int state = 0;
int previous_state = 0;
int delay_count = 0;

void loop()
{
 int button = digitalRead(5);
  if(button == 0){
    if(state != 2){
      state = 1;
      previous_state = 0;
      delay_count = 0;
    }
    
  }
  last_button = button;
  if(delay_count == 0){
    switch (state) {
      case CAR_GREEN:
        switch_led(state);
        previous_state = state;
        state = 1;
        delay_count = 20;
        break;
      case CAR_YELLOW:
        switch_led(state);
        if (previous_state == 0){
          previous_state = state;
          state = 2;
        } else if (previous_state == 2){
          previous_state = state;
          state = 0;
        }
        delay_count = 10;
        break;
      case CAR_RED:
        switch_led(state);
        previous_state = state;
        state = 1;
        delay_count = 20;
        break;
    }
  } else {
    delay(100);
    delay_count -= 1;
  }
  
}
