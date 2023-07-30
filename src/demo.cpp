#include "demo.h"

//Local buffer for the data
uint8_t buff[DRV_DATABUFF_SIZE] = {0};


void demo_periodicTest() {
    memset(buff, 0x00, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_writeScreen();
    delay(DEMOCFG_PERIODICTEST_DELAY);
    memset(buff, 0xFF, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_writeScreen();
    delay(DEMOCFG_PERIODICTEST_DELAY);
}


void demo_speedTest() {
    for (size_t i = 0; i < DEMOCFG_SPEEDTEST_ITER_CNT; i++) {
        memset(buff, 0xFF, DRV_DATABUFF_SIZE);
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
        memset(buff, 0x00, DRV_DATABUFF_SIZE);
        driver_setBuffer(buff, DRV_DATABUFF_SIZE);
        driver_writeScreen();
        
    }    
}

void demo_setupExample() {
    //Driver init must be called ASAP
	driver_init();
	//Initializes the Serial Communication (optional)
    sCom_init(&Serial, 115200);

	//Forced screen clear
    memset(buff, 0, DRV_DATABUFF_SIZE);
    driver_setBuffer(buff, DRV_DATABUFF_SIZE);
    driver_forceWriteScreen();
}

void demo_serialLoop() {
	//Wait until all the screen data arrives on the serial line
	sCom_waitForData(buff, DRV_DATABUFF_SIZE);
	//Write all received information to the screen
	driver_setBuffer(buff, DRV_DATABUFF_SIZE);
	driver_writeScreen();
	//Remove any remaining or corrupted serial data from the buffer
	while(Serial.available()) {
		Serial.read();
	}
	//After the serial buffer is empty, the Arduino signals that it is ready to receive data again
	//This is done by transmitting an 'OK'
	Serial.println("OK");
	//The host must send the data after receiving the 'OK' acknowledge message from the driver.
}