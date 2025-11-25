// Include the required Wire library for I2C<br>
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
  pinMode(PEDESTRIAN_GREEN, OUTPUT);
  pinMode(PEDESTRIAN_RED, OUTPUT);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
}

void switch_led(int led) {
  switch (led) {
    case CAR_GREEN:
      digitalWrite(PEDESTRIAN_GREEN, 0);
      digitalWrite(PEDESTRIAN_RED, 1);
      break;
    case CAR_YELLOW:
      digitalWrite(PEDESTRIAN_GREEN, 0);
      digitalWrite(PEDESTRIAN_RED, 1);
      break;
    case CAR_RED:
      digitalWrite(PEDESTRIAN_GREEN, 0);
      digitalWrite(PEDESTRIAN_RED, 1);
      break;
    case PEDESTRIAN_GREEN:
      digitalWrite(PEDESTRIAN_GREEN, 1);
      digitalWrite(PEDESTRIAN_RED, 0);
      break;
    case PEDESTRIAN_RED:
      digitalWrite(PEDESTRIAN_GREEN, 0);
      digitalWrite(PEDESTRIAN_RED, 1);
      break;
  }

}

int state = 0;
int previous_state = 0;

void receiveEvent(int bytes) {
  state = Wire.read();    // read one character from the I2C
}

void loop()
{
    if(state!= previous_state){
      switch_led(state);
      previous_state = state;
    }
}
