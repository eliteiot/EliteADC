
# Thermistor Example

This Example will read 4x Thermistors on ADC2 and print out the temperatures on the console.

Parts required
* ADC Input 18bit 8ch IIOT Module
* Raspberry Pi
* 100k Thermistors (can be another value but THERMISTOR define will need to be changed to suit)
* 100k Resistor (can also be changed but R1 define will also need to be changed to suit)



## Clone the repo
Then to clone the git repo onto your computer

    cd ~
    git clone https://github.com/eliteiot/EliteADC.git

Build the Example

    cd EliteADC/Examples/Thermistors
    make clean all

Run the Example

    ./Thermistor

