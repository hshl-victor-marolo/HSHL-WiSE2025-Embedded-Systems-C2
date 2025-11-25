#include <Wire.h>

enum Leds {
  CAR_GREEN=11,
  CAR_YELLOW=12,
  CAR_RED=13,
  PEDESTRIAN_GREEN=9,
  PEDESTRIAN_RED=10
};

void setup()
{
  Wire.begin(); 
  pinMode(CAR_GREEN, OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_RED, OUTPUT);
  pinMode(5, INPUT_PULLUP);
}

void switch_led(int led) {
  switch (led) {
    case CAR_GREEN:
      digitalWrite(CAR_GREEN, 1);
      digitalWrite(CAR_YELLOW, 0);
      digitalWrite(CAR_RED, 0);
      break;
    case CAR_YELLOW:
      digitalWrite(CAR_GREEN, 0);
      digitalWrite(CAR_YELLOW, 1);
      digitalWrite(CAR_RED, 0);
      break;
    case CAR_RED:
      digitalWrite(CAR_GREEN, 0);
      digitalWrite(CAR_YELLOW, 0);
      digitalWrite(CAR_RED, 1);
      break;
    case PEDESTRIAN_GREEN:
      digitalWrite(CAR_GREEN, 0);
      digitalWrite(CAR_YELLOW, 0);
      digitalWrite(CAR_RED, 1);
      break;
    case PEDESTRIAN_RED:
      digitalWrite(CAR_GREEN, 0);
      digitalWrite(CAR_YELLOW, 0);
      digitalWrite(CAR_RED, 1);
      break;
  }

}


int button;
int last_button;
int state = CAR_GREEN;
int previous_state = 0;
int delay_count = 0;

void loop()
{
  int button = digitalRead(5);
  if (button == 0) {
     state = PEDESTRIAN_GREEN;
      previous_state = 0;
      delay_count = 0;
  }
  last_button = button;
  if (delay_count == 0) {
    Wire.beginTransmission(9);
    Wire.write(state);               
    Wire.endTransmission();    
    switch (state) {
      case CAR_GREEN:
        switch_led(state);        
        previous_state = state;
        state = CAR_YELLOW;
        delay_count = 50;
        break;
      case CAR_YELLOW:
        switch_led(state);
        if (previous_state == CAR_GREEN) {
          previous_state = state;
          state = CAR_RED;
        } else if (previous_state == PEDESTRIAN_RED) {
          previous_state = state;
          state = CAR_GREEN;
        }
        delay_count = 20;
        break;
      case CAR_RED:
        switch_led(state);
        previous_state = state;
        state = PEDESTRIAN_GREEN;
        delay_count = 20;
        break;
      case PEDESTRIAN_GREEN:
        switch_led(state);
        previous_state = state;
        state = PEDESTRIAN_RED;
        delay_count = 19;
        break;
      case PEDESTRIAN_RED:
        switch_led(state);
        previous_state = state;
        state = CAR_YELLOW;
        delay_count = 1;
        break;
    }
  } else {
    delay(50);
    delay_count -= 1;
  }

}
