#include <Arduino.h>
#include "demo.h"


void setup() {
    demo_setupExample();
}

//#define PERIODIC_TEST
//#define SPEED_TEST

bool hasrun = false;

void loop() {

    demo_serialLoop();

}