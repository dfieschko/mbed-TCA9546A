#ifndef _TCA9546A_H
#define _TCA9546A_H

#include "mbed.h"

/** List of channels w/ corresponding int ids */
        enum Channel
        {
            CHAN0 = 0,
            CHAN1 = 1,
            CHAN2 = 2,
            CHAN3 = 3
        };

class TCA9546A
{
    public:
        /** Constructor.
         * @param i2c_set mbed I2C class
         * @param addr_set I2C address - range 0x70 to 0x77 - 0x70 default
         * @param reset_pin mbed device DigitalOut reset pin - NC default
         */
        TCA9546A( I2C * i2c_set,
                  uint8_t addr_set = 0x70,
                  DigitalOut * resetOut = NULL );
                  
        /** Destructor */
        ~TCA9546A();
        
        /** Resets the TCA9546A by setting the active-low reset pin low. 
         *  This deselects all channels.
         */
        void reset();
        
        /**
         * @param channel the channel to switch to
         * @returns what the i2c write function returns (0 on success, non-0 on failure)
         * @note This turns on the specified channel and turns all other channels off. 
         */
        int setChannel( Channel chan_set );
        
        /**
         * @returns current channel, or -1 if no channel is enabled
         */
        int8_t getChannel() { return channel; }
        
    private:
        I2C * i2c;
        uint8_t address;
        DigitalOut * reset_pin;
        int8_t channel;
};

#endif