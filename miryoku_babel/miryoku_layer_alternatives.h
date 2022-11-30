// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-
// target: qmk

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// SPLIT 3x6

#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH \
U_NP,          KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_MINS,               KC_LBRC, \
U_NP,          LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              HYPR_T(KC_M),      LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),          KC_QUOT, \
U_NP,          LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              MEH_T(KC_H),       KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_NUHS),  KC_SCLN, \
                                                     LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_PROJECT,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL)             

#define MIRYOKU_ALTERNATIVES_BASE_QWERTY \
U_NP,          KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                  KC_LBRC, \
U_NP,          LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      HYPR_T(KC_G),        HYPR_T(KC_H),      RSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_COLN),       KC_QUOT, \
U_NP,          LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              MEH_T(KC_V),       KC_B,                KC_N,              MEH_T(KC_M),       KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),  KC_SCLN, \
                                                     LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_PROJECT,KC_TAB),  LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL)

#define MIRYOKU_ALTERNATIVES_TAP_QWERTY \
U_NP,     KC_Q,  KC_W,    KC_E,    KC_R,              KC_T,              KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     KC_LBRC, \
U_NP,     KC_A,  KC_S,    KC_D,    KC_F,              KC_G,              KC_H,    KC_J,     KC_K,     KC_L,    KC_COLN,  KC_QUOT, \
U_NP,     KC_Z,  KC_X,    KC_C,    KC_V,              KC_B,              KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_SCLN, \
                          KC_ESC,  LT(U_NAV,KC_SPC),  KC_TAB,            KC_ENT,  KC_BSPC,  KC_DEL

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH \
U_NP,  KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,         KC_J,   KC_L,    KC_U,     KC_Y,    KC_QUOT,  U_NP, \
U_NP,  KC_A,  KC_R,  KC_S,  KC_T,  KC_G,         KC_M,   KC_N,    KC_E,     KC_I,    KC_O,     U_NP, \
U_NP,  KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,         KC_K,   KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,  U_NP, \
                   KC_ESC, KC_SPC, KC_TAB,       KC_ENT, KC_BSPC, KC_DEL



   // U_NP,       U_NA,     U_NA,       U_NA,     U_NA,     U_NA,          SE_SLSH,     SE_ASTR,     SE_MINS,  SE_PLUS,  SE_PERC,     U_NP,

#define MIRYOKU_ALTERNATIVES_PROJECT \
U_NP,       U_NA,           U_NA,        U_NA,     U_NA,            U_NA,                 U_NP,                  LSP_REFERENCES,      U_NP,                  U_NP,     PRJ_PROJS,   U_NP, \
U_NP,       PRJ_OTHER_FILE, PRJ_SEARCH,  U_NA,     PRJ_FILES,       MAGIT_STATUS,         LSP_FORMAT_REGION,     GO_TO,               GO_BACK,               LSP_LENS, U_NP,        U_NP, \
U_NP,       U_NA,           U_NA,   S(KC_F12),     U_NA,            PERSP_BUF,            LSP_RENAME,            FLYCHECK_NEXT_ERROR, FLYCHECK_PREV_ERROR,   U_NP,     U_NP,        U_NP, \
                                         U_NA,     U_NA,            U_NA,                 C(SE_RABK),            U_NP,                U_NP

#define MIRYOKU_ALTERNATIVES_NAV \
U_NP,       U_NA,      U_NA,     U_NA,     U_NA,     U_NA,         WIND_MAX_TOGGLE,   WIND_LEFT,  WIND_DOWN,  WIND_UP,    WIND_RIGHT,  LCTL(SE_MINS), \
U_NP,       KC_LGUI,   KC_LALT,  KC_LCTL,  KC_LSFT,  KC_HYPR,      CAPSWRD,           KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,     LCTL(SE_PLUS), \
U_NP,       U_NA,      KC_ALGR,  U_NA,     KC_MEH,   U_NA,         KC_INS,            KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,      HELM_RESUME, \
                                 U_NA,     U_NA,     U_NA,         KC_ENT,            KC_BSPC,    KC_DEL

// Media is also the home of DFs - DFs and reset have been removed from all other layers 
#define MIRYOKU_ALTERNATIVES_MEDIA \
U_NP,       RESET,    DF(U_TAP),  DF(U_EXTRA),  DF(U_BASE),   DT_PRNT,       RGB_TOG,   RGB_MOD,  RGB_HUI,  RGB_SAI,   RGB_VAI,  U_NP, \
U_NP,       KC_LGUI,  KC_LALT,    KC_LCTL,      KC_LSFT,      DT_UP,         U_NU,      KC_MPRV,  KC_VOLD,  KC_VOLU,   KC_MNXT,  U_NP, \
U_NP,       U_NA,     KC_ALGR,    DF(U_FUN),    DF(U_MEDIA),  DT_DOWN,       OUT_AUTO,  U_NU,     U_NU,     U_NU,      U_NU,     U_NP, \
                                  U_NA,         U_NA,         U_NA,          KC_MSTP,   KC_MPLY,  KC_MUTE

#define MIRYOKU_ALTERNATIVES_NUM \
U_NP,        SE_SLSH,  SE_7,   SE_8,   SE_9,   SE_MINS,       U_NA,      U_NA,         U_NA,          U_NA,        U_NA,      U_NP, \
U_NP,        SE_ASTR,  SE_4,   SE_5,   SE_6,   SE_PLUS,       KC_HYPR,   KC_LSFT,      KC_LCTL,       KC_LALT,     KC_LGUI,   U_NP, \
U_NP,        SE_SECT,  SE_1,   SE_2,   SE_3,   SE_PERC,       U_NA,      KC_MEH,       U_NA,          KC_ALGR,     U_NA,      U_NP, \
                              SE_DOT,  SE_0,   SE_COLN,       U_NA,      U_NA,         U_NA

#define MIRYOKU_ALTERNATIVES_EMPTY \
U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        \
U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        \
U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        \
                          U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP

#define MIRYOKU_ALTERNATIVES_BUTTON \
U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        \
U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        \
U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        \
                                       U_NP,        U_NP,        U_NP,        U_NP,        U_NP,        U_NP

#define MIRYOKU_ALTERNATIVES_FUN \
U_NP,       KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,        U_NA,       U_NA,        U_NA,         U_NA,       U_NA,     U_NP, \
U_NP,       KC_F11, KC_F4, KC_F5, KC_F6, KC_SLCK,        KC_HYPR,    KC_LSFT,     KC_LCTL,      KC_LALT,    KC_LGUI,  U_NP, \
U_NP,       KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,        U_NA,       KC_MEH,      U_NA,         U_NA,       U_NA,     U_NP, \
                           KC_APP,KC_SPC, KC_TAB,        U_NA,       U_NA,        U_NA

#define MIRYOKU_ALTERNATIVES_SYM_TWO \
U_NP,       SE_LABK,  SE_AMPR,  SE_LCBR,   SE_RCBR,   SE_AT,              SE_SLSH,   SE_TILD,   SE_CIRC,  U_NA,     SE_QUES,  U_NP, \
U_NP,       SE_RABK,  SE_DLR,   SE_LPRN,   SE_RPRN,   SE_SCLN,            SE_HASH,   SE_EQL,    U_NA,     U_NA,     U_NA,     U_NP, \
U_NP,       SE_PIPE,  SE_EXLM,  SE_LBRC,   SE_RBRC,   SE_COLN,            SE_BSLS,   KC_PERC,   SE_GRV,   KC_ALGR,  U_NA,     U_NP, \
                                SE_DQUO,   SE_SLSH,   SE_QUOT,            U_NA,      U_NA,      U_NA

//(projectile-run-term "/bin/bash")
