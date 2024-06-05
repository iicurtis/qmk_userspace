#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_80_with_macro(
    KC_F16,           KC_ESC,  KC_F1,  KC_F2,   KC_F3, KC_F4, KC_F5,  KC_F6,        KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MPLY, KC_MUTE,
    KC_PAUS, KC_PSCR, KC_GRV,  KC_1,   KC_2,    KC_3 ,  KC_4,  KC_5,  KC_6,         KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  KC_HOME,
    KC_MPRV, KC_MNXT, KC_TAB,  KC_Q,   KC_W,    KC_E,   KC_R,  KC_T,                KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
    KC_F14,  KC_F15,  KC_LCTL, KC_A,   KC_S,    KC_D,   KC_F,  KC_G,                KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    KC_F17,  KC_F18,  KC_LSFT,         KC_Z,    KC_X,   KC_C,  KC_V, KC_B,          KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
    KC_INS,  KC_END,  KC_LCTL, KC_LALT,KC_LGUI, LT(1, KC_BSPC),KC_SPC,KC_SPC,       LT(1, KC_SPC),  KC_BSPC,KC_RALT, KC_RCTL,     KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_80_with_macro(
    RGB_TOG,          _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
    RGB_HUD, RGB_HUI, KC_ESC, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,  KC_F11,  KC_F12,  _______, _______, KC_MPRV,
    RGB_SAD, RGB_SAI, RGB_TOG, LALT(KC_Q),LALT(KC_W),LALT(KC_E),LALT(KC_R),LALT(KC_T),_______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, KC_MNXT,
    RGB_VAD, RGB_VAI, _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______,           KC_EQL , KC_4,    KC_5,    KC_6,    _______, _______,          _______, KC_VOLU,
    RGB_RMOD,RGB_MOD, _______, KC_COMM, KC_DOT , _______, _______, _______,           _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, KC_VOLD,
    _______, _______, _______, _______, _______, KC_DEL,  KC_BSPC, KC_BSPC,           _______, KC_DEL, _______, _______, _______, _______, _______, _______
  ),

  [2] = LAYOUT_80_with_macro(
    _______,          _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______,          _______, _______, _______, _______, _______, _______
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
