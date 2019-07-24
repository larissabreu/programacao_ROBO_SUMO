#include <SPI.h>

#include "controller.h"
#include "motor.h"
Controller :: Controller(){}
void Controller:: write(int16_t x, int16_t y){ 
  Motor_Values aux;
  aux.rigth = aux.left = map(y, 0, 1023, MIN_FORWARD_SPEED, MAX_FORWARD_SPEED);
  if( x < 512){
    if( y < 512){
      aux.left = (aux.left * map(x, 0, 512, 0, 50))/50;
    }
    if( y >= 512){
      aux.left = (aux.left * map(x, 512, 1023, 50, 0))/50;
    }
  }else if( x >= 512){
    if( y < 512){
      aux.rigth = (aux.rigth * map(x, 0, 512, 0, 50))/50;
    }
    if( y >= 512){
      aux.rigth = (aux.rigth * map(x, 512, 1023, 50, 0))/50;
    }
  }
  motor1.move(aux.rigth);
  motor2.move(aux.left);
};
void Controller:: attach(int pin1, int pin2){
  motor1.attach(pin1);
  motor2.attach(pin2);
};
