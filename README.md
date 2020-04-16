# avr-examples

Examples for AVR microcontrollers (mainly ATmega328) using avr-libc.

## Usage

Install prerequisites (for Debian):

    apt install gcc-avr avr-libc avrdude

Allow your user to write to USB port:

    usermod -a -G dialout USERNAME   # and remember to log out / log in

Build an example with avr-gcc:

    avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o program.o SOURCE.c
    avr-gcc -mmcu=atmega328p program.o -o program.elf

Translate the resulting ELF file to Intel HEX format:

    avr-objcopy -O ihex -R .eeprom program.elf program.hex

Flash the HEX file to the chip with avrdude:

    avrdude -F -V -p atmega328p -c arduino -P /dev/ttyUSB0 -b 115200 \
      -U flash:w:program.hex

Please note that your chip must have a proper bootloader installed.

## Examples

### pir.c

Passive infrared (PIR) motion detection sensor connected to ATmega328.

This program polls the port B pin 4 with 500ms interval. If the pin is set high
(motion detected by the sensor), then the program sets the port B pin 5 high,
otherwise set it low.

If you use this example with Arduino Nano board, the port B pin 5 is actually
the on-board LED. The LED will turn on every time if there is motion detected
in the front of the sensor.

## License

MIT License. Copyright (c) 2020 [Jari Jokinen](https://jarijokinen.com).  See
[LICENSE](https://github.com/jarijokinen/avr-examples/blob/master/LICENSE.txt)
for further details.
