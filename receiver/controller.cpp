#include <SPI.h>

#include "controller.h"
#include "motor.h"
Controller :: Controller{};
void Controller:: write(int16_t x, int16_t y){
  
};
void Controller:: attach(int pin1, int pin2){
  motor1.attach(pin1);
  motor2.attach(pin2);
};
