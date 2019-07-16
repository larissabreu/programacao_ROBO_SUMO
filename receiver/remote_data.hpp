#ifndef REMOTE_DATA
#define REMOTE_DATA

#include <stdint.h>

#define BitsOn(x,m) (x |= m)
#define BitsAt(x,m) (x & m)
#define BitsLShiftOn(x,m,s) (x |= ((uint32_t)m << s))
#define BitsDoubleShiftMask(x,m,s) ((x & (uint32_t)m << s) >> s)

namespace Protocol{
    const uint32_t START = 31;
    //#define PARITY (0x << 11)
    const uint32_t STOP = 8;
    const uint8_t X = 21;
    const uint8_t Y = 11;
    const uint8_t FIRST  = 24;
    const uint8_t SECOND = 16;
    const uint8_t THIRD  = 8;
}


class RemoteProtocolHandler {
private:
public:
    uint32_t data;//<* holds the data, only the firstmost 24 bits are used
    RemoteProtocolHandler();//<* initializes data START and STOP bits
    RemoteProtocolHandler(uint16_t x, uint16_t y);//<* initializes every bit necessary
    void write_payload(uint16_t x, uint16_t y);//<* writes the coordinates to data and properly shifts it
                                               //<* \param x 10bits X coordinates
                                               //<* \param y 10bits Y coordinates
    uint16_t get_x();
    uint16_t get_y();
    void write_to_byte_array(uint8_t arr[3]);//<* writes data to a pre-allocated byte array,
                                             //<* used to send data through rf
                                             //<* \param arr 3 byte array 

    void read_from_byte_array(uint8_t arr[3]);//<* reads data from a pre-allocated byte array
                                              //<* used to read data through rf
                                              //<* \param arr 3 byte array 
    bool is_valid();
};

#endif
