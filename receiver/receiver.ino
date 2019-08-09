#include <ServoTimer2.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#include "remote_data.hpp"
#include "motor.h"
#include "controller.h"
Controller control;
RH_ASK driver(4000);


void setup() {
    control.attach(2,3); 
    Serial.begin(9600);
    if (!driver.init())
         Serial.println("init failed");
}

void loop() {
    static uint16_t diff = 0;
    static uint16_t timer = millis();
    RemoteProtocolHandler data;// Classe usada para manipular os bits recebidos
    uint8_t buffer[4];// Armazena a mensagem recebida    
    uint8_t buf_length = 4;// Armazena a mensagem recebida    

    if (driver.recv(buffer, &buf_length)) {
        timer = millis();
        data.read_from_byte_array(buffer);// interpreta os bits recebidos 
        Serial.print("X: ");
        Serial.print(data.get_x(), DEC);
        Serial.print(" Y: ");
        Serial.println(data.get_y(), DEC);
        control.write(data.get_x(), data.get_y());
    }
    diff = millis() - timer;
    if ( diff > 200) {
         diff = 0;
         control.write(512,512);
    }
    
}
