#include <ServoTimer2.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#include "remote_data.hpp"
#include "motor.h"
Controller control;
RH_ASK driver(4000);
void setup() {
    control.attach(2,3); 
    Serial.begin(9600);
    if (!driver.init())
         Serial.println("init failed");
}

void loop() {
    RemoteProtocolHandler data;// Classe usada para manipular os bits recebidos
    uint8_t buffer[4];// Armazena a mensagem recebida    
    uint8_t buf_length = 4;// Armazena a mensagem recebida    

    if (driver.recv(buffer, &buf_length)) {
        data.read_from_byte_array(buffer);// interpreta os bits recebidos 
        Serial.print("X: ");
        Serial.print(data.get_x(), DEC);
        Serial.print(" Y: ");
        Serial.println(data.get_y(), DEC);
        control.write(map(data.get_x(),0,1023,-100,100), map(data.get_y(),0,1023,-100,100));
    }
}
