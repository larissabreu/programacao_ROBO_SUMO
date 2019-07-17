#include "remote_data.hpp"

RemoteProtocolHandler::RemoteProtocolHandler() {
    data = 0;
    BITS_SET(data, 3, Protocol::STOP);
}

RemoteProtocolHandler::RemoteProtocolHandler(uint16_t x, uint16_t y) {
    data = 0;
    BITS_SET(data, x, Protocol::X);
    BITS_SET(data, y, Protocol::Y);
    BITS_SET(data, 3, Protocol::STOP);
}

void RemoteProtocolHandler::write_payload(uint16_t x, uint16_t y){
    if (x > 1023 || y > 1023) {
        x = y = 512;
    }
    BITS_WRITE(data, x, 10, Protocol::X);
    BITS_WRITE(data, y, 10, Protocol::Y);
}

uint16_t RemoteProtocolHandler::get_x(){
    return BITS_VALUE_AT(data, 10, Protocol::X);
}

uint16_t RemoteProtocolHandler::get_y(){
    return BITS_VALUE_AT(data, 10, Protocol::Y);
}

void RemoteProtocolHandler::write_to_byte_array(uint8_t arr[3]){
    arr[0] = BITS_VALUE_AT(data, 8, Protocol::FIRST);
    arr[1] = BITS_VALUE_AT(data, 8, Protocol::SECOND);
    arr[2] = BITS_VALUE_AT(data, 8, Protocol::THIRD);
}

void RemoteProtocolHandler::read_from_byte_array(uint8_t arr[3]){
    BITS_SET(data, arr[0], Protocol::FIRST); 
    BITS_SET(data, arr[1], Protocol::SECOND);
    BITS_SET(data, arr[2], Protocol::THIRD); 
}

bool RemoteProtocolHandler::is_valid(){
    return !BITS_AT(data,1 << Protocol::START) and BITS_AT(data,3 << Protocol::STOP) == 3 << Protocol::STOP;
}

