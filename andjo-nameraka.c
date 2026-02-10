/* Created by Andreas Johansson
   Inspired by and expanded from manna-harbour_miryoku
   ---------------------------------------------------

   Features include:
   - Caps word
   - Layer lock
   - Tmux and emacs window handling
   - Emacs project and programming layer
   - Swedish characters using outer 3x6 columns or combos.
   - Automatic OS detection (macOS vs Linux) at runtime - no reflash needed!

   To build and flash:
   qmk flash -c -kb crkbd -km andjo-nameraka -e NAMERAKA_ALPHAS=QWERTY -e NAMERAKA_EXTRA=COLEMAKDH -e NAMERAKA_TAP=QWERTY

   The keyboard will automatically detect whether it's connected to macOS or Linux
   and adjust keycodes accordingly (Alt key behavior, bracket keycodes, etc.).

   To enable support for the lsp code server ccls, see ccls_create.sh.
*/

#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "features/layer_lock.h"
#include "andjo-nameraka.h"

// Runtime OS detection state
static bool is_macos = false;

// QMK OS detection callback - fires when detection is stable
bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            is_macos = true;
            break;
        case OS_LINUX:
        case OS_WINDOWS:
        default:
            is_macos = false;
            break;
    }
    return true;
}

// Runtime helper to get the correct Alt keycode for the detected OS
static inline uint16_t get_nameraka_alt_keycode(void) {
    return is_macos ? KC_RALT : KC_LALT;
}

// Runtime helper to get the correct Alt key for the detected OS
static inline uint16_t get_nameraka_alt(void) {
    return is_macos ? KC_RIGHT_ALT : KC_LEFT_ALT;
}

// Runtime helper to get the correct Alt mod bit for the detected OS
static inline uint8_t get_nameraka_alt_mod(void) {
    return is_macos ? MOD_BIT(KC_RIGHT_ALT) : MOD_BIT(KC_LEFT_ALT);
}

// Runtime helpers for OS-specific bracket/brace keycodes
// Linux uses AltGr (ALGR), macOS uses Option (A) or Shift+Option (S(A()))

static inline uint16_t se_lcbr_runtime(void) {
    return is_macos ? S(A(KC_8)) : ALGR(KC_7);
}

static inline uint16_t se_rcbr_runtime(void) {
    return is_macos ? S(A(KC_9)) : ALGR(KC_0);
}

static inline uint16_t se_lbrc_runtime(void) {
    return is_macos ? A(KC_8) : ALGR(KC_8);
}

static inline uint16_t se_rbrc_runtime(void) {
    return is_macos ? A(KC_9) : ALGR(KC_9);
}

static inline uint16_t se_pipe_runtime(void) {
    return is_macos ? A(KC_7) : ALGR(KC_NUBS);
}

// Helper to translate Swedish keymap keycodes to OS-specific versions at runtime
// This handles the difference between Linux (AltGr) and macOS (Option) for brackets
static uint16_t translate_se_keycode(uint16_t kc) {
    if (!is_macos) {
        return kc;  // Linux keycodes are already correct (from keymap_swedish.h)
    }
    // Translate Linux SE_* keycodes to macOS equivalents
    switch (kc) {
        case ALGR(KC_7):  return S(A(KC_8));  // SE_LCBR: {
        case ALGR(KC_0):  return S(A(KC_9));  // SE_RCBR: }
        case ALGR(KC_8):  return A(KC_8);     // SE_LBRC: [
        case ALGR(KC_9):  return A(KC_9);     // SE_RBRC: ]
        case ALGR(KC_NUBS): return A(KC_7);   // SE_PIPE: |
        case ALGR(KC_MINS): return S(A(KC_7)); // SE_BSLS: backslash
        default: return kc;
    }
}

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
    JS_USE_EFCT,
    OS_STATUS,
    // Runtime OS-aware Alt mod-tap keys
    MT_ALT_R,   // Colemak left hand (R)
    MT_ALT_I,   // Colemak right hand (I)
    MT_ALT_S,   // QWERTY left hand (S)
    MT_ALT_L,   // QWERTY right hand (L)
    NMK_LALT,   // Plain Alt key (runtime-swapped)
};

extern const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM;

static char get_key_handedness(keyrecord_t *record) {
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;
    if (row >= MATRIX_ROWS || col >= MATRIX_COLS) {
        return '*';
    }
    return pgm_read_byte(&chordal_hold_layout[row][col]);
}

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

    if ((mods & MOD_MASK_ALT) && keycode == SE_LCBR) {
        static const uint16_t PROGMEM seq[] = {
            KC_END, KC_SPC, SE_LCBR, SE_RCBR,
            KC_LEFT, KC_TAB, KC_ENT, KC_ENT,
            KC_TAB, KC_UP,  KC_TAB
        };
        for (uint8_t i = 0; i < sizeof(seq)/sizeof(*seq); ++i) {
            tap_code16(translate_se_keycode(pgm_read_word(&seq[i])));
        }
        goto bail;
    }

    // A table of keycodes we special-case under CTRL
    // Each keycode trigger the corresponding sequence in ctrl_seq.
    static const uint16_t PROGMEM ctrl_keys[] = {
        SE_LABK, KC_COMM, SE_SLSH, SE_GRV,  SE_QUOT, SE_DQUO,
        SE_EQL,  SE_SCLN, SE_EXLM, SE_PIPE, SE_AMPR, SE_LPRN,
        SE_LCBR, SE_LBRC
    };

    // Length of sequences
    static const uint8_t PROGMEM ctrl_lens[] = {
        3,    2,    3,    5,     3,      3,
        4,    3,    4,    4,     4,      3,
        3,    3
    };

    // One sequence per line
    static const uint16_t PROGMEM ctrl_seq[] = {
        SE_LABK,   SE_RABK,   KC_LEFT,
        KC_COMM,   KC_SPC,
        SE_SLSH,   SE_SLSH,   KC_SPC,
        SE_GRV,    SE_GRV,    SE_GRV,  SE_GRV,  KC_LEFT,
        SE_QUOT,   SE_QUOT,   KC_LEFT,
        SE_DQUO,   SE_DQUO,   KC_LEFT,
        KC_SPC,    SE_EQL,    SE_EQL,  KC_SPC,
        KC_END,    SE_SCLN,   KC_ENT,
        KC_SPC,    SE_EXLM,   SE_EQL,  KC_SPC,
        KC_SPC,    SE_PIPE,   SE_PIPE, KC_SPC,
        KC_SPC,    SE_AMPR,   SE_AMPR, KC_SPC,
        SE_LPRN,   SE_RPRN,   KC_LEFT,
        SE_LCBR,   SE_RCBR,   KC_LEFT,
        SE_LBRC,   SE_RBRC,   KC_LEFT,
    };

    // Look up and play back, depending on keycode tapped:
    if (mods & MOD_MASK_CTRL) {
        for (uint8_t i = 0, offset = 0; i < ARRAY_SIZE(ctrl_keys); i++) {
            if (keycode == pgm_read_word(&ctrl_keys[i])) {
                uint8_t len = pgm_read_byte(&ctrl_lens[i]);
                for (uint8_t j = 0; j < len; j++) {
                    tap_code16(translate_se_keycode(pgm_read_word(&ctrl_seq[offset + j])));
                }
                goto bail;
            }
            offset += pgm_read_byte(&ctrl_lens[i]);
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
            SEND_STRING(SS_LCTL("b"));
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
    const uint8_t nameraka_alt_mod = get_nameraka_alt_mod();
    const uint8_t mod_mask  = (MOD_BIT(KC_LEFT_GUI)) | nameraka_alt_mod | (MOD_BIT(KC_LEFT_CTRL)) | (MOD_BIT(KC_LEFT_SHIFT));
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

        if ((mods & mod_mask) == nameraka_alt_mod && (keycode == WIND_RIGHT)) {
            tap_code16(KC_PERCENT);
            goto bail_false;
        }

        if ((mods & mod_mask) == nameraka_alt_mod && (keycode == WIND_DOWN)) {
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
        if (is_macos) {
            SEND_STRING(SS_RALT("."));
        } else {
            SEND_STRING(SS_LALT("."));
        }
        goto bail_false;
    }

    if (keycode == GO_BACK) {
        if (is_macos) {
            SEND_STRING(SS_RALT(","));
        } else {
            SEND_STRING(SS_LALT(","));
        }
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
uint16_t mt_alt_base_key(uint16_t keycode)
{
    uint16_t base_key = KC_NO;

    switch(keycode) {
        case MT_ALT_R: base_key = KC_R; break;
        case MT_ALT_I: base_key = KC_I; break;
        case MT_ALT_S: base_key = KC_S; break;
        case MT_ALT_L: base_key = KC_L; break;
    }

    // Special handling for CAPS WORD
    if (is_caps_word_on()) {
        add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
    }

    return base_key;
}


/**
 */
static uint16_t alt_mt_timer;
static uint16_t alt_mt_key = 0;
static char alt_mt_hand = 0;
static uint16_t alt_mt_pending_keycode = 0;
static uint16_t alt_mt_pending_original = 0;
static keyrecord_t alt_mt_pending_record;
static bool alt_mt_bypass = false;
static bool alt_mt_pending_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (alt_mt_bypass) return true;

    const uint8_t mod_mask  = (MOD_BIT(KC_LEFT_GUI)) | (MOD_BIT(KC_LEFT_ALT)) | (MOD_BIT(KC_LEFT_CTRL)) | (MOD_BIT(KC_LEFT_SHIFT));
    const uint8_t mods = get_mods();

    // Handle pending key release (opposite-hand key that was blocked)
    // This must come before MT_ALT_* check because an MT_ALT key could be the pending key
    if (!record->event.pressed && (keycode == alt_mt_pending_keycode || (alt_mt_pending_original != 0 && keycode == alt_mt_pending_original))) {
        if (alt_mt_pending_active) {
            if (alt_mt_pending_original != 0) {
                 unregister_code16(alt_mt_pending_keycode);
            } else {
                 alt_mt_bypass = true;
                 process_record(record);
                 alt_mt_bypass = false;
            }
            if (alt_mt_key == 0) unregister_code16(get_nameraka_alt_keycode());
            else alt_mt_timer = 0;
        } else {
            if (alt_mt_key != 0) {
                // NESTED: pending key released before mod-tap
                register_code16(get_nameraka_alt_keycode());
                uint16_t key_to_tap = alt_mt_pending_keycode;
                tap_code16(key_to_tap);
                alt_mt_timer = 0; // Force hold
            } else {
                // ROLLING aftermath
                unregister_code16(get_nameraka_alt_keycode());
                unregister_code16(alt_mt_pending_keycode);
            }
        }
        alt_mt_pending_active = false;
        alt_mt_pending_keycode = 0;
        alt_mt_pending_original = 0;
        return false;
    }

    // Custom OS-aware Alt Mod-Tap Logic
    if (keycode == MT_ALT_R || keycode == MT_ALT_I || keycode == MT_ALT_S || keycode == MT_ALT_L) {
        if (record->event.pressed) {
            // Check if another MT_ALT key is already held - treat this as an interrupt
            if (alt_mt_key != 0 && alt_mt_key != keycode) {
                register_code16(get_nameraka_alt_keycode());
                alt_mt_timer = 0; // Force hold behavior on first key's release

                alt_mt_pending_keycode = mt_alt_base_key(keycode);
                alt_mt_pending_original = keycode;
                alt_mt_pending_record = *record;
                return false;
            }

            alt_mt_timer = timer_read();
            alt_mt_key = keycode;
            alt_mt_hand = get_key_handedness(record);
            alt_mt_pending_keycode = 0;
            alt_mt_pending_original = 0;
            return false;
        } else {
            if (alt_mt_key == keycode) {
                if (alt_mt_pending_keycode != 0) {
                    // ROLLING: mod-tap released before pending key
                    // Tap the base key, then send the pending key
                    unregister_code16(get_nameraka_alt_keycode());
                    tap_code(mt_alt_base_key(keycode));

                    if (alt_mt_pending_original != 0) {
                        register_code16(alt_mt_pending_keycode);
                    } else {
                        alt_mt_bypass = true;
                        process_record(&alt_mt_pending_record);
                        alt_mt_bypass = false;
                    }
                    alt_mt_pending_active = true;
                } else if (timer_elapsed(alt_mt_timer) < TAPPING_TERM) {
                    tap_code(mt_alt_base_key(keycode));
                } else {
                    unregister_code16(get_nameraka_alt_keycode());
                }
                alt_mt_key = 0;
            }
            unregister_code16(get_nameraka_alt_keycode());
            return false;
        }
    }

    if (keycode == NMK_LALT) {
        if (record->event.pressed) {
            register_code16(get_nameraka_alt_keycode());
        } else {
            unregister_code16(get_nameraka_alt_keycode());
        }
        return false;
    }



    // Handle interruptions for Custom Alt Mod-Tap (Permissive Hold + Chordal Hold)
    if (record->event.pressed && alt_mt_key != 0) {
        char other_hand = get_key_handedness(record);

        // Same hand -> treat as tap (rolling)
        if (alt_mt_hand == other_hand) {
            alt_mt_key = 0;
            tap_code(mt_alt_base_key(keycode));
        } else {
            // Opposite hands: defer decision until we know rolling vs nested
            if (alt_mt_pending_keycode == 0) {
                alt_mt_pending_keycode = keycode;
                alt_mt_pending_original = 0;
                alt_mt_pending_record = *record;
                return false; // Block the keypress
            } else {
                // Second interrupt while pending - resolve as hold
                register_code16(get_nameraka_alt_keycode());

                if (alt_mt_pending_original != 0) {
                    // Nested MT: register base key
                    register_code16(alt_mt_pending_keycode);
                    alt_mt_pending_active = true;
                } else {
                    // Normal/Layer Key: Replay full record to activate layers
                    alt_mt_bypass = true;
                    process_record(&alt_mt_pending_record);
                    alt_mt_bypass = false;

                    // We handed off the key to QMK, so we are done with it.
                    alt_mt_pending_keycode = 0;
                    alt_mt_pending_original = 0;
                    alt_mt_pending_active = false;
                }

                alt_mt_timer = 0;
                // Let this new key through normally with Alt held
            }
        }
    }


    /* if (!process_layer_lock(keycode, record, LAYER_LOCK)) { */
    /*     return false; */
    /* } */

    if (record->event.pressed) {
        // General implementation for combos - makes it possible to do macros and other more complicated stuff.
        if (keycode == KEY_AA) {
            tap_code16(SE_ARNG);
            return true;
        }

        if (keycode == KEY_AE) {
            tap_code16(SE_ADIA);
            return true;
        }

        // JS
        if (keycode == JS_ARROW_FN) {
            // = () => {}
            tap_code(KC_SPC);
            tap_code16(SE_EQL);
            tap_code(KC_SPC);
            tap_code16(SE_LPRN);
            tap_code16(SE_RPRN);
            tap_code(KC_SPC);
            tap_code16(SE_EQL);

            tap_code16(SE_RABK);
            tap_code16(KC_SPC);
            tap_code16(se_lcbr_runtime());  // {
            tap_code16(se_rcbr_runtime());  // }
            tap_code(KC_LEFT);
            goto bail_false;
        }

        if (keycode == JS_USE_EFCT) {
            int i;
            // (() => {}, [])
            tap_code16(SE_LPRN); // (
            tap_code16(SE_LPRN);
            tap_code16(SE_RPRN);
            tap_code(KC_SPC);
            tap_code16(SE_EQL);

            tap_code16(SE_RABK);
            tap_code16(KC_SPC);
            tap_code16(se_lcbr_runtime()); // {
            tap_code16(se_rcbr_runtime()); // }

            tap_code16(KC_COMM);
            tap_code16(KC_SPC);

            tap_code16(se_lbrc_runtime()); // [
            tap_code16(se_rbrc_runtime()); // ]

            tap_code16(SE_RPRN); // )

            for (i=0; i<6; i++)
                tap_code(KC_LEFT);

            goto bail_false;
        }

        // OS Status - types "MAC" or "LIN" to show current detection
        if (keycode == OS_STATUS) {
            if (is_macos) {
                SEND_STRING("MAC");
            } else {
                SEND_STRING("LIN");
            }
            return false;
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

        PROCESS_SUB_RECORD(process_record_num);

        PROCESS_SUB_RECORD(process_record_programming);

        PROCESS_SUB_RECORD(process_record_navigation);

        PROCESS_SUB_RECORD(process_record_project);

        // Runtime translation of Linux SE keycodes for macOS (fallback if no macro handled it)
        if (is_macos) {
            uint16_t translated = 0;
            switch (keycode) {
                case ALGR(KC_7):    translated = S(A(KC_8)); break;  // {
                case ALGR(KC_0):    translated = S(A(KC_9)); break;  // }
                case ALGR(KC_8):    translated = A(KC_8);    break;  // [
                case ALGR(KC_9):    translated = A(KC_9);    break;  // ]
                case ALGR(KC_NUBS): translated = A(KC_7);    break;  // |
                case ALGR(KC_MINS): translated = S(A(KC_7)); break;  // backslash
            }
            if (translated) {
                tap_code16(translated);
                return false;
            }
        }
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
    case KEY_AA:
    case KEY_AE:
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

void u_td_fn_boot(tap_dance_state_t *state, void *user_data)
{
    if (state->count == 2) {
        reset_keyboard();
    }
}

#define NAMERAKA_X(LAYER, STRING)                                       \
    void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
        if (state->count == 2) {                                        \
            default_layer_set((layer_state_t)1 << U_##LAYER);           \
        }                                                               \
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
