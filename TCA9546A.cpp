#include "TCA9546A.h"

TCA9546A::TCA9546A( I2C * i2c_set, uint8_t addr_set, PinName reset ): reset_pin(reset)
{
    channel = -1;  //signifies no channel is open
    i2c = i2c_set;
    reset_pin = 1; //reset pin is active low, so pull it high
}

TCA9546A::~TCA9546A()
{
    
}

void TCA9546A::reset()
{
    reset_pin = 0;
    wait_us(100); //datasheet says it'll be effective after 6ns, but 100us to be safe
    reset_pin = 1;
    channel = -1;
}

int TCA9546A::setChannel(Channel chan)
{
    channel = chan;
    char buff = 1 << channel; //high bit [channel num] to the left
    return i2c->write( address << 1, &buff, 1);
}
