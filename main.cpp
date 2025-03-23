/*
Filename: main.cpp
Description: Prints to the serial output the temperature sensor continously
Author: A Redfern
Date: 20/02/2025
Input/Output: 
Version: 01.00
Change log: 01.00 - Initial issue
*/
 
#include "mbed.h"
 
AnalogIn TempSensor(A1);
UnbufferedSerial uartUsb(USBTX, USBRX, 115200);
float Tempreading; 
 
int main()
{

    while( true ) {
    char str[10] = "";
             Tempreading = TempSensor.read()*330;
                str[0] = '\0';
                sprintf ( str, "Temperature reading: %.2f\u00B0C\r\n", Tempreading);
                uartUsb.write( str, strlen(str) );
                ThisThread::sleep_for(200);
   
    }
}
 