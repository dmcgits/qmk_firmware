echo "Port and file are hardcoded here using the output from QMK tookit. May need to tweak."
echo "Also doesn't wait around for keyboard to go into bootloader.. Bad script here friend."
avrdude.exe -p atmega32u4 -c avr109 -U flash:w:"W:\repos\qmk_dmac_keebio_nyquist_rev2_dmac.hex":i -P COM4
