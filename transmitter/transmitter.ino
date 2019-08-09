#include <RH_NRF24.h>
#include <SPI.h> // Not actually used but needed to compile
#include "remote_data.hpp"

#define DEBUG

const int analog_x = A0;
const int analog_y = A1;
const int vout = 7;
RH_NRF24 driver;

void setup() {
    pinMode(vout, OUTPUT);
    pinMode(analog_x, INPUT);
    pinMode(analog_y, INPUT);
#ifdef DEBUG
    Serial.begin(115200);
    if (!driver.init())
        Serial.println("init failed");
#else
        driver.init();
#endif
}

void loop() {
    uint8_t buffer[3];// armazena os bytes que serao enviados
    uint16_t x_axis = analogRead(analog_x);
    uint16_t y_axis = analogRead(analog_y);
    RemoteProtocolHandler data;

    data.write_payload(x_axis, y_axis);// escreve os dados
    data.write_to_byte_array(buffer);

#ifdef DEBUG
    print_data(buffer, 3);
#endif

    driver.send(buffer, 3);
    driver.waitPacketSent();
}

void print_data(uint8_t* buf, uint8_t size){
    for (uint8_t i = 0; i < size; i++){
        Serial.print(buf[i], HEX);
    }
    Serial.println();
}

