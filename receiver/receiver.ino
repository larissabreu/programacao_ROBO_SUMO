#include <VirtualWire.h>
#include "remote_data.hpp"
byte message[VW_MAX_MESSAGE_LEN];    // Armazena as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Armazena o tamanho das mensagens

void setup() {
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
        Serial.print("X_axis: ");
        Serial.print(data.get_x());
        Serial.print("Y_axis: ");
        Serial.println(data.get_y());
    }  
}
