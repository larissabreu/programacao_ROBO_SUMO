#include <SPI.h> // Not actualy used but needed to compile
#include "motor.h"
Motor:: Motor() : servo(){
}; 
void Motor :: move(int val){
	servo.write(val);
};
void Motor:: attach(int pin){
  servo.attach(pin);
};
