// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// compile artifacts: qmk compile --compiledb -kb keebio/iris_lm/k1 -km jack
#include "action_layer.h"
#include "color.h"
#include "keycodes.h"
#include "quantum.h"
#include "rgb_matrix.h"

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
//    ┌──────────────┬────────────────┬───────────┬───────────┬─────────────────┬───────────────┐                         ┌────────────────┬───────────────┬───────────┬───────────┬────────────────┬────┐
//    │      0       │       1        │     2     │     3     │        4        │       5       │                         │       6        │       7       │     8     │     9     │  DF(_GAMING)   │ no │
//    ├──────────────┼────────────────┼───────────┼───────────┼─────────────────┼───────────────┤                         ├────────────────┼───────────────┼───────────┼───────────┼────────────────┼────┤
//    │     lsft     │       q        │     w     │     f     │        p        │       b       │                         │       j        │       l       │     u     │     y     │       '        │ no │
//    ├──────────────┼────────────────┼───────────┼───────────┼─────────────────┼───────────────┤                         ├────────────────┼───────────────┼───────────┼───────────┼────────────────┼────┤
//    │     tab      │   LGUI_T(a)    │ LALT_T(r) │ LCTL_T(s) │    LSFT_T(t)    │       g       │                         │       m        │   LSFT_T(n)   │ LCTL_T(e) │ LALT_T(i) │   LGUI_T(o)    │ no │
//    ├──────────────┼────────────────┼───────────┼───────────┼─────────────────┼───────────────┼─────────┬───────────────┼────────────────┼───────────────┼───────────┼───────────┼────────────────┼────┤
//    │ LCTL_T(caps) │ LT(_BUTTON, z) │ ALGR_T(x) │     c     │        d        │       v       │   no    │      no       │       k        │       h       │     ,     │ ALGR_T(.) │ LT(_BUTTON, /) │ no │
//    └──────────────┴────────────────┴───────────┴───────────┼─────────────────┼───────────────┼─────────┼───────────────┼────────────────┼───────────────┼───────────┴───────────┴────────────────┴────┘
//                                                            │ LT(_MEDIA, esc) │ LT(_NAV, spc) │ CW_TOGG │ LT(_SYM, ent) │ LT(_NUM, bspc) │ LT(_FUN, del) │
//                                                            └─────────────────┴───────────────┴─────────┴───────────────┴────────────────┴───────────────┘
[_COLEMAK] = LAYOUT(
  KC_0            , KC_1              , KC_2         , KC_3         , KC_4               , KC_5             ,                              KC_6              , KC_7             , KC_8         , KC_9           , DF(_GAMING)          , KC_NO,
  KC_LSFT         , KC_Q              , KC_W         , KC_F         , KC_P               , KC_B             ,                              KC_J              , KC_L             , KC_U         , KC_Y           , KC_QUOT              , KC_NO,
  KC_TAB          , LGUI_T(KC_A)      , LALT_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T)       , KC_G             ,                              KC_M              , LSFT_T(KC_N)     , LCTL_T(KC_E) , LALT_T(KC_I)   , LGUI_T(KC_O)         , KC_NO,
  LCTL_T(KC_CAPS) , LT(_BUTTON, KC_Z) , ALGR_T(KC_X) , KC_C         , KC_D               , KC_V             , KC_NO   , KC_NO            , KC_K              , KC_H             , KC_COMM      , ALGR_T(KC_DOT) , LT(_BUTTON, KC_SLSH) , KC_NO,
                                                                      LT(_MEDIA, KC_ESC) , LT(_NAV, KC_SPC) , CW_TOGG , LT(_SYM, KC_ENT) , LT(_NUM, KC_BSPC) , LT(_FUN, KC_DEL)
),

//    ┌──────┬───┬───┬───┬─────┬─────┐               ┌──────┬─────┬───┬───┬──────────────┬──────┐
//    │  0   │ 1 │ 2 │ 3 │  4  │  5  │               │  6   │  7  │ 8 │ 9 │ DF(_COLEMAK) │  no  │
//    ├──────┼───┼───┼───┼─────┼─────┤               ├──────┼─────┼───┼───┼──────────────┼──────┤
//    │ lsft │ q │ w │ e │  r  │  t  │               │  y   │  u  │ i │ o │      p       │ del  │
//    ├──────┼───┼───┼───┼─────┼─────┤               ├──────┼─────┼───┼───┼──────────────┼──────┤
//    │ tab  │ a │ s │ d │  f  │  g  │               │  h   │  j  │ k │ l │      ;       │  '   │
//    ├──────┼───┼───┼───┼─────┼─────┼─────────┬─────┼──────┼─────┼───┼───┼──────────────┼──────┤
//    │ lctl │ z │ x │ c │  v  │  b  │  home   │ end │  n   │  m  │ , │ . │      /       │ rsft │
//    └──────┴───┴───┴───┼─────┼─────┼─────────┼─────┼──────┼─────┼───┴───┴──────────────┴──────┘
//                       │ esc │ spc │ CW_TOGG │ ent │ bspc │ del │
//                       └─────┴─────┴─────────┴─────┴──────┴─────┘
[_GAMING] = LAYOUT(
  KC_0    , KC_1 , KC_2 , KC_3 , KC_4   , KC_5   ,                    KC_6    , KC_7   , KC_8    , KC_9   , DF(_COLEMAK) , KC_NO  ,
  KC_LSFT , KC_Q , KC_W , KC_E , KC_R   , KC_T   ,                    KC_Y    , KC_U   , KC_I    , KC_O   , KC_P         , KC_DEL ,
  KC_TAB  , KC_A , KC_S , KC_D , KC_F   , KC_G   ,                    KC_H    , KC_J   , KC_K    , KC_L   , KC_SCLN      , KC_QUOT,
  KC_LCTL , KC_Z , KC_X , KC_C , KC_V   , KC_B   , KC_HOME , KC_END , KC_N    , KC_M   , KC_COMM , KC_DOT , KC_SLSH      , KC_RSFT,
                                 KC_ESC , KC_SPC , CW_TOGG , KC_ENT , KC_BSPC , KC_DEL
),

//    ┌──────┬────────────────┬───────────┬───────────┬─────────────────┬───────────────┐                         ┌────────────────┬───────────────┬───────────┬───────────┬────────────────┬────┐
//    │  0   │       1        │     2     │     3     │        4        │       5       │                         │       6        │       7       │     8     │     9     │       no       │ no │
//    ├──────┼────────────────┼───────────┼───────────┼─────────────────┼───────────────┤                         ├────────────────┼───────────────┼───────────┼───────────┼────────────────┼────┤
//    │ lsft │       q        │     w     │     e     │        r        │       t       │                         │       y        │       u       │     i     │     o     │       p        │ no │
//    ├──────┼────────────────┼───────────┼───────────┼─────────────────┼───────────────┤                         ├────────────────┼───────────────┼───────────┼───────────┼────────────────┼────┤
//    │ tab  │   LGUI_T(a)    │ LALT_T(s) │ LCTL_T(d) │    LSFT_T(f)    │       g       │                         │       h        │   LSFT_T(j)   │ LCTL_T(k) │ LALT_T(l) │   LGUI_T(')    │ no │
//    ├──────┼────────────────┼───────────┼───────────┼─────────────────┼───────────────┼─────────┬───────────────┼────────────────┼───────────────┼───────────┼───────────┼────────────────┼────┤
//    │ lctl │ LT(_BUTTON, z) │ ALGR_T(x) │     c     │        v        │       b       │   no    │      no       │       n        │       m       │     ,     │ ALGR_T(.) │ LT(_BUTTON, /) │ no │
//    └──────┴────────────────┴───────────┴───────────┼─────────────────┼───────────────┼─────────┼───────────────┼────────────────┼───────────────┼───────────┴───────────┴────────────────┴────┘
//                                                    │ LT(_MEDIA, esc) │ LT(_NAV, spc) │ CW_TOGG │ LT(_SYM, ent) │ LT(_NUM, bspc) │ LT(_FUN, del) │
//                                                    └─────────────────┴───────────────┴─────────┴───────────────┴────────────────┴───────────────┘
[_EXTRA] = LAYOUT(
  KC_0    , KC_1              , KC_2         , KC_3         , KC_4               , KC_5             ,                              KC_6              , KC_7             , KC_8         , KC_9           , KC_NO                , KC_NO,
  KC_LSFT , KC_Q              , KC_W         , KC_E         , KC_R               , KC_T             ,                              KC_Y              , KC_U             , KC_I         , KC_O           , KC_P                 , KC_NO,
  KC_TAB  , LGUI_T(KC_A)      , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F)       , KC_G             ,                              KC_H              , LSFT_T(KC_J)     , LCTL_T(KC_K) , LALT_T(KC_L)   , LGUI_T(KC_QUOT)      , KC_NO,
  KC_LCTL , LT(_BUTTON, KC_Z) , ALGR_T(KC_X) , KC_C         , KC_V               , KC_B             , KC_NO   , KC_NO            , KC_N              , KC_M             , KC_COMM      , ALGR_T(KC_DOT) , LT(_BUTTON, KC_SLSH) , KC_NO,
                                                              LT(_MEDIA, KC_ESC) , LT(_NAV, KC_SPC) , CW_TOGG , LT(_SYM, KC_ENT) , LT(_NUM, KC_BSPC) , LT(_FUN, KC_DEL)
),

//    ┌──────┬───┬───┬───┬─────┬─────┐               ┌────────────────┬───────────────┬───┬───┬────┬────┐
//    │  0   │ 1 │ 2 │ 3 │  4  │  5  │               │       6        │       7       │ 8 │ 9 │ no │ no │
//    ├──────┼───┼───┼───┼─────┼─────┤               ├────────────────┼───────────────┼───┼───┼────┼────┤
//    │ lsft │ q │ w │ e │  r  │  t  │               │       y        │       u       │ i │ o │ p  │ no │
//    ├──────┼───┼───┼───┼─────┼─────┤               ├────────────────┼───────────────┼───┼───┼────┼────┤
//    │ tab  │ a │ s │ d │  f  │  g  │               │       h        │       j       │ k │ l │ '  │ no │
//    ├──────┼───┼───┼───┼─────┼─────┼─────────┬─────┼────────────────┼───────────────┼───┼───┼────┼────┤
//    │ lctl │ z │ x │ c │  v  │  b  │   no    │ no  │       n        │       m       │ , │ . │ /  │ no │
//    └──────┴───┴───┴───┼─────┼─────┼─────────┼─────┼────────────────┼───────────────┼───┴───┴────┴────┘
//                       │ esc │ spc │ CW_TOGG │ ent │ LT(_NUM, bspc) │ LT(_FUN, del) │
//                       └─────┴─────┴─────────┴─────┴────────────────┴───────────────┘
[_TAP] = LAYOUT(
  KC_0    , KC_1 , KC_2 , KC_3 , KC_4   , KC_5   ,                    KC_6              , KC_7             , KC_8    , KC_9   , KC_NO   , KC_NO,
  KC_LSFT , KC_Q , KC_W , KC_E , KC_R   , KC_T   ,                    KC_Y              , KC_U             , KC_I    , KC_O   , KC_P    , KC_NO,
  KC_TAB  , KC_A , KC_S , KC_D , KC_F   , KC_G   ,                    KC_H              , KC_J             , KC_K    , KC_L   , KC_QUOT , KC_NO,
  KC_LCTL , KC_Z , KC_X , KC_C , KC_V   , KC_B   , KC_NO   , KC_NO  , KC_N              , KC_M             , KC_COMM , KC_DOT , KC_SLSH , KC_NO,
                                 KC_ESC , KC_SPC , CW_TOGG , KC_ENT , LT(_NUM, KC_BSPC) , LT(_FUN, KC_DEL)
),

//    ┌──────┬──────┬──────┬──────┬───────┬────┐         ┌────┬───────┬──────┬──────┬──────┬────┐
//    │  0   │  1   │  2   │  3   │   4   │ 5  │         │ 6  │   7   │  8   │  9   │  no  │ no │
//    ├──────┼──────┼──────┼──────┼───────┼────┤         ├────┼───────┼──────┼──────┼──────┼────┤
//    │ lsft │  no  │ cut  │ copy │ paste │ no │         │ no │ paste │ copy │ cut  │  no  │ no │
//    ├──────┼──────┼──────┼──────┼───────┼────┤         ├────┼───────┼──────┼──────┼──────┼────┤
//    │ tab  │ lgui │ lalt │ lctl │ lsft  │ no │         │ no │ lsft  │ lctl │ lalt │ lgui │ no │
//    ├──────┼──────┼──────┼──────┼───────┼────┼────┬────┼────┼───────┼──────┼──────┼──────┼────┤
//    │ lctl │  no  │ cut  │ copy │ paste │ no │ no │ no │ no │ paste │ copy │ cut  │  no  │ no │
//    └──────┴──────┴──────┴──────┼───────┼────┼────┼────┼────┼───────┼──────┴──────┴──────┴────┘
//                                │  no   │ no │ no │ no │ no │  no   │
//                                └───────┴────┴────┴────┴────┴───────┘
[_BUTTON] = LAYOUT(
  KC_0    , KC_1    , KC_2    , KC_3    , KC_4     , KC_5  ,                 KC_6  , KC_7     , KC_8    , KC_9    , KC_NO   , KC_NO,
  KC_LSFT , KC_NO   , KC_CUT  , KC_COPY , KC_PASTE , KC_NO ,                 KC_NO , KC_PASTE , KC_COPY , KC_CUT  , KC_NO   , KC_NO,
  KC_TAB  , KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT  , KC_NO ,                 KC_NO , KC_LSFT  , KC_LCTL , KC_LALT , KC_LGUI , KC_NO,
  KC_LCTL , KC_NO   , KC_CUT  , KC_COPY , KC_PASTE , KC_NO , KC_NO , KC_NO , KC_NO , KC_PASTE , KC_COPY , KC_CUT  , KC_NO   , KC_NO,
                                          KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO
),

//    ┌──────┬──────┬──────┬──────┬──────┬────┐          ┌──────┬───────┬──────┬──────┬─────────┬────┐
//    │  0   │  1   │  2   │  3   │  4   │ 5  │          │  6   │   7   │  8   │  9   │   no    │ no │
//    ├──────┼──────┼──────┼──────┼──────┼────┤          ├──────┼───────┼──────┼──────┼─────────┼────┤
//    │ lsft │  no  │  no  │  no  │  no  │ no │          │  no  │ paste │ copy │ cut  │  undo   │ no │
//    ├──────┼──────┼──────┼──────┼──────┼────┤          ├──────┼───────┼──────┼──────┼─────────┼────┤
//    │ tab  │ lgui │ lalt │ lctl │ lsft │ no │          │ left │ down  │  up  │ rght │ CW_TOGG │ no │
//    ├──────┼──────┼──────┼──────┼──────┼────┼────┬─────┼──────┼───────┼──────┼──────┼─────────┼────┤
//    │ lctl │  no  │ aLGR │  no  │  no  │ no │ no │ no  │ home │ pgdn  │ pgup │  no  │   no    │ no │
//    └──────┴──────┴──────┴──────┼──────┼────┼────┼─────┼──────┼───────┼──────┴──────┴─────────┴────┘
//                                │  no  │ no │ no │ ent │ bspc │  del  │
//                                └──────┴────┴────┴─────┴──────┴───────┘
[_NAV] = LAYOUT(
  KC_0    , KC_1    , KC_2    , KC_3    , KC_4    , KC_5  ,                  KC_6    , KC_7     , KC_8    , KC_9    , KC_NO   , KC_NO,
  KC_LSFT , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,                  KC_NO   , KC_PASTE , KC_COPY , KC_CUT  , KC_UNDO , KC_NO,
  KC_TAB  , KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO ,                  KC_LEFT , KC_DOWN  , KC_UP   , KC_RGHT , CW_TOGG , KC_NO,
  KC_LCTL , KC_NO   , KC_ALGR , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO  , KC_HOME , KC_PGDN  , KC_PGUP , KC_NO   , KC_NO   , KC_NO,
                                          KC_NO   , KC_NO , KC_NO , KC_ENT , KC_BSPC , KC_DEL
),

//    ┌──────┬──────┬──────┬──────┬──────┬────┐           ┌──────┬──────┬──────┬──────┬─────────┬────┐
//    │  0   │  1   │  2   │  3   │  4   │ 5  │           │  6   │  7   │  8   │  9   │   no    │ no │
//    ├──────┼──────┼──────┼──────┼──────┼────┤           ├──────┼──────┼──────┼──────┼─────────┼────┤
//    │ lsft │  no  │  no  │  no  │  no  │ no │           │  no  │  no  │  no  │  no  │   no    │ no │
//    ├──────┼──────┼──────┼──────┼──────┼────┤           ├──────┼──────┼──────┼──────┼─────────┼────┤
//    │ tab  │ lgui │ lalt │ lctl │ lsft │ no │           │ mprv │ vold │ volu │ mnxt │   no    │ no │
//    ├──────┼──────┼──────┼──────┼──────┼────┼────┬──────┼──────┼──────┼──────┼──────┼─────────┼────┤
//    │ lctl │  no  │ aLGR │  no  │  no  │ no │ no │  no  │  no  │  no  │  no  │  no  │ OU_AUTO │ no │
//    └──────┴──────┴──────┴──────┼──────┼────┼────┼──────┼──────┼──────┼──────┴──────┴─────────┴────┘
//                                │  no  │ no │ no │ mstp │ mply │ mute │
//                                └──────┴────┴────┴──────┴──────┴──────┘
[_MEDIA] = LAYOUT(
  KC_0    , KC_1    , KC_2    , KC_3    , KC_4    , KC_5  ,                   KC_6    , KC_7    , KC_8    , KC_9    , KC_NO   , KC_NO,
  KC_LSFT , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO ,                   KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO,
  KC_TAB  , KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO ,                   KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT , KC_NO   , KC_NO,
  KC_LCTL , KC_NO   , KC_ALGR , KC_NO   , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , OU_AUTO , KC_NO,
                                          KC_NO   , KC_NO , KC_NO , KC_MSTP , KC_MPLY , KC_MUTE
),

//    ┌──────┬───┬───┬───┬───┬───┐         ┌────┬──────┬──────┬──────┬──────┬────┐
//    │  0   │ 1 │ 2 │ 3 │ 4 │ 5 │         │ 6  │  7   │  8   │  9   │  no  │ no │
//    ├──────┼───┼───┼───┼───┼───┤         ├────┼──────┼──────┼──────┼──────┼────┤
//    │ lsft │ [ │ 7 │ 8 │ 9 │ ] │         │ no │  no  │  no  │  no  │  no  │ no │
//    ├──────┼───┼───┼───┼───┼───┤         ├────┼──────┼──────┼──────┼──────┼────┤
//    │ tab  │ ; │ 4 │ 5 │ 6 │ = │         │ no │ lsft │ lctl │ lalt │ lgui │ no │
//    ├──────┼───┼───┼───┼───┼───┼────┬────┼────┼──────┼──────┼──────┼──────┼────┤
//    │ lctl │ ` │ 1 │ 2 │ 3 │ \ │ no │ no │ no │  no  │  no  │ aLGR │  no  │ no │
//    └──────┴───┴───┴───┼───┼───┼────┼────┼────┼──────┼──────┴──────┴──────┴────┘
//                       │ . │ 0 │ -  │ 0  │ -  │  no  │
//                       └───┴───┴────┴────┴────┴──────┘
[_NUM] = LAYOUT(
  KC_0    , KC_1    , KC_2 , KC_3 , KC_4   , KC_5    ,                   KC_6    , KC_7    , KC_8    , KC_9    , KC_NO   , KC_NO,
  KC_LSFT , KC_LBRC , KC_7 , KC_8 , KC_9   , KC_RBRC ,                   KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO,
  KC_TAB  , KC_SCLN , KC_4 , KC_5 , KC_6   , KC_EQL  ,                   KC_NO   , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI , KC_NO,
  KC_LCTL , KC_GRV  , KC_1 , KC_2 , KC_3   , KC_BSLS , KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_ALGR , KC_NO   , KC_NO,
                                    KC_DOT , KC_0    , KC_MINS , KC_0  , KC_MINS , KC_NO
),

//    ┌──────┬───┬───┬───┬───┬───┐         ┌────┬──────┬──────┬──────┬──────┬────┐
//    │  0   │ 1 │ 2 │ 3 │ 4 │ 5 │         │ 6  │  7   │  8   │  9   │  no  │ no │
//    ├──────┼───┼───┼───┼───┼───┤         ├────┼──────┼──────┼──────┼──────┼────┤
//    │ lsft │ { │ & │ * │ ( │ } │         │ no │  no  │  no  │  no  │  no  │ no │
//    ├──────┼───┼───┼───┼───┼───┤         ├────┼──────┼──────┼──────┼──────┼────┤
//    │ tab  │ : │ ^ │ % │ $ │ + │         │ no │ lsft │ lctl │ lalt │ lgui │ no │
//    ├──────┼───┼───┼───┼───┼───┼────┬────┼────┼──────┼──────┼──────┼──────┼────┤
//    │ lctl │ ~ │ ! │ @ │ # │ | │ no │ no │ no │  no  │  no  │ aLGR │  no  │ no │
//    └──────┴───┴───┴───┼───┼───┼────┼────┼────┼──────┼──────┴──────┴──────┴────┘
//                       │ ( │ ) │ _  │ no │ no │  no  │
//                       └───┴───┴────┴────┴────┴──────┘
[_SYM] = LAYOUT(
  KC_0    , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                   KC_6  , KC_7    , KC_8    , KC_9    , KC_NO   , KC_NO,
  KC_LSFT , KC_LCBR , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR ,                   KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO,
  KC_TAB  , KC_COLN , KC_CIRC , KC_PERC , KC_DLR  , KC_PLUS ,                   KC_NO , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI , KC_NO,
  KC_LCTL , KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_PIPE , KC_NO   , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_ALGR , KC_NO   , KC_NO,
                                          KC_LPRN , KC_RPRN , KC_UNDS , KC_NO , KC_NO , KC_NO
),

//    ┌──────┬─────┬────┬────┬─────┬──────┐              ┌────┬──────┬──────┬──────┬──────┬────┐
//    │  0   │  1  │ 2  │ 3  │  4  │  5   │              │ 6  │  7   │  8   │  9   │  no  │ no │
//    ├──────┼─────┼────┼────┼─────┼──────┤              ├────┼──────┼──────┼──────┼──────┼────┤
//    │ lsft │ f12 │ f7 │ f8 │ f9  │ pscr │              │ no │  no  │  no  │  no  │  no  │ no │
//    ├──────┼─────┼────┼────┼─────┼──────┤              ├────┼──────┼──────┼──────┼──────┼────┤
//    │ tab  │ f11 │ f4 │ f5 │ f6  │ sCRL │              │ no │ lsft │ lctl │ lalt │ lgui │ no │
//    ├──────┼─────┼────┼────┼─────┼──────┼─────────┬────┼────┼──────┼──────┼──────┼──────┼────┤
//    │ lctl │ f10 │ f1 │ f2 │ f3  │ paus │ QK_BOOT │ no │ no │  no  │  no  │ aLGR │  no  │ no │
//    └──────┴─────┴────┴────┼─────┼──────┼─────────┼────┼────┼──────┼──────┴──────┴──────┴────┘
//                           │ app │ spc  │   tab   │ no │ no │  no  │
//                           └─────┴──────┴─────────┴────┴────┴──────┘
[_FUN] = LAYOUT(
  KC_0    , KC_1   , KC_2  , KC_3  , KC_4   , KC_5    ,                   KC_6  , KC_7    , KC_8    , KC_9    , KC_NO   , KC_NO,
  KC_LSFT , KC_F12 , KC_F7 , KC_F8 , KC_F9  , KC_PSCR ,                   KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO,
  KC_TAB  , KC_F11 , KC_F4 , KC_F5 , KC_F6  , KC_SCRL ,                   KC_NO , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI , KC_NO,
  KC_LCTL , KC_F10 , KC_F1 , KC_F2 , KC_F3  , KC_PAUS , QK_BOOT , KC_NO , KC_NO , KC_NO   , KC_NO   , KC_ALGR , KC_NO   , KC_NO,
                                     KC_APP , KC_SPC  , KC_TAB  , KC_NO , KC_NO , KC_NO
)
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    // the c compiler has my back surely
    hsv_t cinnamon = (hsv_t){2, 110, 240};
    hsv_t apricot = (hsv_t){0, 82 , 255};
    hsv_t tuscan = (hsv_t){23, 89, 255};
    hsv_t parchment = (hsv_t){44, 74, 255};
    hsv_t mint = (hsv_t){78, 64, 255};
    hsv_t oceanic = (hsv_t){124, 230, 209};
    hsv_t winter = (hsv_t){131, 99, 255};
    hsv_t blue = (hsv_t){113, 196, 255};
    hsv_t purple = (hsv_t){175, 77, 255};
    // hsv_t sugar = (hsv_t){212, 56, 255};

    // The reason it isn't working on the slave is this matrix_rows calculation
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            hsv_t hsv = {0, 0, 0};
            bool set = false;

            // Set hsv color
            if (host_keyboard_led_state().caps_lock) {
                hsv = (hsv_t){HSV_RED};
                set = true;
            } else if (is_caps_word_on()) {
                set = true;
                hsv = (hsv_t){HSV_PINK};
            } else if (layer > 0) {
                set = true;
                switch(layer) {
                    case 1:
                        hsv = cinnamon;
                        break;
                    case 2:
                        hsv = apricot;
                        break;
                    case 3:
                        hsv = tuscan;
                        break;
                    case 4:
                        hsv = parchment;
                        break;
                    case 5:
                        hsv = mint;
                        break;
                    case 6:
                        hsv = oceanic;
                        break;
                    case 7:
                        hsv = winter;
                        break;
                    case 8:
                        hsv = blue;
                        break;
                    case 9:
                        hsv = purple;
                        break;
                    default:
                        hsv = (hsv_t){HSV_CORAL};
                }
            }

            // This function applies the effect only to configured keycodes
            // if (index >= led_min && index < led_max && index != NO_LED &&
            //         keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                // Limit brightness to driver max
                if (hsv.v > rgb_matrix_get_val()) {
                    hsv.v = rgb_matrix_get_val();
                }
                rgb_t converted = hsv_to_rgb(hsv);
                if (set) {
                    rgb_matrix_set_color(index, converted.r, converted.g, converted.b);
                }
            // }
        }
    }
    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
    hsv_t sugar = (hsv_t){212, 56, 255};
    rgb_matrix_sethsv(sugar.h, sugar.s, rgb_matrix_get_val());
}
