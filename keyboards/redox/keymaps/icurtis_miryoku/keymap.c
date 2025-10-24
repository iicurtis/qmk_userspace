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

#if !defined(MIRYOKU_LAYER_LIST)

#    define MIRYOKU_LAYER_LIST      \
        MIRYOKU_X(BASE, "Base")     \
        MIRYOKU_X(EXTRA, "Extra")   \
        MIRYOKU_X(TAP, "Tap")       \
        MIRYOKU_X(BUTTON, "Button") \
        MIRYOKU_X(NAV, "Nav")       \
        MIRYOKU_X(MOUSE, "Mouse")   \
        MIRYOKU_X(MEDIA, "Media")   \
        MIRYOKU_X(NUM, "Num")       \
        MIRYOKU_X(SYM, "Sym")       \
        MIRYOKU_X(FUN, "Fun")

#endif

enum miryoku_layers {
#define MIRYOKU_X(LAYER, STRING) U_##LAYER,
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

#define MIRYOKU_X(LAYER, STRING)                                        \
    void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
        if (state->count == 2) {                                        \
            default_layer_set((layer_state_t)1 << U_##LAYER);           \
        }                                                               \
    }
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_U_BASE] = ACTION_TAP_DANCE_FN(u_td_fn_U_BASE),
};

// shift functions

const key_override_t  capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);
const key_override_t *key_overrides[]       = {&capsword_key_override};

// Key combos
const uint16_t PROGMEM combo_jk_esc[]  = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_uj_lprn[] = {KC_U, KC_J, COMBO_END};
combo_t                key_combos[]    = {
    COMBO(combo_jk_esc, KC_ESC),
    COMBO(combo_uj_lprn, KC_LPRN), // keycodes with modifiers are possible too!
};

// Shortcut to make keymap more readable
#define SYM_L MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_NAV, KC_END)
#define KC_ADPU LT(_NAV, KC_PGUP)
#define KC_ADPU LT(_NAV, KC_PGUP)

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
#define KC_GUIR LGUI_T(KC_SCLN)
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
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_NAGR, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NAMI,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, SYM_L, SYM_L, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_CTESC, KC_GUIA, KC_ALTS, KC_CTLD, KC_SFTF, KC_G, KC_LBRC, KC_RBRC, KC_H, KC_SFTJ, KC_CTLK, KC_ALTL, KC_GUIR, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_LCTL, KC_LALT, KC_LGUI, KC_ALAS, KC_MEEC, KC_NASP, KC_MSBS, KC_SYEN, KC_NUTB, KC_FNDL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        // └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_NAV] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NAMI,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, SYM_L, SYM_L, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_GUIA, KC_ALTS, KC_CTLD, KC_SFTF, KC_G, KC_LBRC, KC_RBRC, KC_H, KC_SFTJ, KC_CTLK, KC_ALTL, KC_GUIR, KC_SCLN,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LALT, KC_LGUI, KC_ALAS, KC_MEEC, KC_NASP, KC_MSBS, KC_SYEN, KC_NUTB, KC_FNDL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        // └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_MOUSE] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NAMI,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, SYM_L, SYM_L, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_GUIA, KC_ALTS, KC_CTLD, KC_SFTF, KC_G, KC_LBRC, KC_RBRC, KC_H, KC_SFTJ, KC_CTLK, KC_ALTL, KC_GUIR, KC_SCLN,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LALT, KC_LGUI, KC_ALAS, KC_MEEC, KC_NASP, KC_MSBS, KC_SYEN, KC_NUTB, KC_FNDL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        // └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_MEDIA] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NAMI,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_NO, TD(U_TD_U_TAP), TD(U_TD_U_EXTRA), TD(U_TD_U_BASE), KC_NO, KC_NO, SYM_L, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_ALGR, TD(U_TD_U_FUN), TD(U_TD_U_MEDIA), KC_NO, KC_NO, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LALT, KC_LGUI, KC_ALAS, KC_MEEC, KC_NASP, KC_MSBS, KC_SYEN, KC_NUTB, KC_FNDL, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        // └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_NUM] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, SYM_L, SYM_L, KC_NO, TD(U_TD_U_BASE), TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), KC_NO, KC_NO,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_LBRC, KC_RBRC, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_NO, TD(U_TD_U_NUM), TD(U_TD_U_NAV), KC_ALGR, KC_NO, KC_RSFT,
        // ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LALT, KC_LGUI, KC_ALAS, KC_DOT, KC_0, KC_MINS, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        // └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_SYMB] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NAMI,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, SYM_L, SYM_L, KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES, KC_QUOT, KC_EQL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_PLUS, KC_EQUAL, KC_LPRN, KC_RPRN, KC_DQUO, KC_LBRC, KC_RBRC, KC_COLN, KC_RBRC, KC_LBRC, KC_RCBR, KC_LCBR, KC_SCLN,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LT, KC_PIPE, KC_MINS, KC_GT, KC_BSLS, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_GRV, KC_UNDS, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        // ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LALT, KC_LGUI, KC_ALAS, KC_MEEC, KC_NASP, KC_MSBS, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        // └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

    [_FUN] = LAYOUT(
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NAMI,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR, SYM_L, SYM_L, KC_NO, TD(U_TD_U_BASE), TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), KC_NO, KC_NO,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL, KC_LBRC, KC_RBRC, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS, KC_ADPU, KC_PGDN, KC_HOME, KC_ADEN, KC_NO, TD(U_TD_U_FUN), TD(U_TD_U_MEDIA), KC_ALGR, KC_NO, KC_RSFT,
        // ├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_TRNS, KC_LALT, KC_LGUI, KC_ALAS, KC_APP, KC_SPC, KC_TAB, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        // └────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
        ),

};
