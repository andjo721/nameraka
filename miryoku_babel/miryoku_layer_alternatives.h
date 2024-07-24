// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-
// target: qmk

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// SPLIT 3x6

// Base layers
// Can be switched between using the <DF> keys located in the media layer.
// Which are BASE EXTRA and TAPPED may be specified using build time command line settings, for example by appending:
// -e MIRYOKU_ALPHAS=QWERTY -e MIRYOKU_EXTRA=COLEMAKDH -e MIRYOKU_TAP=QWERTY
#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH \
U_NP,          KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_MINS,               KC_LBRC, \
U_NP,          LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              HYPR_T(KC_M),      LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),          KC_QUOT, \
U_NP,          LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              MEH_T(KC_H),       KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_NUHS),  KC_SCLN, \
                                                     LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_PROJECT,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL)

#define MIRYOKU_ALTERNATIVES_BASE_QWERTY                                \
U_NP,          KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                  KC_LBRC, \
U_NP,          LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      HYPR_T(KC_G),        HYPR_T(KC_H),      RSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_COLN),       KC_QUOT, \
U_NP,          LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              MEH_T(KC_V),       KC_B,                KC_N,              MEH_T(KC_M),       KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),  KC_SCLN, \
                                                     LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_PROJECT,KC_TAB),  LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL)

#define MIRYOKU_ALTERNATIVES_TAP_QWERTY                                 \
KC_LALT,   KC_Q,  KC_W,    KC_E,    KC_R,              KC_T,              KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     KC_LBRC, \
KC_LCTL,   KC_A,  KC_S,    KC_D,    KC_F,              KC_G,              KC_H,    KC_J,     KC_K,     KC_L,    KC_COLN,  KC_QUOT, \
KC_LSFT,   KC_Z,  KC_X,    KC_C,    KC_V,              KC_B,              KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_SCLN, \
                          KC_ESC,  LT(U_NAV,KC_SPC),  KC_TAB,            KC_ENT,  KC_BSPC,  KC_DEL

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH                              \
U_NP,  KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,         KC_J,   KC_L,    KC_U,     KC_Y,    KC_QUOT,  U_NP, \
U_NP,  KC_A,  KC_R,  KC_S,  KC_T,  KC_G,         KC_M,   KC_N,    KC_E,     KC_I,    KC_O,     U_NP, \
U_NP,  KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,         KC_K,   KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,  U_NP, \
                   KC_ESC, KC_SPC, KC_TAB,       KC_ENT, KC_BSPC, KC_DEL

// ----------------
// Thumb key layers
// ----------------

// Left thumb key #1 (from inside)
// Emacs/Emacs Project
#define MIRYOKU_ALTERNATIVES_PROJECT \
U_NP,    LSP_FORMAT_REGION, U_NA,        U_NA,     VC_REVERT_HUNK, U_NA,                 LSP_TYPE_DEFINITION,   LSP_REFERENCES,      CCLS_CALL_HIERARCHY,   CCLS_MEMBER_HIERARCHY, PRJ_PROJS,   U_NP, \
U_NP,       PRJ_OTHER_FILE, PRJ_SEARCH,  U_NA,     PRJ_FILES,       MAGIT_STATUS,         HELM_RESUME,           GO_TO,               GO_BACK,               LSP_LENS, U_NP,        U_NP, \
U_NP,       U_NA,           U_NA,   S(KC_F12),     U_NA,            PERSP_BUF,            LSP_RENAME,            FLYCHECK_NEXT_ERROR, FLYCHECK_PREV_ERROR,   U_NP,     U_NP,        U_NP, \
                                         U_NA,     U_NA,            U_NA,                 C(SE_RABK),            U_NP,                U_NP

// Left thumb key #2 (from inside)
#define MIRYOKU_ALTERNATIVES_NAV \
U_NP,       U_NA,      U_NA,     U_NA,     U_NA,     U_NA,         WIND_MAX_TOGGLE,   WIND_LEFT,  WIND_DOWN,  WIND_UP,    WIND_RIGHT,  U_NP, \
U_NP,       KC_LGUI,   KC_LALT,  KC_LCTL,  KC_LSFT,  KC_HYPR,      CW_TOGG,           KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,     U_NP, \
U_NP,       U_NA,      KC_ALGR,  U_NA,     KC_MEH,   U_NA,         U_NP,              KC_END,     KC_PGDN,    KC_PGUP,    KC_HOME,     U_NP, \
                                 U_NA,     U_NA,     U_NA,         KC_ENT,            KC_BSPC,    KC_DEL

// Left thumb key #3 (from inside)
// 1. Media is also the only home of DFs - DFs and reset have been removed from all other layers
// 2. DT is also here for evaluating purposes.
//    Should be removed, or at least not built for release, when it is clear what the appropriate modifier delay is when I have become faster at typing on this keyboard.
// 3. Also, since it is for issuing commands of different kinds, I also have added GPT Emacs qmk macros here, since i foresee using my GPT package a lot.
//    I removed RGB support for this. This was the upper right row before my changes: RGB_TOG,   RGB_MOD,  RGB_HUI,  RGB_SAI,   RGB_VAI,

#define MIRYOKU_ALTERNATIVES_MEDIA                                      \
U_NP, TD(U_TD_BOOT), TD(U_TD_U_TAP),  TD(U_TD_U_EXTRA),    TD(U_TD_U_BASE),   DT_PRNT,  GPT_QUERY,        U_NU,     U_NU,     U_NU,      U_NU,  U_NP, \
U_NP,       KC_LGUI,        KC_LALT,           KC_LCTL,            KC_LSFT,      DT_UP, GPT_REPLY,     KC_MPRV,  KC_VOLD,  KC_VOLU,   KC_MNXT,  U_NP, \
U_NP,          U_NA,        KC_ALGR,    TD(U_TD_U_FUN),   TD(U_TD_U_MEDIA),    DT_DOWN,   OU_AUTO,        U_NU,     U_NU,     U_NU,      U_NU,  U_NP, \
                               U_NA,              U_NA,               U_NA,    KC_MSTP,   KC_MPLY,     KC_MUTE
// --------

// Right thumb key #1 (from inside)
#define MIRYOKU_ALTERNATIVES_SYM \
U_NP,       SE_LABK,  SE_AMPR,  SE_LCBR,   SE_RCBR,   SE_AT,              SE_SLSH,   SE_GRV,            SE_CIRC,        SE_ACUT,     SE_QUES,  U_NP, \
U_NP,       SE_RABK,  SE_DLR,   SE_LPRN,   SE_RPRN,   SE_SCLN,            SE_HASH,   SE_EQL,        LCTL_T(U_NA),   LALT_T(U_NA),  LGUI(U_NA),  U_NP, \
U_NP,       SE_PIPE,  SE_EXLM,  SE_LBRC,   SE_RBRC,   SE_COLN,            SE_BSLS,   KC_PERC,            SE_TILD,        KC_ALGR,        U_NA,  U_NP, \
                                SE_DQUO,   SE_SLSH,   SE_QUOT,            U_NA,      U_NA,                  U_NA

// Right thumb key #2 (from inside)
#define MIRYOKU_ALTERNATIVES_NUM \
U_NP,        SE_SLSH,  SE_7,   SE_8,   SE_9,   SE_MINS,       JS_ARROW_FN, U_NA,         U_NA,          U_NA,        U_NA,      U_NP, \
U_NP,        SE_ASTR,  SE_4,   SE_5,   SE_6,   SE_PLUS,       KC_HYPR,     KC_LSFT,      KC_LCTL,       KC_LALT,     KC_LGUI,   U_NP, \
U_NP,        SE_SECT,  SE_1,   SE_2,   SE_3,   SE_PERC,       U_NA,        KC_MEH,       U_NA,          KC_ALGR,     U_NA,      U_NP, \
                              SE_DOT,  SE_0,   SE_COLN,       U_NA,        U_NA,         U_NA

// Right thumb key #3 (from inside)
#define MIRYOKU_ALTERNATIVES_FUN \
U_NP,       KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,        U_NA,       U_NA,        U_NA,         U_NA,       U_NA,     U_NP, \
U_NP,       KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,        KC_HYPR,    KC_LSFT,     KC_LCTL,      KC_LALT,    KC_LGUI,  U_NP, \
U_NP,       KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,        U_NA,       KC_MEH,      U_NA,         U_NA,       U_NA,     U_NP, \
                           KC_APP,KC_SPC, KC_TAB,        U_NA,       U_NA,        U_NA


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
