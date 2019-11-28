/*
 * ADC Input 18bit 8ch IIOT Module
 * Thermistor Example code
 *
 * Copyright (c) 2019 Rob Brown - Elite Engineering WA.
 * This is distributed as a way to use the 
 * ADC Input 18bit 8ch IIOT Module - https://www.elitewa.com.au/adc-input-board.html
 * 
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * in the main directoy of this repository.
 * If not, see <http://www.gnu.org/licenses/>.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#include "../src/HDC1080.h"
#include "../src/MCP3424.h"

#define ADC_BITS            16384                       // ADC set to 14bit Resolution (60 samples per second)
#define R1                  100000.0                    // External resistor value
#define THERMISTOR          100000.0                    // Thermistor resistance
#define TEMPNOMINAL         25                          // Thermistor calibration temp
#define BCOEFFICIENT        3950


int main(int argc, char *argv[])
{
    
    HDC1080_Init();
    MCP3424Init();

    printf("Temperature of Board : %.2f\n", HDC1080_Temp());
    printf("Humidity of Board : %.2f\n", HDC1080_Hum());
    printf("\n");



    for (int i = 0; i < ADC_CHANNELS; i++)
    {
        float adc_reading = R1 / (ADC_BITS / MCP3424Read(ADC_2, i) - 1.0);
        
        float steinhart;
        steinhart = adc_reading / THERMISTOR;        // (R/Ro)
        steinhart = log(steinhart);                  // ln(R/Ro)
        steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
        steinhart += 1.0 / (TEMPNOMINAL + 273.15);   // + (1/To)
        steinhart = 1.0 / steinhart;                 // Invert
        steinhart -= 273.15;                         // convert to C

        printf("Temp %d : %.3f degC  -  ADC Raw val : %.3f\n", i, steinhart, adc_reading);
    }
    
    return 0;
}