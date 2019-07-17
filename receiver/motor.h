#ifndef MOTOR
#define MOTOR

#include <stdint.h>
#include <Arduino.h>
#include <ServoTimer2.h>

class Motor {
public:
   ServoTimer2 servo;
   Motor();
   void move(int val);
   void attach(int pin);
};

#endif
