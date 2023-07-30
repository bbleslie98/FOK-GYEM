#ifndef _DEMO_HEADER_
#define _DEMO_HEADER_

#include <Arduino.h>

#include "shiftRegister.h"
#include "driver.h"
#include "serialCom.h"


/*	DEMO CONFIG OPTIONS	*/
//Speedtest iteration count - amount of full screen write and clears
#define DEMOCFG_SPEEDTEST_ITER_CNT 6

//Specifies the delay between the periodic screen write/clears - miliseconds
#define DEMOCFG_PERIODICTEST_DELAY 2000

/**
 * @brief This function should be called in the Arduino main's loop() function.
 * Every DEMOCFG_PERIODICTEST_DELAY miliseconds clears or writes the full screen.
 * Useful for testing the hardware and pixels.
 */
void demo_periodicTest();

/**
 * @brief This function should be called only once, or on a command, or with a delay.
 * When it is called, performs full-speed series of screen clears and writes, without
 * any delay or pause.
 * The total clear-write periods are specified by the DEMOCFG_SPEEDTEST_ITER_CNT macro.
 * 
 */
void demo_speedTest();

/**
 * @brief This is an example illustrates how the Arduino main's setup() function should look like.
 * The driver's driver_init() function must be called ASAP during the initialization.
 * The serial communication feature is optional.
 * 
 */
void demo_setupExample();


/**
 * @brief If Serial Communication is used to control the content of the screen with an another device,
 * this is a recommended Arduino loop() function to handle the serial requests.
 */
void demo_serialLoop();

#endif