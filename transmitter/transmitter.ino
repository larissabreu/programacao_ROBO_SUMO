#include <VirtualWire.h>
#include "remote_data.hpp"
#define button_1 5
#define button_2 6
#define vin 7
const int analog_x = A0;
const int analog_y = A1;

void setup() {
  pinMode(vin, OUTPUT);
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(analog_x, INPUT);
  pinMode(analog_y, INPUT);
  Serial.begin(9600);
  vw_set_tx_pin(8);
  vw_setup(2000);   // Bits per sec
}

void loop() {
    digitalWrite(7,1);// gambiarra pq o corno do jamal fodeu com a porta de 5v
    RemoteData data;
    uint8_t buffer[3];// armazena os bytes que serao enviados
    uint16_t x_axis = analogRead(analog_x);
    uint16_t y_axis = analogRead(analog_y);
    data.write_payload(x_axis, y_axis);// escreve os dados
    data.write_to_byte_array(buffer);
    Serial.println((char*)buffer);
    send(buffer, 3);
}
void send (uint8_t *message, uint8_t len)
{
  vw_send((uint8_t *)message,len);
  vw_wait_tx(); // Aguarda o envio de dados
}
