#include "encoders.h"

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch (get_highest_layer(layer_state)) {
      case DEFAULT:
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;
      case SYMBOLS:
        if (clockwise) {
          tap_code(KC_PGDN);
        } else {
          tap_code(KC_PGUP);
        }
        break;
      case NAV:
      default:
        if (clockwise) {
          tap_code16(C(A(KC_RIGHT)));
        } else {
          tap_code16(C(A(KC_LEFT)));
        }
        break;
    }
#    ifdef OLED_DRIVER_ENABLE
        oled_on();
#    endif
  } else if (index == 1) {
    switch (get_highest_layer(layer_state)) {
      case DEFAULT:
        if (clockwise) {
          tap_code16(C(KC_TAB));
        } else {
          tap_code16(C(S(KC_TAB)));
        }
        break;
      case SYMBOLS:
        if (clockwise) {
          tap_code16(C(KC_RIGHT));
        } else {
          tap_code16(C(KC_LEFT));
        }
        break;
      case NAV:
      default:
        if (clockwise) {
          tap_code16(C(KC_TAB));
        } else {
          tap_code16(C(S(KC_TAB)));
        }
        break;
    }
#    ifdef OLED_DRIVER_ENABLE
        oled_on();
#    endif
  }
}
