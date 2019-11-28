#
# MCP3424 ADC Example Makefile
#
# Copyright (c) 2019 Rob Brown - Elite Engineering WA.
# This is distributed as a way to use the 
# ADC Input 18bit 8ch IIOT Module - https://www.elitewa.com.au/adc-input-board.html
# 
# This is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# in the main directoy of this repository.
# If not, see <http://www.gnu.org/licenses/>.
#

DEFINES=-DRPI3

CC=gcc
CFLAGS=-c -Wall -O2 -Werror=switch
LDFLAGS=-lm
SOURCES=main.c ../src/HDC1080.c ../src/MCP3424.c
OBJDIR=obj
OBJECTS=$(SOURCES:%.c=$(OBJDIR)/%.o)
EXECUTABLE=Thermistor

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -g $(addprefix $(OBJDIR)/,$(notdir $(OBJECTS))) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	$(CC) -g $(CFLAGS) $(DEFINES) $< -o $(OBJDIR)/$(notdir $@)

clean:
	rm -f $(addprefix $(OBJDIR)/,$(notdir $(OBJECTS))) $(EXECUTABLE)
