#ifndef DMACMAKES
#define DMACMAKES
#endif

#ifndef TAP_DANCE_ENABLE
#define TAP_DANCE_ENABLE
#endif

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"
// DOCSNOTE tap dance enable was missing from the docs example


enum {
  TD_ESC_GRAVE = 0,
  TD_ENTER_SPACE = 1,
  TD_ESC_LAYER1
};


// Possible outcomes for the key
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2
};

// DOCS NOTE This was called xtap in the docs so creating a tap in dmacmakes.c didn't work.
typedef struct {
  bool is_press_action;
  int state;
} tap;


// DOCSNOTE they had "ctl_x" which is the reverse of what happends (x on tap ctl on hold)
// Specific tapdances

int cur_dance (qk_tap_dance_state_t *state);

// for the escGr tap dance. put it here so it can be used in any keymap
void escGr_finished (qk_tap_dance_state_t *state, void *user_data);
void escGr_reset (qk_tap_dance_state_t *state, void *user_data);

void tdEnterSpace_finished (qk_tap_dance_state_t *state, void *user_data);
void tdEnterSpace_reset (qk_tap_dance_state_t *state, void *user_data);
