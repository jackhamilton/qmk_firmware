// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
    _COLEMAK,
    _GAMING,
    _EXTRA,
    _TAP,
    _BUTTON,
    _NAV,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
        KC_0,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,DF(_GAMING),KC_NO,\
        KC_LSFT,KC_Q,KC_W,KC_F,KC_P,KC_B,KC_J,KC_L,KC_U,KC_Y,KC_QUOT,KC_NO,\
        KC_TAB,LGUI_T(KC_A),LALT_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T),KC_G,KC_M,LSFT_T(KC_N),LCTL_T(KC_E),LALT_T(KC_I),LGUI_T(KC_O),KC_NO,\
        LCTL_T(KC_CAPS),LT(_BUTTON,KC_Z),ALGR_T(KC_X),KC_C,KC_D,KC_V,KC_NO,KC_NO,KC_K,KC_H,KC_COMM,ALGR_T(KC_DOT),LT(_BUTTON,KC_SLSH),KC_NO,\
        LT(_MEDIA,KC_ESC),LT(_NAV,KC_SPC),KC_LSFT,LT(_SYM,KC_ENT),LT(_NUM,KC_BSPC),LT(_FUN,KC_DEL)
    ),

    [_GAMING] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_0, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    DF(_COLEMAK),    KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_ESC, KC_SPC, KC_LSFT,                    KC_ENT,  KC_BSPC, KC_DEL

    ),

    [_EXTRA] = LAYOUT(
        KC_0,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_NO,                 KC_NO,\
        LSFT_T(KC_TAB),    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 KC_NO,\
        KC_TAB,            LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),      KC_NO,\
        KC_CAPS,           LT(_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_V,              KC_B, KC_NO, KC_NO,  KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(_BUTTON,KC_SLSH), KC_NO,\
        LT(_MEDIA,KC_ESC),LT(_NAV,KC_SPC),  KC_LSFT,           LT(_SYM,KC_ENT),  LT(_NUM,KC_BSPC), LT(_FUN,KC_DEL)
    ),

    [_TAP] = LAYOUT(
        KC_0,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_NO,    KC_NO,\
        KC_LSFT,           KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 KC_NO,\
        KC_TAB,            KC_A,              KC_S,              KC_D,              KC_F,              KC_G,              KC_H,              KC_J,              KC_K,              KC_L,              KC_QUOT,              KC_NO,\
        KC_LCTL,           KC_Z,              KC_X,              KC_C,              KC_V,              KC_B, KC_NO, KC_NO,  KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,              KC_NO,\
        KC_ESC,            KC_SPC,            KC_LSFT,           KC_ENT,            LT(_NUM,KC_BSPC), LT(_FUN,KC_DEL)
    ),

    [_BUTTON] = LAYOUT(
        KC_0,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_NO,                 KC_NO,\
        LSFT_T(KC_TAB),    KC_NO,              KC_CUT,             KC_COPY,             KC_PASTE,             /*u_rdo*/KC_NO,             /*u_rdo*/KC_NO,             KC_PASTE,             KC_COPY,             KC_CUT,             KC_NO,                 KC_NO,\
        KC_TAB,            KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_NO,              KC_NO,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              KC_NO,\
        KC_CAPS,           KC_NO,              KC_CUT,             KC_COPY,             KC_PASTE,             /*u_rdo*/KC_NO,  KC_NO, KC_NO,/*u_rdo*/KC_NO,             KC_PASTE,             KC_COPY,             KC_CUT,             KC_NO,                 KC_NO,\
        KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO
    ),

    [_NAV] = LAYOUT(
        KC_0,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_NO,                 KC_NO,\
        LSFT_T(KC_TAB),    KC_NO,     KC_NO,    KC_NO,  KC_NO,   KC_NO,              /*u_rdo*/KC_NO,             KC_PASTE,             KC_COPY,             KC_CUT,             KC_UNDO,                KC_NO,\
        KC_TAB,            KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_NO,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           CW_TOGG,              KC_NO,\
        KC_CAPS,           KC_NO,              KC_ALGR,           KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,  KC_HOME,           KC_PGDN,           KC_PGUP,           KC_NO,           KC_NO,               KC_NO,\
        KC_NO,              KC_NO,              KC_NO,              KC_ENT,            KC_BSPC,           KC_DEL
    ),

    [_MEDIA] = LAYOUT(
        KC_0,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_NO,                 KC_NO,\
        LSFT_T(KC_TAB),    KC_NO,     KC_NO,    KC_NO,  KC_NO,   KC_NO,              KC_NO,           KC_NO,           KC_NO,           KC_NO,           KC_NO,              KC_NO,\
        KC_TAB,            KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_NO,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           KC_NO,                 KC_NO,\
        KC_CAPS,           KC_NO,              KC_ALGR,           KC_NO,    KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO,              KC_NO,              KC_NO,              KC_NO,              OU_AUTO,              KC_NO,\
        KC_NO,              KC_NO,              KC_NO,              KC_MSTP,           KC_MPLY,           KC_MUTE
    ),

    [_NUM] = LAYOUT(
        KC_0,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_NO,                 KC_NO,\
        LSFT_T(KC_TAB),    KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           KC_NO,              KC_NO,   KC_NO,  KC_NO,    KC_NO,    KC_NO,\
        KC_TAB,            KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            KC_NO,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,          KC_NO,\
        KC_CAPS,           KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,KC_NO, KC_NO,KC_NO,              KC_NO,    KC_NO,    KC_ALGR,           KC_NO,             KC_NO,\
        KC_DOT,            KC_0,              KC_MINS,           KC_0,              KC_MINS,           KC_NO
    ),

    [_SYM] = LAYOUT(
        KC_0,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_NO,                 KC_NO,\
        LSFT_T(KC_TAB),    KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           KC_NO,              KC_NO,   KC_NO,  KC_NO,    KC_NO,        KC_NO,\
        KC_TAB,            KC_COLN,           KC_CIRC,           KC_PERC,           KC_DLR,            KC_PLUS,           KC_NO,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,              KC_NO,\
        KC_CAPS,           KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE, KC_NO, KC_NO, KC_NO,            KC_NO,    KC_NO, /* TD(U_TD_U_MOUSE), */  KC_ALGR,           KC_NO,     KC_NO,\
        KC_LPRN,           KC_RPRN,           KC_UNDS,           KC_NO,              KC_NO,              KC_NO
    ),

    [_FUN] = LAYOUT(
        KC_0,              KC_1,              KC_2,              KC_3,              KC_4,              KC_5,              KC_6,              KC_7,              KC_8,              KC_9,              KC_NO,                 KC_NO,\
        LSFT_T(KC_TAB),    KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           KC_NO,              KC_NO,   KC_NO,  KC_NO,    KC_NO,    KC_NO,\
        KC_TAB,            KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           KC_NO,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,          KC_NO,\
        KC_CAPS,           KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,KC_NO, KC_NO,KC_NO,              KC_NO,    KC_NO,  KC_ALGR,           KC_NO,             KC_NO,\
        KC_APP,            KC_SPC,            KC_TAB,            KC_NO,              KC_NO,              KC_NO
    )
};
