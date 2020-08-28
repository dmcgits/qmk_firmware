#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_keycodes {
    //P_MACRO = SAFE_RANGE,
		MDOWN_IMG_MACRO = SAFE_RANGE
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define ______ KC_TRNS
#define _DEFLT 0
#define _RAISE 1
#define _LOWER 2
#define _FN 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Qwerty
	* ,-----------------------------------------------------------------------------------.
	* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
	* `-----------------------------------------------------------------------------------'
	*/
	[_DEFLT] = LAYOUT( \
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
		LT(_LOWER, KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
		KC_LSFT, KC_Z,    KC_X,    KC_ENT,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT,  MT(MOD_RSFT,KC_SLSH), \
		KC_LCTL,  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,   KC_SPC,  MO(_RAISE),  MO(_RAISE),   KC_RCTL, KC_MINUS, KC_EQUAL, KC_DEL \
	),

	/* Colemak
	* ,-----------------------------------------------------------------------------------.
	* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
	* `-----------------------------------------------------------------------------------'
	*/
	[_RAISE] = LAYOUT( \
		KC_F12,                KC_F1,     KC_F2,   KC_F3,    KC_F4,    KC_F5,            KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,       KC_F11, \
		KC_ENTER,    KC_SYSTEM_SLEEP,   KC_LWIN,   KC_LCBR,  KC_RCBR,  KC_5,             KC_6,     KC_PGUP,  KC_UP,    KC_PGDN,    KC_PSCREEN,   RESET, \
		KC_CAPSLOCK,         KC_HOME,   KC_LEFT,   KC_LPRN,  KC_RPRN,  KC_END,           KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT,   KC_END,       KC_ENT, \
		______, KC_BSPACE,    KC_DEL,   KC_LBRC,  KC_RBRC,  MDOWN_IMG_MACRO,  RGB_VAI,  RGB_HUD,  KC_MPLY,  KC_VOLD,    KC_VOLU,      KC_QUES, \
		______,             ______,   ______,   ______,  KC_MEDIA_PLAY_PAUSE, KC_MEDIA_PLAY_PAUSE,  ______,  ______,  ______,   KC_VOLD,    KC_VOLU, KC_INSERT \
	),

	/* Dvorak
	* ,-----------------------------------------------------------------------------------.
	* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
	* |------+------+------+------+------+-------------+------+------+------+------+------|
	* | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
	* |------+------+------+------+------+------|------+------+------+------+------+------|
	* | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
	* |------+------+------+------+------+------+------+------+------+------+------+------|
	* |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
	* `-----------------------------------------------------------------------------------'
	*/
	[_LOWER] = LAYOUT( \
		KC_F12, LCTL(KC_F5),      KC_F5,     KC_F10,    KC_F11,  KC_F12,        KC_F6,      KC_F7,      KC_F8,   KC_MINUS,      KC_EQUAL,   KC_F11,    \
		KC_MEDIA_PLAY_PAUSE,  KC_SYSTEM_SLEEP,    ______,     KC_LCBR,    KC_RCBR,    ______,		BL_ON,      BL_OFF,     BL_DEC,      BL_INC,    KC_PSCREEN, KC_BSLS,    \
		______,    ______,    ______,   KC_LPRN,    KC_RPRN, 	KC_LABK,		KC_RABK,	KC_LABK,    KC_RABK,    KC_LBRC,    KC_RBRC,    KC_ENT,     \
		______,    ______,   ______,    KC_LBRC,    KC_RBRC,    MDOWN_IMG_MACRO,		RGB_VAI,	RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,    RGB_MODE_PLAIN,  \
		BL_STEP,    ______,    ______,    ______,   LCTL(KC_SPC), LCTL(KC_SPC),      ______,      ______,    KC_MNXT,    KC_VOLD,    KC_VOLU,  KC_INSERT \
	)
}; // End declaration of layouts array

// This function will be called every matrix scan so we can add Macro functionality
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
}

