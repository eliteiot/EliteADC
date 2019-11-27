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


#ifndef MCP3424_H
#define MCP3424_H

#include <stdio.h>
#include <stdlib.h>

#define NUM_ADCS            2
#define ADC_1               0
#define ADC_2               1

#define ADC_CHANNELS        4
#define LEN                 256

void MCP3424Init(void);
float MCP3424Read(int adc, int channel);

#endif // MCP3424_H
