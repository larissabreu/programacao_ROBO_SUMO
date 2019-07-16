#include "remote_data.hpp"

RemoteProtocolHandler::RemoteProtocolHandler() {
    data = 0;
    BitsLShiftOn(data, 1, Protocol::START);
    BitsLShiftOn(data, 3, Protocol::STOP);
    //BitsLShiftOn(data, 1, 10)
}

RemoteProtocolHandler::RemoteProtocolHandler(uint16_t x, uint16_t y) {
    data = 0;
    BitsLShiftOn(data, x, Protocol::X);
    BitsLShiftOn(data, y, Protocol::Y);
    BitsLShiftOn(data, 3, Protocol::STOP);
    //BitsLShiftOn(data, 1, 10)
}

void RemoteProtocolHandler::write_payload(uint16_t x, uint16_t y){
    if (x > 1023 || y > 1023) {
        x = y = 512;
    }
    BitsLShiftOn(data, x, Protocol::X);
    BitsLShiftOn(data, y, Protocol::Y);
}

uint16_t RemoteProtocolHandler::get_x(){
    return BitsDoubleShiftMask(data, 0x3ff, 21);
}

uint16_t RemoteProtocolHandler::get_y(){
    return BitsDoubleShiftMask(data, 0x3ff, 11);
}

void RemoteProtocolHandler::write_to_byte_array(uint8_t arr[3]){
    arr[0] = BitsDoubleShiftMask(data, 0xff, Protocol::FIRST);
    arr[1] = BitsDoubleShiftMask(data, 0xff, Protocol::SECOND);
    arr[2] = BitsDoubleShiftMask(data, 0xff, Protocol::THIRD);
}

void RemoteProtocolHandler::read_from_byte_array(uint8_t arr[3]){
    BitsLShiftOn(data, arr[0], Protocol::FIRST); 
    BitsLShiftOn(data, arr[1], Protocol::SECOND);
    BitsLShiftOn(data, arr[2], Protocol::THIRD); 
}

bool RemoteProtocolHandler::is_valid(){
    return !BitsAt(data,1 << Protocol::START) and BitsAt(data,3 << Protocol::STOP) == 3 << Protocol::STOP;
}

