// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-
// target: qmk

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// SPLIT 3x6

#define MIRYOKU_ALTERNATIVES_BASE_COLEMAKDH \
U_NP,    KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_MINS,               KC_LBRC, \
KC_LCTL, LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              HYPR_T(KC_M),      LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),          KC_QUOT, \
KC_LSFT, LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              MEH_T(KC_H),       KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_NUHS),  KC_SCLN, \
                                               LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL)             

#define MIRYOKU_ALTERNATIVES_BASE_QWERTY \
U_NP,    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                  KC_LBRC, \
KC_LCTL, LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              HYPR_T(KC_H),      LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_COLN),       KC_QUOT, \
KC_LSFT, LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              MEH_T(KC_M),       KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),  KC_SCLN, \
                                               LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL)

#define MIRYOKU_ALTERNATIVES_TAP_QWERTY \
U_NP,    KC_Q,         KC_W,      KC_E,        KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              KC_LBRC, \
KC_LCTL, KC_A,         KC_S,      KC_D,        KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_COLN,           KC_QUOT, \
KC_LSFT, KC_Z,         KC_X,      KC_C,        KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_SCLN, \
                                  KC_ESC,      LT(U_NAV,KC_SPC),  KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL

#define MIRYOKU_ALTERNATIVES_TAP_COLEMAKDH \
U_NP, KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,               U_NP, \
U_NP, KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              KC_I,              KC_O,                  U_NP, \
U_NP, KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,               U_NP, \
                                            KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_BSPC,           KC_DEL

/* #define MIRYOKU_ALTERNATIVES_MOUSE \ */
/* U_NP, RESET,             DF(U_TAP),         DF(U_EXTRA),       DF(U_BASE),        U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                 U_NP, \ */
/* U_NP, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,               U_NP, \ */
/* U_NP, U_NA,              KC_ALGR,           DF(U_SYM),         DF(U_MOUSE),       U_NA,              U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,               U_NP, \ */
/*                                             U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3 */
// 123456789!"#¤%&/() var <>|&$!:;@_/"

#define MIRYOKU_ALTERNATIVES_MOUSE                                      \
U_NP, RESET,             DF(U_TAP),         DF(U_EXTRA),       DF(U_BASE),        U_NA,              LSFT(KC_7),        KC_PAST,           KC_PMNS,           KC_PPLS,        LSFT(KC_5),               U_NP,                                         \
U_NP, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,           LSFT(KC_0),              U_NP,              U_NP,              U_NP,               U_NP, \
U_NP, U_NA,              KC_ALGR,           DF(U_SYM),         DF(U_MOUSE),       U_NA,              U_NU,                 U_NP,              U_NP,              U_NP,              U_NP,               U_NP, \
                                            U_NA,              U_NA,              U_NA,              U_NP,                 U_NP,              U_NP

#define MIRYOKU_ALTERNATIVES_NAV \
U_NP, RESET,             DF(U_TAP),         DF(U_EXTRA),       DF(U_BASE),        DT_PRNT,           U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                 U_NP, \
U_NP, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           DT_UP,             KC_CAPS,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,               U_NP, \
U_NP, U_NA,              KC_ALGR,           DF(U_NUM),         DF(U_NAV),         DT_DOWN,           KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,                U_NP, \
                                            U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL

#define MIRYOKU_ALTERNATIVES_MEDIA \
U_NP, RESET,             DF(U_TAP),         DF(U_EXTRA),       DF(U_BASE),        U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,               U_NP, \
U_NP, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,               U_NP, \
U_NP, U_NA,              KC_ALGR,           DF(U_FUN),         DF(U_MEDIA),       U_NA,              OUT_AUTO,          U_NU,              U_NU,              U_NU,              U_NU,                  U_NP, \
                                            U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE

#define MIRYOKU_ALTERNATIVES_NUM                                        \
U_NP, KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         RESET,                 U_NP, \
U_NP, KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            KC_HYPR,           KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,               U_NP, \
U_NP, KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              KC_MEH,            U_NA,              KC_ALGR,           U_NA,                  U_NP, \
                                            KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA

/* #define MIRYOKU_ALTERNATIVES_BUTTON \ */
/* U_NP, U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                 U_NP, \ */
/* U_NP, KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,              U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,               U_NP, \ */
/* U_NP, U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,                 U_NP, \ */
/*                                             KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_BTN1,           KC_BTN3 */

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
U_NP, KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         RESET,                 U_NP, \
U_NP, KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SLCK,        KC_HYPR,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,               U_NP, \
U_NP, KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              KC_MEH,            U_NA,              KC_ALGR,           U_NA,                  U_NP, \
                                            KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA
/*
#define MIRYOKU_ALTERNATIVES_SYM_TWO \
U_NP, RALT(KC_2),        LSFT(KC_6),        LSFT(KC_8),        LSFT(KC_9),        KC_NUBS,           U_NA,              DF(U_BASE),        DF(U_EXTRA),       DF(U_TAP),         RESET,                 U_NP, \
U_NP, LSFT(KC_COMM),     RALT(KC_4),        RALT(KC_7),        RALT(KC_0),        LSFT(KC_NUBS),     U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,               U_NP, \
U_NP, LSFT(KC_DOT),      LSFT(KC_1),        RALT(KC_8),        RALT(KC_9),        RALT(KC_NUBS),     U_NA,              DF(U_SYM),         DF(U_MOUSE),       KC_ALGR,           U_NA,                  U_NP, \
                                            KC_LPRN,           KC_SLSH,           LSFT(KC_SLSH),     U_NA,              U_NA,              U_NA
*/

#define MIRYOKU_ALTERNATIVES_SYM_TWO \
U_NP, KC_NUBS,           LSFT(KC_6),        RALT(KC_7),        RALT(KC_0),        RALT(KC_2),                    LSFT(KC_7),             U_NA,            U_NA,              U_NA,              U_NA,               U_NP, \
U_NP, LSFT(KC_NUBS),     RALT(KC_4),        LSFT(KC_8),        LSFT(KC_9),        LSFT(KC_COMM),                 LSFT(KC_0),       LSFT(KC_3),            U_NA,              U_NA,              U_NA,               U_NP, \
U_NP, RALT(KC_NUBS),     LSFT(KC_1),        RALT(KC_8),        RALT(KC_9),        LSFT(KC_DOT),               RALT(KC_MINS),          KC_PERC,         KC_SLSH,           KC_ALGR,              U_NA,               U_NP, \
                                            LSFT(KC_2),        LSFT(KC_7),        KC_NUHS,                             U_NA,             U_NA,            U_NA

//=-%\\\%---%%\====*/-++-=
//dddfffdddssslxddddd \n\n

// ::;;;;:;.()???++
// ';''\\'''
