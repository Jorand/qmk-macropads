/* Copyright 2020 GhostSeven <work@ghost7.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

extern MidiDevice midi_device;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MO(1),    KC_MYCM,    KC_VOLD,  KC_MUTE,  KC_VOLU,
        LT(2,KC_MPRV),  KC_MPLY,        KC_MNXT
    ),

    [1] = LAYOUT(
        KC_TRNS,  RGB_SAI,    RGB_VAD,  RGB_TOG,  RGB_VAI,
        RGB_MOD,  RGB_SAD,              RGB_HUI
    ),

    [2] = LAYOUT(
        KC_TRNS,  MI_C,    KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  RESET,                EEP_RST
    ),

    [3] = LAYOUT(
        KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,              KC_TRNS
    ),

};

#define MIDI_CC_OFF 63
#define MIDI_CC_ON  65

enum custom_keycodes {
    MIDI_CC80 = USER00,
    MIDI_CC82,
    MIDI_CC84,
    MIDI_CC85
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MIDI_CC80:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_OFF);
            }
            return true;
        case MIDI_CC82:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 82, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, midi_config.channel, 82, MIDI_CC_OFF);
            }
            return true;
        case MIDI_CC84:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 84, 70);
            }
            return true;
        case MIDI_CC85:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, midi_config.channel, 84, 50);
            }
            return true;
    }
    return true;
};

#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

#define ENCODERS 1
static uint8_t  encoder_state[ENCODERS] = {0};
static keypos_t encoder_cw[ENCODERS]    = {{ 3, 1 }};
static keypos_t encoder_ccw[ENCODERS]  = {{ 3, 0 }};

void encoder_action_unregister(void) {
    for (int index = 0; index < ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t) {
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
            };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void encoder_action_register(uint8_t index, bool clockwise) {
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

void matrix_scan_user(void) {
    encoder_action_unregister();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif
