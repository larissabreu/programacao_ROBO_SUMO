#include <iostream>
#include <cstdint>
#include <bitset>
#include "remote_data.hpp"


int main(){
    RemoteData d;
    RemoteData c;
    uint8_t buffer[3];
    c.write_payload(0x3ff, 0x2aa);
    c.write_to_byte_array(buffer);
    buffer[0] = 1;
    d.read_from_byte_array(buffer);
    std::cout << sizeof(RemoteData) << std::endl;
    if (d.is_valid())
        std::cout << std::hex << d.get_x() << std::endl << d.get_y() << std::endl ;
}
