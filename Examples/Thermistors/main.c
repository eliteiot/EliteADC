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

#include "../src/HDC1080.h"
#include "../src/MCP3424.h"

#define ADC_BITS        4096
#define R1              100000.0
#define C1              1.009249522e-03
#define C2              2.378405444e-04
#define C3              2.378405444e-04



int main(int argc, char *argv[])
{
    
    HDC1080_Init();
    MCP3424Init();

    printf("Temperature of Board : %.2f\n", HDC1080_Temp());
    printf("Humidity of Board : %.2f\n", HDC1080_Hum());
    printf("\n");



    for (int i = 0; i < ADC_CHANNELS; i++)
    {
        float adc_reading = MCP3424Read(ADC_2, i);
        float r2, log_r2, T, Tc, Tf;

        r2 = R1 * (ADC_BITS / adc_reading - 1.0);
        log_r2 = log(r2);
        T = (1.0 / (C1 + C2*log_r2 + C3*log_r2*log_r2*log_r2));
        Tc = T - 273.15;

        printf("Temp %d : %.3f degC  -  ADC Raw val : %.3f\n", i, Tc, adc_reading);
    }
    
    return 0;
}