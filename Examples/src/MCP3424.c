/*
 * MCP3424 ADC Library
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


/**** Please see Setup/Linux_Driver.md for configuration of ADC's on the System ****/

#include "MCP3424.h"

FILE * adc_fp;
int adc_fd;

void MCP3424Init(void) {

    //Code can be put here to set up ADC gain, etc.
    printf("ADC Modules Ready\n");

}

float MCP3424Read(int adc, int channel) {

    char filename[LEN];
    float adc_ret;

    snprintf(filename, LEN, "/dev/i2cadc%d/in_voltage%d_raw", adc, channel);
    adc_fp = fopen(filename,"r");
    fscanf(adc_fp,"%f",&adc_ret);
    fclose(adc_fp);
    return adc_ret;

}
