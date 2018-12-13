#include "snagpad.h"
#define _DEFLT 0
#define _RAISE 1
#define _LOWER 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_DEFLT] = KEYMAP( \
		TG(_RAISE),		KC_PSLS,	KC_PAST,	KC_PMNS, 
		KC_P7,		KC_P8,		KC_P9,		KC_PPLS, 
		KC_P4,		KC_P5,		KC_P6,		KC_PPLS, 
		KC_P1,		KC_P2,		KC_P3,		KC_PENT, 
		KC_P0,		KC_P0,		KC_PDOT,	KC_PENT),

	[_RAISE] = KEYMAP( \
		KC_TRNS, 	KC_VOLD,	KC_VOLU,	KC_F5, 
		KC_PGUP, 	KC_TRNS,	KC_PGDN,	LCTL(KC_F5), 
		KC_HOME, 	KC_UP,		KC_END,		LCTL(KC_F5), 
		KC_LEFT, 	KC_DOWN,	KC_RIGHT,	KC_TRNS, 
		KC_SPACE, 	KC_SPACE,	KC_BSPC,	KC_TRNS)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	//keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}