/* SPDX-License-Identifier: GPL-2.0-or-later */
#include QMK_KEYBOARD_H

enum layers {
   _QWERTY,
   _NAV,
   _MOUSE,
   _MEDIA,
   _NUM,
   _SYMB,
   _FUN,
   //_GAMING,
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define KC_MEEC LT(_MEDIA, KC_ESC)
#define KC_NASP LT(_NAV, KC_SPC)
#define KC_MSBS LT(_MOUSE, KC_BSPC)
#define KC_SYEN LT(_SYMB, KC_ENT)
#define KC_NUTB LT(_NUM, KC_TAB)
#define KC_FNDL LT(_FUN, KC_DEL)

#define KC_CTESC LCTL_T(KC_ESC)
#define KC_GUIA LGUI_T(KC_A)
#define KC_ALTS LALT_T(KC_S)
#define KC_CTLD LCTL_T(KC_D)
#define KC_SFTF LSFT_T(KC_F)
#define KC_GUIQ LGUI_T(KC_QUOT)
#define KC_ALTL LALT_T(KC_L)
#define KC_CTLK LCTL_T(KC_K)
#define KC_SFTJ LSFT_T(KC_J)

#define KC_GUPL LGUI_T(KC_PLUS)
#define KC_ATEQ LALT_T(KC_EQL)
#define KC_CTLP LCTL_T(KC_LPRN)
#define KC_SFRP LSFT_T(KC_RPRN)
#define KC_GUISY LGUI_T(KC_LCBR)
#define KC_ALTSY LALT_T(KC_RCBR)
#define KC_CTLSY LCTL_T(KC_LBRC)
#define KC_SFTSY LSFT_T(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_NAGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,SYM_L   ,                          SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_CTESC,KC_GUITA,KC_ALTS ,KC_CTLD ,KC_SFTF ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_SFTJ ,KC_CTLK ,KC_ALTL ,KC_GUIQ ,KC_SCLN ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
      //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
         KC_LCTL ,KC_LALT ,KC_LGUI ,KC_ALAS ,     KC_MEEC ,    KC_NASP ,KC_MSBS ,        KC_SYEN ,KC_NUTB ,    KC_FNDL ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
      //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_NAV] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_TRNS ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,SYM_L   ,                          SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_GUITA,KC_ALTS ,KC_CTLD ,KC_SFTF ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_SFTJ ,KC_CTLK ,KC_ALTL ,KC_GUIQ ,KC_SCLN ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
      //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_LALT ,KC_LGUI ,KC_ALAS ,     KC_MEEC ,    KC_NASP ,KC_MSBS ,        KC_SYEN ,KC_NUTB ,    KC_FNDL ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
      //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_MOUSE] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_TRNS ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,SYM_L   ,                          SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_GUITA,KC_ALTS ,KC_CTLD ,KC_SFTF ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_SFTJ ,KC_CTLK ,KC_ALTL ,KC_GUIQ ,KC_SCLN ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
      //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_LALT ,KC_LGUI ,KC_ALAS ,     KC_MEEC ,    KC_NASP ,KC_MSBS ,        KC_SYEN ,KC_NUTB ,    KC_FNDL ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
      //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_MEDIA] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_TRNS ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,SYM_L   ,                          SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_GUITA,KC_ALTS ,KC_CTLD ,KC_SFTF ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_SFTSY,KC_CTLSY,KC_ALTSY,KC_GUISY,KC_SCLN ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
      //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_LALT ,KC_LGUI ,KC_ALAS ,     KC_MEEC ,    KC_NASP ,KC_MSBS ,        KC_SYEN ,KC_NUTB ,    KC_FNDL ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
      //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_NUM] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_TRNS ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,SYM_L   ,                          SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_GUITA,KC_ALTS ,KC_CTLD ,KC_SFTF ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_SFTJ ,KC_CTLK ,KC_ALTL ,KC_GUIQ ,KC_SCLN ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
      //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_LALT ,KC_LGUI ,KC_ALAS ,     KC_MEEC ,    KC_NASP ,KC_MSBS ,        KC_SYEN ,KC_NUTB ,    KC_FNDL ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
      //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_SYMB] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_TRNS ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F0   ,KC_NAMI ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,SYM_L   ,                          SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_GUPL ,KC_ATEQ ,KC_CTLP ,KC_SFRP ,KC_DQUO ,KC_LBRC ,                          KC_RBRC ,KC_COLN ,KC_SFTSY,KC_CTLSY,KC_ALTSY,KC_GUISY,KC_SCLN ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_LT   ,KC_PIPE ,KC_MINS ,KC_GT   ,KC_BSLS ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_GRV    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
      //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_LALT ,KC_LGUI ,KC_ALAS ,     KC_MEEC ,    KC_NASP ,KC_MSBS ,        KC_SYEN ,KC_NUTB ,    KC_FNDL ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
      //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

	[_FUN] = LAYOUT(
      //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
         KC_TRNS ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,SYM_L   ,                          SYM_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_GUITA,KC_ALTS ,KC_CTLD ,KC_SFTF ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_SFTJ ,KC_CTLK ,KC_ALTL ,KC_GUIQ ,KC_SCLN ,
      //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
      //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
         KC_TRNS ,KC_LALT ,KC_LGUI ,KC_ALAS ,     KC_MEEC ,    KC_NASP ,KC_MSBS ,        KC_SYEN ,KC_NUTB ,    KC_FNDL ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
      //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	),

};
