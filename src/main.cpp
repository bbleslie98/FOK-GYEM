#include <Arduino.h>
#define TEST

//Custom files
#include "shiftRegister.h"
#include "driver.h"
#include "serialCom.h"

uint8_t buff[DRV_DATABUFF_SIZE] = {0};

void periodicTest() {
    memset(buff, 0x00, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_writeScreen();
    delay(2000);
    memset(buff, 0xFF, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_writeScreen();
    delay(2000);
}

void speedTest() {
    for (size_t i = 0; i < 6; i++) {
        memset(buff, 0xFF, DRV_DATABUFF_SIZE);
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
        memset(buff, 0x00, DRV_DATABUFF_SIZE);
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
        
    }    
}

void setup() {
    sCom_init(&Serial, 115200);
    driver_init();
    memset(buff, 0, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_forceWriteScreen();
}

//#define PERIODIC_TEST
//#define SPEED_TEST

bool hasrun = false;

void loop() {
    
    //The mode can be selected using a define above
    #if defined(SPEED_TEST)
        //After reset, performs a full speed forced full screen set-clear writes 6 times.
        if(!hasrun) {
        hasrun = true;
        speedTest();
        }
    #elif defined(PERIODIC_TEST)
        //Changes the screen between full colors every 2 seconds.
        periodicTest();
    #else
        //Driver using SerialCom to update screen data

        sCom_waitForData(buff, DRV_DATABUFF_SIZE);
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
        while(Serial.available()) { //Remove any remaining or corrupted serial data from the buffer
            Serial.read();
        }
        //The host must send the data after receiving the 'OK' acknowledge message from the driver.
        //The message is reduced, requires less time to trasmit, this improves the latency.
        Serial.println("OK");
    #endif

}