#!/bin/sh

# This worked in Ubuntu WSL when pro micro wasn't showing up as com6 in qmk toolbox,
# but toolbox wasn't passing com6 after -P. Added -V for verbose also.
# Requires double-tap on rst + gnd on pro micro
avrdude -V -p atmega32u4 -c avr109 -U flash:w:"/mnt/w/personal/keyboard/qmk_dmac/keebio_nyquist_rev2_default.hex":i -P /dev/ttyS6