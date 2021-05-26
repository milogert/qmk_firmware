#pragma once

#include QMK_KEYBOARD_H
#include "layers.h"

typedef enum {
    ENC_MODE_VOLUME = 0,
    ENC_MODE_WORD_NAV,
    ENC_MODE_LEFT_RIGHT,
    ENC_MODE_UP_DOWN,
    ENC_MODE_PAGING,
    _ENC_MODE_LAST  // Do not use, except for looping through enum values
} encoder_mode_t;

encoder_mode_t encoder_left_mode;
encoder_mode_t encoder_right_mode;

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise);
#endif
