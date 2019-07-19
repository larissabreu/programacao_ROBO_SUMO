#ifndef CONTROLLER
#define CONTROLLER

#include <stdint.h>
#include <Arduino.h>
#include <ServoTimer2.h>
#include "motor.h"

class Controller {
public:
   Motor motor1;
   Motor motor2;
   Controller();
   void write(int16_t x, int16_t y);
   void attach(int pin1, int pin2);
};

#endif
