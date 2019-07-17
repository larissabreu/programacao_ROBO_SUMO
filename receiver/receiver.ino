#include <ServoTimer2.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#include "remote_data.hpp"

//ServoTimer2 motor;
//ServoTimer2 motor1;

RH_ASK driver(4000);
RemoteProtocolHandler data;// Classe usada para manipular os bits recebidos

void setup() {
    //motor.attach(2); 
    //motor1.attach(3); 
    Serial.begin(9600);
    if (!driver.init())
         Serial.println("init failed");
}

void loop() {
    uint8_t buffer[4];// Armazena a mensagem recebida    
    uint8_t buf_length = 4;// Armazena a mensagem recebida    

    if (driver.recv(buffer, &buf_length)) {
        data.read_from_byte_array(buffer);// interpreta os bits recebidos 
        Serial.print("X: ");
        Serial.print(data.get_x(),HEX);
        Serial.print(" Y: ");
        Serial.println(data.get_y(),HEX);
    }  
}
