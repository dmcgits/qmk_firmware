#include QMK_KEYBOARD_H
//hash include "dmacmakes.h"

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

  LAYOUT_arrows_dmac(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, ______,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      LT(2, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_1, KC_Z, KC_X, KC_C, KC_V,KC_B, KC_N, KC_M, KC_COMM, KC_DOT, ______, MT (MOD_RSFT, KC_SLASH), KC_UP, KC_BSPC,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_GRAVE, MO(1), KC_LGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
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

  LAYOUT_arrows_dmac(
      KC_ESC,   KC_F1,  KC_F2,    KC_F3,  KC_F4,    KC_F5,      KC_F6,  KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_VOLD, KC_VOLU, KC_F11, KC_F11,
      KC_ENT,   KC_SYSTEM_SLEEP, RGB_TOG,   RGB_VAD,  RGB_VAI,   RGB_MODE_PLAIN,   RGB_MOD, KC_PGUP,    KC_UP,  KC_PGDN,   KC_PSCR,   RGB_VAI,  RGB_VAD,    RESET,
      KC_CAPS, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, ______,   KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,  KC_END,   KC_END, ______,
      ______, KC_6, KC_BSPC, KC_DEL, KC_BSLS, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_VOLD, KC_VOLU, KC_F11, KC_QUESTION, KC_PGUP, KC_F11,
      ______, MAGIC_UNSWAP_ALT_GUI, MAGIC_SWAP_ALT_GUI, KC_ENTER, ______, ______, ______, MAGIC_TOGGLE_ALT_GUI, KC_HOME, KC_PGDN, KC_END
      ),

  LAYOUT_arrows_dmac(
      KC_ESC, LCTL(KC_F5),  KC_F5,  KC_F10,  KC_F11, KC_F12,      KC_F6,  KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_VOLD, KC_VOLU, KC_F11, KC_F11,
      KC_ENT,      KC_SYSTEM_SLEEP, ______,   KC_LCBR,  KC_RCBR,   RGB_MOD,    RGB_TOG, ______,    KC_UP,  ______,   KC_PSCR,   KC_I,  ______,    RESET,
      ______, 	______, ______, KC_LPRN, KC_RPRN, KC_LABK,   KC_RABK, KC_LABK,    KC_RABK,    KC_LBRC,    KC_RBRC,   ______,   KC_ENTER,
      ______, KC_6, KC_BSPC, KC_LBRC, KC_RBRC, BL_DEC, BL_TOGG, BL_INC, ______, ______, ______, ______, ______, KC_VOLU, MAGIC_SWAP_ALT_GUI,
      ______, ______, MAGIC_TOGGLE_ALT_GUI, KC_ENTER, ______, ______, ______, ______, KC_HOME, KC_VOLD, KC_END
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
