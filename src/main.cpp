#include <Arduino.h>

//Custom files
#include "shiftRegister.h"
#include "driver.h"
#include "serialCom.h"

void setup() {
    sCom_init(&Serial, 115200);
    driver_init();
}

void loop() {
    uint8_t buff[DRV_DATABUFF_SIZE];
    
    sCom_waitForData(buff, DRV_DATABUFF_SIZE);
    
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_writeScreen();
}