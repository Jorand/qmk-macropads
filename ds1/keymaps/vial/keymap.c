/* Copyright 2022 Jorand
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
            KC_F9, DF(1)
      ),

      [1] = LAYOUT(
            SGUI(KC_Q), DF(0)
      )
};

void keyboard_post_init_user(void) {
      // Customise these values to desired behaviour
      debug_enable=true;
      //debug_matrix=true;
      //debug_keyboard=true;
      //debug_mouse=true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {

      #ifdef CONSOLE_ENABLE
      uprintf("state: %u, get_highest_layer: %u, biton32: %u\n", state, get_highest_layer(state), biton32(state));
      #endif

      switch (get_highest_layer(state)) {
            case 0:
                  writePinLow(D4);
                  break;
            case 1:
                  writePinHigh(D4);
                  break;
            default: //  for any other layers, or the default layer
                  writePinLow(D4);
                  break;
            }
      return state;
}

void keyboard_pre_init_user(void) {
      // Call the keyboard pre init code.

      // Set our LED pins as output
      setPinOutput(D4);
}