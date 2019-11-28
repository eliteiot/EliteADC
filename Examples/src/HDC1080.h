/*
 * HDC1080 Library
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

#ifndef HDC1080_H
#define HDC1080_H

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define HDC1080_ADD     0x40
#define HDC1080_DELAY   50000

void HDC1080_Init(void);
float HDC1080_Temp(void);
float HDC1080_Hum(void);

#endif // HDC1080_H
