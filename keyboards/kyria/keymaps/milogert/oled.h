#pragma once

#include "layers.h"

#ifdef ENCODER_ENABLE
#    include "encoders.h"
#endif

void render_kyria_logo(void);

void render_layer(void);

#ifdef ENCODER_ENABLE
void render_encoder(encoder_mode_t mode);
#endif

void render_status(void);
