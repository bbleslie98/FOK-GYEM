#include <Arduino.h>
#include <SPI.h>

//Custom files
#include "shiftRegister.h"
#include "driver.h"
#include "serialCom.h"

uint8_t buff[DRV_DATABUFF_SIZE] = {0};

void setup() {
    /*
    sCom_init(&Serial, 115200);
    driver_init();
    memset(buff, 0, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_forceWriteScreen();*/
    SPI.begin();
    SPISettings spiset = SPISettings(2000000, MSBFIRST, SPI_MODE0);
    SPI.beginTransaction(spiset);
}

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

void serialCom() {
    sCom_waitForData(buff, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_writeScreen();
    Serial.println("print_finished");
}

void loop() {
    noInterrupts();
    PORTB |= (1<<2);
    SPI.transfer(0x01);
    PORTB &= ~(1<<2);
    _NOP;
    PORTB |= (1<<2);
    SPI.transfer(0xFF);
    PORTB &= ~(1<<2);
    _NOP; _NOP;
    PORTB |= (1<<2);
    SPI.transfer(0x80);
    PORTB &= ~(1<<2);
    _NOP; _NOP; _NOP;
    PORTB |= (1<<2);
    SPI.transfer(0x00);
    PORTB &= ~(1<<2);
    interrupts();
    delay(100);
    
}