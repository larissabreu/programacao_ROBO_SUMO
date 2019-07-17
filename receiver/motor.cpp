#include <SPI.h> // Not actualy used but needed to compile
#include "motor.h"
Motor:: Motor() : servo(){
}; 
void Motor :: move(int val){
	servo.write(map(val, -100, 100, 1300, 1700));
};
void Motor:: attach(int pin){
  servo.attach(pin);
};
