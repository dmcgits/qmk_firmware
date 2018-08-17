#include "dmacmakes.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"
#include "config.h"

/*
 * Return an integer for type of tap dance to send
 *
 How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */



 int cur_dance (qk_tap_dance_state_t *state) {
   if (state->count == 1) {
      if (state->interrupted || !state->pressed) {
        return SINGLE_TAP;
      } else {
        return SINGLE_HOLD;
      }
   }
   return 8;
 }

// Instantiate a tap for escGr dance
 static tap escGrTap_state = {
   .is_press_action = true,
   .state = 0
 };

  static tap tdEnterSpaceTap_state = {
   .is_press_action = true,
   .state = 0
 };

 void escGr_finished (qk_tap_dance_state_t *state, void *user_data) {
   escGrTap_state.state = cur_dance(state);
   switch (escGrTap_state.state) {
     case SINGLE_TAP: register_code(KC_ESC); break;
     case SINGLE_HOLD: register_code(KC_GRAVE); break;
   }
 }

 void escGr_reset (qk_tap_dance_state_t *state, void *user_data) {
   switch (escGrTap_state.state) {
     case SINGLE_TAP: unregister_code(KC_ESC); break;
     case SINGLE_HOLD: unregister_code(KC_GRAVE); break;
   }
   escGrTap_state.state = 0;
 }

  void tdEnterSpace_finished (qk_tap_dance_state_t *state, void *user_data) {
   
   tdEnterSpaceTap_state.state = cur_dance(state);
   switch (tdEnterSpaceTap_state.state) {
     case SINGLE_TAP: register_code(KC_ENTER); break;
     case SINGLE_HOLD: register_code(KC_SPACE); break;
   }
 }

 void tdEnterSpace_reset (qk_tap_dance_state_t *state, void *user_data) {
   switch (tdEnterSpaceTap_state.state) {
     case SINGLE_TAP: unregister_code(KC_ENTER); break;
     case SINGLE_HOLD: unregister_code(KC_SPACE); break;
   }
   tdEnterSpaceTap_state.state = 0;
 }

 qk_tap_dance_action_t tap_dance_actions[] = {
   [TD_ESC_GRAVE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, escGr_finished, escGr_reset),
   [TD_ENTER_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tdEnterSpace_finished, tdEnterSpace_reset)
 };


