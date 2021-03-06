#include <Arduino.h>

//Custom files
#include "shiftRegister.h"
#include "driver.h"

uint8_t data[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0xe7,   0x1c, 0x38, 0x70, 0xe1, 0x00, 0x00, 0x00,   
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x22,   0x22, 0x44, 0x89, 0x13, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x42,   0x20, 0x04, 0x98, 0x11, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x82,   0x2e, 0x08, 0xa8, 0x21, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x02,   0x22, 0x10, 0xc8, 0x41, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x02,   0x22, 0x20, 0x88, 0x81, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00, 0x00, 0x00, 0x00, 0x01, 0xe3, 0xe7,   0x1e, 0x7c, 0x71, 0xf3, 0x80, 0x00, 0x00
    };
uint8_t data2[] = { 
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0xFF, 0x00, 0xFF, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0xFF, 0x00, 0xFF,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0x00, 0xFF, 0x00, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0xFF, 0x00,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0xFF, 0x00, 0xFF, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0xFF, 0x00, 0xFF,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,   0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F
};
void setup() {
    driver_init();
}

void loop() {
    uint8_t buff[DRV_DATABUFF_SIZE];
    while(true) {

        driver_setBuffer(data, DRV_DATABUFF_SIZE);  //SZIG normal
        driver_writeScreen();
        delay(2000);

        for(uint8_t i = 0; i <DRV_DATABUFF_SIZE; i++) {
            buff[i] = 0x00;
        }
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
        delay(2000);

        for(uint8_t i = 0; i < DRV_DATABUFF_SIZE; i++) {
            buff[i] = ~data[i];
        }
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
        delay(2000);

        for(uint8_t i = 0; i <DRV_DATABUFF_SIZE; i++) {
            buff[i] = 0xFF;
        }
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
        delay(2000);

        for(uint8_t i = 0; i <DRV_DATABUFF_SIZE; i++) {
            buff[i] = 0xAA;
        }
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
        
        for(uint8_t i = 0; i <DRV_DATABUFF_SIZE; i++) {
            buff[i] = 0x55;
        }
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
    }
}