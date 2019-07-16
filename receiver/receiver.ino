#include <VirtualWire.h>
#include <ServoTimer2.h>
#include "remote_data.hpp"
byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens
ServoTimer2 motor;
ServoTimer2 motor1;

void setup() {
    motor.attach(2); 
    motor1.attach(3); 
    Serial.begin(9600);
    vw_set_rx_pin(5); 
    vw_setup(2000); // Bits por segundo
    vw_rx_start();           
}

void loop() {
    RemoteProtocolHandler data;// Classe usada para manipular os bits recebidos
    uint8_t buffer[3];// Armazena a mensagem recebida    

    if (vw_get_message(message, &msgLength)) {
        for (int i = 0; i < 3; i++){// copia a mensagem para o buffer
            buffer[i] = message[i];
        }
        data.read_from_byte_array(buffer);// interpreta os bits recebidos 
        motor.write(map(data.get_x(),0,1023,1310, 1690));
        motor1.write(map(data.get_y(),0,1023,1310, 1690));
        Serial.println(data.get_x(),HEX);
    }  
}
