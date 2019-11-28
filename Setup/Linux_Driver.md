
This is how to set up the ADC Module to use the native linux drivers on a Raspberry Pi (This should also work for most linux computers)

Please note this must be run as ROOT the preferred way is to use

    sudo su

This will switch you to the root user to run the following commands.

Enable the ADC Linux Driver Module (Please note that the ADC chips are MCP3424 which are included in this Linux Driver)

`modprobe mcp3422`

Add the 2x MCP3424 addresses to the I2C bus devices (These are the preset addresses 0x6C and 0x6A)

    echo "mcp3424 0x6c" >/sys/bus/i2c/devices/i2c-1/new_device
    echo "mcp3424 0x6a" >/sys/bus/i2c/devices/i2c-1/new_device

Create an easy to find link in the /dev/folder

    ln -s /sys/bus/i2c/devices/1-006c/iio:device0/ /dev/i2cadc0
    ln -s /sys/bus/i2c/devices/1-006a/iio:device1/ /dev/i2cadc1


Now if you look in the /dev/i2cadc0 folder you will find some configuration files.
You can set the sampling frquency to 60 samples per second with the following commands to set both ADC's (please not each ADC can be configured seperately)

    echo 60 > /dev/i2cadc0/in_voltage_sampling_frequency
    echo 60 > /dev/i2cadc1/in_voltage_sampling_frequency


If you would like to set the gain of the ADC's you can use the following commands. (please note the gain can be set per channel of the ADC)

    echo 0.000250000 > /dev/i2cadc0/in_voltage0_scale
    echo 0.000250000 > /dev/i2cadc0/in_voltage1_scale
    echo 0.000250000 > /dev/i2cadc0/in_voltage2_scale
    echo 0.000250000 > /dev/i2cadc0/in_voltage3_scale

    echo 0.000250000 > /dev/i2cadc1/in_voltage0_scale
    echo 0.000250000 > /dev/i2cadc1/in_voltage1_scale
    echo 0.000250000 > /dev/i2cadc1/in_voltage2_scale
    echo 0.000250000 > /dev/i2cadc1/in_voltage3_scale

## Please note these settings will reset after each boot
if you would like to make them permanent create a script in /etc/init.d to load these settings every boot