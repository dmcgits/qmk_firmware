#include QMK_KEYBOARD_H
#include "dmacmakes.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  , |  . | Mo(r_shift,/) | U | Del |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl |  Alt  |  Cmd  |  Space/Enter   |  FN  |   Space   | Cmd | RAlt |  L  |  D  |  R  |
 * `-----------------------------------------------------------------------------------------'
 */

  LAYOUT_directional(
      KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_DEL, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      LT(2, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, ______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT (MOD_RSFT, KC_SLASH), KC_UP, KC_DEL,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), KC_SPC, KC_RCTL, MO(1), KC_LEFT, KC_DOWN, KC_RIGHT
      ),

/* FN Layer

TD(TD_ENTER_SPACE)
 * ,-----------------------------------------------------------------------------------------.
 * | Esc | BL- | BL+ | BL  |     |     |     |RESET|     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |    | Val+ | Val- | Reset |
 * |-----------------------------------------------------------------------------------------+
 * |         | Hue+| Hue-| Sat+| Sat-|     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |     | Up  |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |       |       |          |       |              |       |    | Hm |    Pd |  End |
 * `-----------------------------------------------------------------------------------------'
 */

  LAYOUT_directional(
      KC_ESC,   KC_F1,  KC_F2,    KC_F3,  KC_F4,    KC_F5,      KC_F6,  KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_VOLD, KC_VOLU,   KC_SLEP, KC_DEL,
      KC_ENT,   ______, ______,   KC_UP,  ______,   RGB_MOD,    RGB_TOG, KC_PGDN,    KC_UP,  KC_PGUP,   KC_PSCR,   ______,  ______,    RESET,
      KC_CAPS, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, ______,   KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_END,   ______,   ______,
      ______, ______, KC_BSPC, KC_DEL, KC_BSLS, BL_DEC, BL_TOGG, BL_INC, ______, ______, ______, KC_QUESTION, KC_PGUP, KC_INS,
      ______, ______, ______, KC_ENTER, ______, ______, ______, ______, KC_HOME, KC_PGDN, KC_END
      ),

  LAYOUT_directional(
      KC_ESC,   KC_F1,  KC_F2,    KC_F3,  KC_F4,    KC_F5,      KC_F6,  KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_VOLD, KC_VOLU,   KC_SLEP, KC_DEL,
      KC_ENT,   ______, ______,   KC_UP,  ______,   RGB_MOD,    RGB_TOG, ______,    KC_UP,  ______,   KC_PSCR,   ______,  ______,    RESET,
      KC_CAPS, ______, KC_LBRACKET, KC_LEFT_CURLY_BRACE, KC_LEFT_PAREN, KC_LEFT_ANGLE_BRACKET,   KC_RIGHT_ANGLE_BRACKET, KC_RIGHT_PAREN, KC_RIGHT_CURLY_BRACE, KC_RBRACKET, ______,   ______,   KC_KP_ENTER,
      ______, ______, KC_BSPC, KC_DEL, KC_BSLS, BL_DEC, BL_TOGG, BL_INC, ______, ______, ______, ______, KC_PGUP, KC_INS,
      ______, ______, ______, KC_ENTER, ______, ______, ______, ______, KC_HOME, KC_PGDN, KC_END
      ),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
