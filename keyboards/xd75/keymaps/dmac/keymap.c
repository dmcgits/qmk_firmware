/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Layer shorthand
#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
	MDOWN_IMG_MACRO = SAFE_RANGE,
	CPP_MAIN_MACRO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | ESC/SHF| A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_BASE] = LAYOUT_ortho_5x15( /* QWERTY */
    KC_GRAVE,           KC_1,       KC_2,    KC_3,    	KC_4,    KC_5,    KC_BSPC,  	KC_KP_MINUS, KC_KP_PLUS,	KC_6,   KC_7,    KC_8,     	KC_9,     KC_0,     KC_BSPC,
    KC_TAB,             KC_Q,       KC_W,    KC_E,    	KC_R,    KC_T,    KC_KP_7,  		KC_KP_8,  	KC_KP_9,  		KC_Y,   KC_U,    KC_I,     	KC_O,     KC_P,     KC_BSLASH,
    LT(_LOWER, KC_ESC), KC_A,       KC_S,    KC_D,    	KC_F,    KC_G,    KC_KP_4,  		KC_KP_5,   	KC_KP_6,  		KC_H,   KC_J,    KC_K,     	KC_L,     KC_SCLN,  KC_QUOTE,
    KC_LSFT,            KC_Z,       KC_X,    KC_ENTER, 	KC_C,		 KC_V,    KC_KP_1,  		KC_KP_2,  	KC_KP_3,  		KC_B,		KC_N,    KC_M,    	KC_COMM, 	KC_DOT,   MT(MOD_RSFT, KC_SLASH),
    KC_LCTL,            KC_LCTRL,   KC_LGUI, KC_LALT,		KC_SPC,  KC_SPC,  KC_KP_0,  		KC_KP_DOT,  KC_KP_ENTER,  MO(_RAISE), MO(_RAISE),  KC_RCTRL,	KC_MINUS, KC_EQUAL,  KC_DEL
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_RAISE] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F12,                KC_F1,       KC_F2,   	KC_F3,   	KC_F4,   	KC_F5,   					KC_NUMLOCK,	KC_SLSH, 	KC_ASTR, 		KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,       KC_F11, \
		KC_ENTER,    KC_SYSTEM_SLEEP,       KC_LWIN, 	KC_LCBR,  KC_RCBR, 	KC_5,		 					KC_P7,  				KC_P8,   	KC_P9,   		KC_6,     KC_PGUP,  KC_UP,    KC_PGDN,    KC_PSCREEN,   RESET, \
    KC_CAPSLOCK,         KC_HOME,       KC_LEFT, 	KC_LPRN, 	KC_RPRN, 	KC_END,		 				KC_P4,  				KC_P5,   	KC_P6,   		KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT,   KC_END,       KC_ENT, \
    KC_TRNS,            KC_BSPACE,      KC_DEL, 	KC_LBRC,  KC_RBRC,  MDOWN_IMG_MACRO, 	KC_P1,   				KC_P2,   	KC_P3,   		RGB_VAI,  RGB_HUD,  KC_MPLY,  KC_VOLD,    KC_VOLU,      KC_QUES, \
    KC_TRNS,             KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 						CPP_MAIN_MACRO,  	KC_TRNS, 	KC_PDOT, 	KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_VOLD,    KC_VOLU,      KC_TRNS \
		),

		[_LOWER] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F12,          LCTL(KC_F5),       KC_F5,   	KC_F10,   KC_F11,   KC_F12,   					KC_NUMLOCK, 				KC_SLSH, 	KC_ASTR, 		KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,       KC_F11, \
		KC_ENTER,    KC_SYSTEM_SLEEP,       KC_LWIN, 	KC_LCBR,  KC_RCBR, 	KC_5,		 					  KC_P7,  				KC_P8,   	KC_P9,   		KC_6,     KC_PGUP,  KC_UP,    KC_PGDN,    KC_PSCREEN,   RESET, \
    KC_CAPSLOCK,         KC_HOME,       KC_LEFT, 	KC_LPRN, 	KC_RPRN, 	KC_END,		 				  KC_P4,  				KC_P5,   	KC_P6,   		KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT,   KC_END,       KC_ENT, \
    KC_TRNS,            KC_BSPACE,      KC_DEL, 	KC_LBRC,  KC_RBRC,  MDOWN_IMG_MACRO, 	  KC_P1,   				KC_P2,   	KC_P3,   		RGB_TOG,	RGB_VAI,  RGB_HUD,   KC_VOLD,    KC_VOLU,      KC_QUES, \
    KC_TRNS,             KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, 						CPP_MAIN_MACRO,  	KC_TRNS, 	KC_PDOT, 	KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_VOLD,    KC_VOLU,      KC_TRNS \
		)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MDOWN_IMG_MACRO:
        if(record->event.pressed) {
					SEND_STRING("![]()");
				} else {
					// if it's released
        }
				break;
    case CPP_MAIN_MACRO:
        if(record->event.pressed) {
					SEND_STRING("int main() \
					{ \
						return(0);\
					} \
					");
				} else {
					// if it's released
        }
				break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}