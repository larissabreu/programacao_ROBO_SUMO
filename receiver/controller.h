#ifndef CONTROLLER
#define CONTROLLER
#include <stdint.h>
#include <Arduino.h>
#include <ServoTimer2.h>
#include "motor.h"

#define MAX_FORWARD_SPEED 2000
#define MIN_FORWARD_SPEED 1000


struct Motor_Values{
  uint16_t left, rigth;
};
 
class Controller {
public:
   Motor motor1;
   Motor motor2;
   Controller();
   void write(int16_t x, int16_t y);
   void attach(int pin1, int pin2);
};

#endif
