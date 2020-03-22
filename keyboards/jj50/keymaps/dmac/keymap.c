/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "rgblight.h"

#define ______ KC_TRNS
#define _DEFLT 0
#define _RAISE 1
#define _LOWER 2
#define _FN 3

enum custom_keycodes {
    //P_MACRO = SAFE_RANGE,
		MDOWN_IMG_MACRO = SAFE_RANGE,
};

// GBP £ Macro (sends alt 156 - windows users only)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
      case MDOWN_IMG_MACRO:
        if(record->event.pressed) {
					SEND_STRING("![]()");
				} else {
					// if it's released
        }
				break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | sh/? |Enter | (Hold for shift / tap for ?)
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | LGUI | Alt  | Space| Space|_RAISE|    Space    |   -  |   +  |_RAISE| Del  |
     * `-----------------------------------------------------------------------------------'
     */
    [_DEFLT] = LAYOUT( 
        KC_GRAVE,           KC_1,       KC_2,    KC_3,    KC_4,    KC_5,        KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPACE,  \
        KC_TAB,             KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLS,    \
        LT(_LOWER, KC_ESC), KC_A,       KC_S,    KC_D,    KC_F,    KC_G,        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    \
        KC_LSFT,            KC_Z,   	KC_X,	KC_ENTER, KC_C,    KC_V,        KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     MT(MOD_RSFT, KC_SLASH),     \
        KC_LCTL,            KC_LCTL,    KC_LGUI, KC_LALT, KC_SPACE,KC_SPACE,  MO(_RAISE),MO(_RAISE),     KC_RCTL,    KC_MINUS,   KC_EQUAL,   KC_DEL      \
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  | PgDn |  Up  | PgUp |      |Reset |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      | Home | Left | Down |Right | End  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | BSp  | Del  | BlDec|BLInc |BLStep|RGBTg |RGBSad|RGBSai|      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
	// Right space function layer
    [_RAISE] = LAYOUT( 		
       KC_F12,                KC_F1,     KC_F2,   KC_F3,    KC_F4,    KC_F5,            KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,       KC_F11, \
       KC_ENTER,    KC_SYSTEM_SLEEP,   KC_LWIN,   KC_LCBR,  KC_RCBR,  KC_5,             KC_6,     KC_PGUP,  KC_UP,    KC_PGDN,    KC_PSCREEN,   RESET, \
       KC_CAPSLOCK,         KC_HOME,   KC_LEFT,   KC_LPRN,  KC_RPRN,  KC_END,           KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT,   KC_END,       KC_ENT, \
       ______,           KC_BSPACE,    KC_DEL,   KC_LBRC,  KC_RBRC,  MDOWN_IMG_MACRO,  RGB_VAI,  RGB_HUD,  KC_MPLY,  KC_VOLD,    KC_VOLU,      KC_QUES, \
       ______,             ______,   ______,   ______,  KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PLAY_PAUSE,  ______,  ______,  ______,   KC_VOLD,    KC_VOLU, KC_INSERT \
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  ENT |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |   {  |   }  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |ISO ~ |ISO | |  HOM |  END |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
	// capsLock/esc function layer
    [_LOWER] = LAYOUT( 
        KC_F12, LCTL(KC_F5),      KC_F5,     KC_F10,    KC_F11,  KC_F12,        KC_F6,      KC_F7,      KC_F8,   KC_MINUS,      KC_EQUAL,   KC_F11,    \
        KC_MEDIA_PLAY_PAUSE,  KC_SYSTEM_SLEEP,    ______,     KC_LCBR,    KC_RCBR,    ______,		BL_ON,      BL_OFF,     BL_DEC,      BL_INC,    KC_PSCREEN, KC_BSLS,    \
        ______,    ______,    ______,   KC_LPRN,    KC_RPRN, 	KC_LABK,		KC_RABK,	KC_LABK,    KC_RABK,    KC_LBRC,    KC_RBRC,    KC_ENT,     \
        ______,    ______,   ______,    KC_LBRC,    KC_RBRC,    MDOWN_IMG_MACRO,		RGB_VAI,	RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,    RGB_MODE_PLAIN,  \
        BL_STEP,    ______,    ______,    ______,   LCTL(KC_SPC), LCTL(KC_SPC),      ______,      ______,    KC_MNXT,    KC_VOLD,    KC_VOLU,  KC_INSERT \
    ),
    
    /* Fn
     * ,-----------------------------------------------------------------------------------.
     * |      |      |  £   |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |BL_OFF|BL_DEC|BL_INC|BL_ON |
     * `-----------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT( 
       ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
       ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
       ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
       ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
       ______, ______, ______, ______, ______, ______, ______, ______, BL_OFF,  BL_DEC,  BL_INC,  BL_ON    \
    )
};
