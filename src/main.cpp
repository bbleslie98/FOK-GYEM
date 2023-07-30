#include <Arduino.h>
#define TEST

//Custom files
#include "shiftRegister.h"
#include "driver.h"
#include "serialCom.h"

uint8_t buff[DRV_DATABUFF_SIZE] = {0};

void fullTest() {
    memset(buff, 0x00, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_writeScreen();
    delay(1000);
    memset(buff, 0xFF, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_writeScreen();
    delay(1000);
}

void setup() {
    sCom_init(&Serial, 115200);
    driver_init();
    memset(buff, 0, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_forceWriteScreen();
}

//#define TEST

void loop() {
    
    #ifndef TEST
    sCom_waitForData(buff, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_writeScreen();
    while(Serial.available()) { //Remove any remaining or corrupted serial data from the buffer
        Serial.read();
    }
   Serial.println("print_finished");
   #else

   while(true) {
        fullTest();
   }

   #endif
}