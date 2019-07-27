#include <ServoTimer2.h>
#include <RH_NRF24.h>
#include <SPI.h> // Not actualy used but needed to compile
#include "remote_data.hpp"
#include "motor.h"
#include "controller.h"

#define DEBUG

Controller control;
RH_NRF24 driver;
void setup() {
    control.attach(2,3); 
#ifdef DEBUG
    Serial.begin(9600);
    if (!driver.init())
         Serial.println("init failed");
#else
    driver.init()
#endif
}

void loop() {
    RemoteProtocolHandler data;// Classe usada para manipular os bits recebidos
    uint8_t buffer[4];// Armazena a mensagem recebida    
    uint8_t buf_length = 4;// Armazena a mensagem recebida    

    if (driver.recv(buffer, &buf_length)) {
        data.read_from_byte_array(buffer);// interpreta os bits recebidos 
#ifdef DEBUG
        Serial.print("X: ");
        Serial.print(data.get_x(), DEC);
        Serial.print(" Y: ");
        Serial.println(data.get_y(), DEC);
#endif
        if(data.is_valid())
            control.write(data.get_x(), data.get_y());
    }
}
