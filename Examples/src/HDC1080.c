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

#include "HDC1080.h"

int fdt;

void HDC1080_Init(void) {

	char *fileName = "/dev/i2c-1";								// Name of the port we will be using
	unsigned char buf[10];										// Buffer for data being read/ written on the i2c bus
	
	if ((fdt = open(fileName, O_RDWR)) < 0) {					// Open port for reading and writing
		printf("Failed to open i2c HDC1080 port\n");
		exit(1);
	}
	
	if (ioctl(fdt, I2C_SLAVE, HDC1080_ADD) < 0) {				// Set the port options and set the address of the device we wish to speak to
		printf("Unable to get bus access to talk to i2c HDC1080\n");
		exit(1);
	}
	
	buf[0] = 0x02;												// Commands to enable the sensor
	buf[1] = 0x00;
	
	if ((write(fdt, buf, 2)) != 2) {								// Write commands to the i2c port
		printf("Error writing to i2c HDC1080\n");
		exit(1);
	}
	
	usleep(HDC1080_DELAY);										// this sleep waits for the ping to come back
	
	buf[0] = 0xFE;
    buf[1] = 0x00;												// This is the register we wish to read from
	
	if ((write(fdt, buf, 2)) != 2) {							// Send register to read from
		printf("Error writing to i2c HDC1080\n");
		exit(1);
	}
	
	if (read(fdt, buf, 4) != 4) {								// Read back data into buf[]
		printf("Unable to read from i2c HDC1080\n");
		exit(1);
	}

    int man = (buf[1] << 8) + buf[0];

    if (man == 21577) {
        printf("HDC1080 Ready\n");   /*read manufacturer*/
    } else {
        printf("HDC1080 Config ERROR - %d\n", man);
    }

}

float HDC1080_Temp(void) {
	int temp;
	unsigned char buf[10];

	buf[0] = 0x00;												// This is the register we wish to read from
	
	if ((write(fdt, buf, 1)) != 1) {							// Send register to read from
		printf("Error writing to i2c HDC1080\n");
		exit(1);
	}

	delay(HDC1080_DELAY);   									// waiting for measurement

	if (read(fdt, buf, 4) != 4) {								// Read back data into buf[]
		printf("Unable to read from i2c HDC1080\n");
		exit(1);
	}

	temp = (buf[1] << 8) + buf[0];

  	return ((float)(temp)/(65536.0)*165.0-40.0);   				// converting reading to degrees celsius
}

float HDC1080_Hum(void) {
  	int humidity;
  	unsigned char buf[10];

	buf[0] = 0x01;												// This is the register we wish to read from
	
	if ((write(fdt, buf, 1)) != 1) {							// Send register to read from
		printf("Error writing to i2c HDC1080\n");
		exit(1);
	}

	delay(HDC1080_DELAY);   									// waiting for measurement

	if (read(fdt, buf, 4) != 4) {								// Read back data into buf[]
		printf("Unable to read from i2c HDC1080\n");
		exit(1);
	}

	humidity = (buf[1] << 8) + buf[0];

  	return ((float)(humidity)/(65536.0)*100.0);   				// converting reading to RH%
}
