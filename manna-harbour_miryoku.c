// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"
#include "features/layer_lock.h"

enum custom_keycodes {
    WIND_LEFT = SAFE_RANGE,
    WIND_RIGHT,
    WIND_UP,
    WIND_DOWN,
    WIND_MAX_TOGGLE,
    HELM_RESUME,
    LAYER_LOCK,
    /* Project keycodes */
    PRJ_FILES,
    PRJ_PROJS,
    PRJ_SEARCH,
    PERSP_BUF,
    MAGIT_STATUS,
    PRJ_OTHER_FILE,
    GO_TO,
    GO_BACK,
    LSP_FORMAT_REGION,
    LSP_REFERENCES,
    LSP_RENAME,    
    LSP_LENS,    
    FLYCHECK_NEXT_ERROR,
    FLYCHECK_PREV_ERROR,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    const uint8_t mods = get_mods();

    if (!process_layer_lock(keycode, record, LAYER_LOCK)) {
        return false;
    }

    if (record->event.pressed) {
        bool wind_move =
            (keycode == WIND_LEFT) || 
            (keycode == WIND_DOWN) || 
            (keycode == WIND_UP) || 
            (keycode == WIND_RIGHT);
        
        if (wind_move) {
            clear_mods();
#if 0
            if ((((mods) & MOD_MASK_CSA) == MOD_MASK_CSA) && (keycode == WIND_RIGHT)) {
                tap_code16(A(G(KC_5)));
                goto bail_false;
            }
            if ((((mods) & MOD_MASK_CSA) == MOD_MASK_CSA) && (keycode == WIND_LEFT)) {
                tap_code16(A(G(KC_4)));
                goto bail_false;
            }
#endif
            
            SEND_STRING(SS_LCTL("b"));
            
            if (((mods) & MOD_MASK_GUI) && (keycode == WIND_RIGHT)) {
                tap_code16(C(KC_RIGHT));
                goto bail_false;
            }
            if (((mods) & MOD_MASK_GUI) && (keycode == WIND_LEFT)) {
                tap_code16(C(KC_LEFT));
                goto bail_false;
            }
            if (((mods) & MOD_MASK_GUI) && (keycode == WIND_UP)) {
                tap_code16(C(KC_UP));
                goto bail_false;
            }
            if (((mods) & MOD_MASK_GUI) && (keycode == WIND_DOWN)) {
                tap_code16(C(KC_DOWN));
                goto bail_false;
            }
            
            if (((mods) & MOD_MASK_ALT) && (keycode == WIND_RIGHT)) {
                SEND_STRING("%");
                goto bail_false;
            }

            if (((mods) & MOD_MASK_ALT) && (keycode == WIND_DOWN)) {
                tap_code16(SE_DQUO);
                goto bail_false;
            }
            
            if ((mods) & MOD_MASK_CTRL)
                SEND_STRING("b");
            
            switch(keycode) {
            case WIND_LEFT:
                tap_code16(KC_LEFT);
                goto bail_false;
            case WIND_DOWN:
                tap_code16(KC_DOWN);
                goto bail_false;
            case WIND_UP:
                tap_code16(KC_UP);
                goto bail_false;
            case WIND_RIGHT:
                tap_code16(KC_RIGHT);
                goto bail_false;
            }
        }

        if (keycode == WIND_MAX_TOGGLE) {
            SEND_STRING(SS_LCTL("b"));
            SEND_STRING("z");
            goto bail_false;
        }

        if (keycode == HELM_RESUME) {
            SEND_STRING(SS_LCTL("x"));
            SEND_STRING("c");
            SEND_STRING("b");
            goto bail_false;
        }

        if (keycode == PRJ_FILES) {
            SEND_STRING(SS_LCTL("c"));
            SEND_STRING("pf");
            goto bail_false;
        }

        if (keycode == PRJ_PROJS) {
            SEND_STRING(SS_LCTL("c"));
            SEND_STRING("pp");
            goto bail_false;
        }

        if (keycode == PRJ_SEARCH) {
            SEND_STRING(SS_LCTL("c"));
            SEND_STRING("pss");
            goto bail_false;
        }

        if (keycode == PRJ_OTHER_FILE) {
            SEND_STRING(SS_LCTL("c"));
            SEND_STRING("pa");
            goto bail_false;
        }

        if (keycode == PERSP_BUF) {
            SEND_STRING(SS_LCTL("x"));
            SEND_STRING(SS_LCTL("b"));
            goto bail_false;
        }

        if (keycode == MAGIT_STATUS) {
            SEND_STRING(SS_LCTL("x"));
            SEND_STRING("g");
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
            SEND_STRING(SS_LCTL(SS_LSFT(".")));
            tap_code16(SE_EQL);
            SEND_STRING("r");
            goto bail_false;
        }

        if (keycode == LSP_REFERENCES) {
            SEND_STRING(SS_LCTL(SS_LSFT(".")));
            SEND_STRING("gr");
            goto bail_false;
        }

        if (keycode == LSP_RENAME) {
            SEND_STRING(SS_LCTL(SS_LSFT(".")));
            SEND_STRING("rr");
            goto bail_false;
        }

        if (keycode == LSP_LENS) {
            SEND_STRING(SS_LCTL(SS_LSFT(".")));
            SEND_STRING("Tl");
            goto bail_false;
        }
        
        if (keycode == FLYCHECK_NEXT_ERROR) {
            SEND_STRING(SS_LCTL("c"));
            SEND_STRING("!n");
            goto bail_false;
        }
        
        if (keycode == FLYCHECK_PREV_ERROR) {
            SEND_STRING(SS_LCTL("c"));
            SEND_STRING("!p");
            goto bail_false;
        }
    }

    return true;
    
bail_false:
    set_mods(mods);
    return false;
};


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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_DEVELOP, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
  #if defined (MIRYOKU_LAYERS_FLIP)
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
  #if defined (MIRYOKU_LAYERS_FLIP)
  COMBO(thumbcombos_sym, KC_RPRN),
  #else
  COMBO(thumbcombos_sym, KC_LPRN),
  #endif
  COMBO(thumbcombos_fun, KC_APP)
};
#endif
