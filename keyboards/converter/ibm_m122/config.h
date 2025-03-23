/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2016 Priyadi Iman Nurcahyo <priyadi@priyadi.net>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "musical_notes.h"

#define START_BEEP H__NOTE(_B5),

/* matrix size */
#define MATRIX_ROWS 17  // keycode bit: 3-0
#define MATRIX_COLS 8   // keycode bit: 6-4

/* legacy keymap support */
#define USE_LEGACY_KEYMAP

/* NKRO enable */
#define FORCE_NKRO

/* VIA support */
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

/* Audio */
#define AUDIO_INIT_DELAY
#define AUDIO_PIN A8
#define AUDIO_PWM_DRIVER PWMD1
#define AUDIO_PWM_CHANNEL 1
#define AUDIO_PWM_PAL_MODE 42
#define AUDIO_STATE_TIMER GPTD4

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(START_BEEP)
#endif

/*
 * PS/2 Interrupt configuration
 */
#ifdef PS2_DRIVER_INTERRUPT
#define PS2_CLOCK_PIN   B9
#define PS2_DATA_PIN    B8
#endif
