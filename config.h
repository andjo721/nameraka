#pragma once

#include "custom_config.h"

// default but used in macros
#undef TAPPING_TERM

#if defined (NAMERAKA_TAPPING_TERM)
#define TAPPING_TERM (NAMERAKA_TAPPING_TERM)
#else
#define TAPPING_TERM 175
#endif

#define PERMISSIVE_HOLD

//#define RGB_MATRIX_LED_COUNT 0
//define HOLD_ON_OTHER_KEY_PRESS

#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off layer lock after 60 seconds.

// Prevent normal rollover on alphas from accidentally triggering mods.
// #define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Setting QUICK_TAP_TERM to 0 to stop keys with hold actions from autorepeating TAP key, if tapped twice in quick succession and then held.
// https://docs.qmk.fm/#/tap_hold?id=quick-tap-term
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 0

// combos
#define COMBO_COUNT 2

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// Thumb Combos
#if defined (NAMERAKA_KLUDGE_THUMBCOMBOS)
  #define COMBO_COUNT 8
  #define COMBO_TERM 200
  #define EXTRA_SHORT_COMBOS
#endif
