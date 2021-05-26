#include QMK_KEYBOARD_H

#include "layers.h"

#ifdef ENCODER_ENABLE
#    include "encoders.h"
#endif

#ifdef OLED_DRIVER_ENABLE
#    include "oled.h"
#endif

// Home row mods information: https://precondition.github.io/home-row-mods
// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Thumb cluster mods
#define TC_SPACE LT(1, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT] = LAYOUT(
    LT(3, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T,                                                                  KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSLS,
    KC_LCTL,       KC_A, KC_S, KC_D, KC_F, KC_G,                                                                  KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSPO,       KC_Z, KC_X, KC_C, KC_V, KC_B,    LCTL_T(KC_LBRC), LT(3,KC_ESC), LT(2,KC_TAB), RCTL_T(KC_RBRC), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
                         KC_MPLY, KC_LALT, KC_LGUI, KC_SPC,          MO(2),        MO(3),        KC_ENT,          KC_BSPC, OSL(MACROS), KC_MUTE
  ),
  [MATH] = LAYOUT(
    DF(DEFAULT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
    _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX,
    _______,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, _______,
                                   XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, _______, KC_PENT, KC_KP_0, KC_PDOT
  ),
  [SYMBOLS] = LAYOUT(
    XXXXXXX, KC_1,  KC_2,  KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
    _______, KC_F1, KC_F2, KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DOT,
    _______, KC_F7, KC_F8, KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, _______, KC_F12,  KC_UNDS, KC_PLUS, KC_DOT,  XXXXXXX, _______,
                           XXXXXXX, _______, _______, _______, KC_TILD, KC_GRV,  _______, _______, _______, XXXXXXX
  ),
  [NAV] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_DEL,  LCTL(KC_B),                                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  XXXXXXX,                                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, _______,
                               KC_PGUP, _______, _______,    _______, XXXXXXX, XXXXXXX, _______, _______, _______, KC_PGDN
  ),
  [UTIL] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX,  KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, RESET,
    XXXXXXX, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                      XXXXXXX,  KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(MATH), XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX
  ),
  [MACROS] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G(S(KC_4)), G(S(KC_5)),                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

void matrix_init_user(void) {
#ifdef ENCODER_ENABLE
    //encoder_utils_init();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, SYMBOLS, NAV, UTIL);
}
