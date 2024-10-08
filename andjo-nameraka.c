/* Created by Andreas Johansson
   Inspired by and expanded from manna-harbour_miryoku
   ---------------------------------------------------

   Features include:
   - Caps word
   - Layer lock
   - Tmux and emacs window handling
   - Emacs project and programming layer
   - Swedish characters using outer 3x6 columns or combos.

   To build and flash normally:
   qmk flash -c -kb crkbd -km andjo-nameraka -e NAMERAKA_ALPHAS=QWERTY -e NAMERAKA_EXTRA=COLEMAKDH -e NAMERAKA_TAP=QWERTY

   May be built with mac os ansi keymap support by setting the environment variable:
   -e NAMERAKA_KEYMAP=MACOS
   when building. For example
   qmk flash -c -kb crkbd -km andjo-nameraka -e NAMERAKA_ALPHAS=QWERTY -e NAMERAKA_EXTRA=COLEMAKDH -e NAMERAKA_TAP=QWERTY -e NAMERAKA_KEYMAP=MACOS

   To enable support for the lsp code server ccls, see ccls_create.sh.
*/

#include QMK_KEYBOARD_H
#include "andjo-nameraka.h"
#include "wait.h"
#include "features/layer_lock.h"

enum custom_keycodes {
    WIND_LEFT = SAFE_RANGE,
    WIND_RIGHT,
    WIND_UP,
    WIND_DOWN,
    WIND_MAX_TOGGLE,
    HELM_RESUME,
    LAYER_LOCK, // May be used for locking to current layer.

    /* Project keycodes */
    PRJ_FILES,
    PRJ_PROJS,
    PRJ_SEARCH,
    PERSP_BUF,
    MAGIT_STATUS,
    PRJ_OTHER_FILE,
    LSP_TYPE_DEFINITION,
    CCLS_CALL_HIERARCHY,
    CCLS_MEMBER_HIERARCHY,
    GO_TO,
    GO_BACK,
    LSP_FORMAT_REGION,
    LSP_REFERENCES,
    LSP_RENAME,
    LSP_LENS,
    VC_REVERT_HUNK,
    FLYCHECK_NEXT_ERROR,
    FLYCHECK_PREV_ERROR,

    /* GPT */
    GPT_QUERY,
    GPT_REPLY,

    /* Swedish key codes for activation through e.g. Combos. */
    KEY_AA,
    KEY_AE,
    KEY_OE,

    /* Macro keys */
    JS_ARROW_FN,
};

// Combos for å ä ö, that works on the smaller 3x5 keyboard splits.
const uint16_t PROGMEM combo_aa[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_oe[] = {RSFT_T(KC_J), LCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo_ae[] = {MEH_T(KC_M), KC_COMM, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_aa, KEY_AA),
    COMBO(combo_ae, KEY_AE),
};

#define PROCESS_SUB_RECORD(F) { \
        int r = F(keycode, record, mods); \
        if (r == 0) \
           goto bail_false; \
        else if (r == 1) \
           return true; \
    }

int process_record_programming(uint16_t keycode, keyrecord_t *record, const uint8_t mods)
{
    // Mostly for programming
    clear_mods();

    if (mods & MOD_MASK_ALT) {
        if (keycode == SE_LCBR) {
            tap_code(KC_END);
            tap_code(KC_SPC);
            tap_code16(SE_LCBR);
            tap_code16(SE_RCBR);
            tap_code(KC_LEFT);
            tap_code(KC_TAB);
            tap_code(KC_ENT);
            tap_code(KC_ENT);
            tap_code(KC_TAB);
            tap_code(KC_UP);
            tap_code(KC_TAB);
            goto bail;
        }
    }

    if (mods & MOD_MASK_CTRL) {
        if (keycode == SE_LABK) {
            tap_code16(SE_LABK);
            tap_code16(SE_RABK);
            tap_code(KC_LEFT);
            goto bail;
        }

        if (keycode == KC_COMM) {
            tap_code(KC_COMM);
            tap_code(KC_SPC);
            goto bail;
        }

        if (keycode == SE_SLSH) {
            tap_code16(SE_SLSH);
            tap_code16(SE_SLSH);
            tap_code(KC_SPC);
            goto bail;
        }

        if (keycode == SE_GRV) {
            tap_code16(SE_GRV);
            tap_code16(SE_GRV);
            tap_code16(SE_GRV);
            tap_code16(SE_GRV);
            tap_code(KC_LEFT);
            goto bail;
        }

        if (keycode == SE_QUOT) {
            tap_code16(SE_QUOT);
            tap_code16(SE_QUOT);
            tap_code(KC_LEFT);
            goto bail;
        }

        if (keycode == SE_DQUO) {
            tap_code16(SE_DQUO);
            tap_code16(SE_DQUO);
            tap_code(KC_LEFT);
            goto bail;
        }

        if (keycode == SE_EQL) {
            tap_code(KC_SPC);
            tap_code16(SE_EQL);
            tap_code16(SE_EQL);
            tap_code(KC_SPC);
            goto bail;
        }

        if (keycode == SE_SCLN) {
            tap_code(KC_END);
            tap_code16(SE_SCLN);
            tap_code(KC_ENT);
            goto bail;
        }

        if (keycode == SE_EXLM) {
            tap_code(KC_SPC);
            tap_code16(SE_EXLM);
            tap_code16(SE_EQL);
            tap_code(KC_SPC);
            goto bail;
        }

        if (keycode == SE_PIPE) {
            tap_code(KC_SPC);
            tap_code16(SE_PIPE);
            tap_code16(SE_PIPE);
            tap_code(KC_SPC);
            goto bail;
        }

        if (keycode == SE_AMPR) {
            tap_code(KC_SPC);
            tap_code16(SE_AMPR);
            tap_code16(SE_AMPR);
            tap_code(KC_SPC);
            goto bail;
        }

        if (keycode == SE_LPRN) {
            tap_code16(SE_LPRN);
            tap_code16(SE_RPRN);
            tap_code(KC_LEFT);
            goto bail;
        }

        if (keycode == SE_LCBR) {
            tap_code16(SE_LCBR);
            tap_code16(SE_RCBR);
            tap_code(KC_LEFT);
            goto bail;
        }

        if (keycode == SE_LBRC) {
            tap_code16(SE_LBRC);
            tap_code16(SE_RBRC);
            tap_code(KC_LEFT);
            goto bail;
        }
    }

    set_mods(mods);
    return -1;
bail:
    set_mods(mods);
    return 0;
}

/**
 */
int process_record_num(uint16_t keycode, keyrecord_t *record, const uint8_t mods)
{
    const uint8_t mod_mask  = (MOD_BIT(KC_LEFT_GUI)) | (MOD_BIT(KC_LEFT_ALT)) | (MOD_BIT(KC_LEFT_CTRL)) | (MOD_BIT(KC_LEFT_SHIFT));
    clear_mods();

    if (keycode >= KC_1 && keycode <= KC_0) {
        if ((mods & mod_mask) == ((MOD_BIT(KC_LEFT_ALT)) | (MOD_BIT(KC_LEFT_CTRL)) | (MOD_BIT(KC_LEFT_SHIFT)))) {
            SEND_STRING(SS_LCTL("x"));
            SEND_STRING("x");
            tap_code(keycode);
            goto bail;
        }
    }

    set_mods(mods);
    return -1;
bail:
    set_mods(mods);
    return 0;
}

/**
 */
int process_record_navigation(uint16_t keycode, keyrecord_t *record, const uint8_t mods)
{
    const uint8_t mod_mask  = (MOD_BIT(KC_LEFT_GUI)) | (MOD_BIT(KC_LEFT_ALT)) | (MOD_BIT(KC_LEFT_CTRL)) | (MOD_BIT(KC_LEFT_SHIFT));
    bool          wind_move = (keycode == WIND_LEFT) || (keycode == WIND_DOWN) || (keycode == WIND_UP) || (keycode == WIND_RIGHT);
    clear_mods();

    if (wind_move) {

        tap_code16(C(KC_B));

        if ((mods & mod_mask) == MOD_BIT(KC_LEFT_GUI) && (keycode == WIND_RIGHT)) {
            tap_code16(C(KC_RIGHT));
            goto bail_false;
        }
        if ((mods & mod_mask) == MOD_BIT(KC_LEFT_GUI) && (keycode == WIND_LEFT)) {
            tap_code16(C(KC_LEFT));
            goto bail_false;
        }
        if ((mods & mod_mask) == MOD_BIT(KC_LEFT_GUI) && (keycode == WIND_UP)) {
            tap_code16(C(KC_UP));
            goto bail_false;
        }
        if ((mods & mod_mask) == MOD_BIT(KC_LEFT_GUI) && (keycode == WIND_DOWN)) {
            tap_code16(C(KC_DOWN));
            goto bail_false;
        }

        if ((mods & mod_mask) == MOD_BIT(KC_LEFT_ALT) && (keycode == WIND_RIGHT)) {
            tap_code16(KC_PERCENT);
            goto bail_false;
        }

        if ((mods & mod_mask) == MOD_BIT(KC_LEFT_ALT) && (keycode == WIND_DOWN)) {
            tap_code16(SE_DQUO);
            goto bail_false;
        }

        if ((mods & mod_mask) == MOD_BIT(KC_LEFT_CTRL))
            tap_code16(KC_B);

        switch(keycode) {
        case WIND_LEFT:
            tap_code(KC_LEFT);
            goto bail_false;
        case WIND_DOWN:
            tap_code(KC_DOWN);
            goto bail_false;
        case WIND_UP:
            tap_code(KC_UP);
            goto bail_false;
        case WIND_RIGHT:
            tap_code(KC_RIGHT);
            goto bail_false;
        }
    }

    if (keycode == WIND_MAX_TOGGLE) {
        if ((mods & mod_mask) == MOD_BIT(KC_LEFT_CTRL)) {
            SEND_STRING(SS_LCTL("x"));
            SEND_STRING("1");
        }
        else if ((mods & mod_mask) == MOD_BIT(KC_LEFT_SHIFT)) {
            SEND_STRING(SS_LCTL("b"));
            SEND_STRING("t");
        }
        else {
            SEND_STRING(SS_LCTL("b"));
            SEND_STRING("z");
        }
        goto bail_false;
    }

    return -1;

bail_false:
    return 0;
}


/**
 */
int process_record_project(uint16_t keycode, keyrecord_t *record, const uint8_t mods)
{
    clear_mods();
    if (keycode == HELM_RESUME) {
        SEND_STRING(SS_LCTL("x") "cb");
        goto bail_false;
    }

    if (keycode == PRJ_FILES) {
        SEND_STRING(SS_LCTL("c") "pf");
        goto bail_false;
    }

    if (keycode == PRJ_PROJS) {
        SEND_STRING(SS_LCTL("c") "pp");
        goto bail_false;
    }

    if (keycode == PRJ_SEARCH) {
        SEND_STRING(SS_LCTL("c") "pss");
        goto bail_false;
    }

    if (keycode == PRJ_OTHER_FILE) {
        SEND_STRING(SS_LCTL("c") "pa");
        goto bail_false;
    }

    if (keycode == VC_REVERT_HUNK) {
        SEND_STRING(SS_LCTL("x") "vn");  // diff-hl-revert-hunk
        goto bail_false;
    }


    if (keycode == PERSP_BUF) {
        SEND_STRING(SS_LCTL("x") SS_LCTL("b"));
        goto bail_false;
    }

    if (keycode == MAGIT_STATUS) {
        SEND_STRING(SS_LCTL("x") "g");
        goto bail_false;
    }

    if (keycode == LSP_TYPE_DEFINITION) {
        SEND_STRING(SS_LCTL("q") "lgt");
        goto bail_false;
    }

    if (keycode == CCLS_CALL_HIERARCHY) {
        SEND_STRING(SS_LCTL("q") "lcc");
        goto bail_false;
    }

    if (keycode == CCLS_MEMBER_HIERARCHY) {
        SEND_STRING(SS_LCTL("q") "lcm");
        goto bail_false;
    }

    if (keycode == GO_TO) {
        tap_code16(A(SE_DOT));
        goto bail_false;
    }

    if (keycode == GO_BACK) {
        tap_code16(A(SE_COMM));
        goto bail_false;
    }

    if (keycode == LSP_FORMAT_REGION) {
        SEND_STRING(SS_LCTL("q") "l");
        tap_code16(SE_EQL);
        SEND_STRING("r");
        goto bail_false;
    }

    if (keycode == LSP_REFERENCES) {
        if (mods & MOD_MASK_CTRL) {
            SEND_STRING(SS_LCTL("q") "lGr");
        }
        else {
            SEND_STRING(SS_LCTL("q") "lgr");
        }
        goto bail_false;
    }

    if (keycode == LSP_RENAME) {
        SEND_STRING(SS_LCTL("q") "lrr");
        goto bail_false;
    }

    if (keycode == LSP_LENS) {
        SEND_STRING(SS_LCTL("q") "lTl");
        goto bail_false;
    }

    if (keycode == FLYCHECK_NEXT_ERROR) {
        SEND_STRING(SS_LCTL("c") "!n");
        goto bail_false;
    }

    if (keycode == FLYCHECK_PREV_ERROR) {
        SEND_STRING(SS_LCTL("c") "!p");
        goto bail_false;
    }

    set_mods(mods);
    return -1;

bail_false:
    set_mods(mods);
    return 0;
}


/**
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    const uint8_t mod_mask  = (MOD_BIT(KC_LEFT_GUI)) | (MOD_BIT(KC_LEFT_ALT)) | (MOD_BIT(KC_LEFT_CTRL)) | (MOD_BIT(KC_LEFT_SHIFT));
    const uint8_t mods = get_mods();

    /* if (!process_layer_lock(keycode, record, LAYER_LOCK)) { */
    /*     return false; */
    /* } */

    if (record->event.pressed) {
        // General implementation for combos - makes it possible to do macros and other more complicated stuff.
        if (keycode == KEY_AA) {
            tap_code16(SE_ARNG);
            return true;
        }

        // JS
        if (keycode == JS_ARROW_FN) {
            tap_code(KC_SPC);
            tap_code16(SE_EQL);
            tap_code(KC_SPC);
            tap_code16(SE_LPRN);
            tap_code16(SE_RPRN);
            tap_code(KC_SPC);
            tap_code16(SE_EQL);

            tap_code16(SE_RABK);
            tap_code16(KC_SPC);
            send_string(SS_LSFT(SS_LALT("8")));
            send_string(SS_LSFT(SS_LALT("9")));
            tap_code(KC_LEFT);
            goto bail_false;
        }

        // GPT
        if (keycode == GPT_QUERY) {
            clear_mods();
            SEND_STRING(SS_LCTL("c"));
            if ((mods & mod_mask) == MOD_BIT(KC_LEFT_CTRL)) {
                SEND_STRING("gt");
            } else {
                SEND_STRING("gq");
            }
            goto bail_false;
        }

        if (keycode == GPT_REPLY) {
            SEND_STRING(SS_LCTL("c"));
            SEND_STRING("gr");
        }

        if (keycode == KEY_AE) {
            tap_code16(SE_ADIA);
            return true;
        }

        PROCESS_SUB_RECORD(process_record_num);

        PROCESS_SUB_RECORD(process_record_programming);

        PROCESS_SUB_RECORD(process_record_navigation);

        PROCESS_SUB_RECORD(process_record_project);
    }

    return true;

bail_false:
    set_mods(mods);
    return false;
}


// Customized caps word for defines
bool caps_word_press_user(uint16_t keycode)
{
    switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case SE_A ... SE_Z:
    case SE_ARNG:
    case SE_ADIA:
    case SE_ODIA:
    case SE_MINS:
        add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
        return true;

    // Keycodes that continue Caps Word, without shifting.
    case SE_1 ... SE_0:
    case KC_BSPC:
    case KC_DEL:
    case SE_UNDS:
        return true;
    }

    return false;  // Deactivate Caps Word.
}


// Additional Features double tap guard

enum {
    U_TD_BOOT,
#define NAMERAKA_X(LAYER, STRING) U_TD_U_##LAYER,
NAMERAKA_LAYER_LIST
#undef NAMERAKA_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) {
    reset_keyboard();
  }
}

#define NAMERAKA_X(LAYER, STRING) \
void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << U_##LAYER); \
  } \
}
NAMERAKA_LAYER_LIST
#undef NAMERAKA_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define NAMERAKA_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
NAMERAKA_LAYER_LIST
#undef NAMERAKA_X
};



// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define NAMERAKA_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(NAMERAKA_LAYERMAPPING_##LAYER, NAMERAKA_LAYER_##LAYER),
NAMERAKA_LAYER_LIST
#undef NAMERAKA_X
};

// thumb combos

#if defined (NAMERAKA_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_DEVELOP, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (NAMERAKA_LAYERS_FLIP)
const uint16_t PROGMEM thumbcombos_sym[] = {KC_UNDS, KC_LPRN, COMBO_END};
  #else
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
  #endif
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  #if defined (NAMERAKA_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif
