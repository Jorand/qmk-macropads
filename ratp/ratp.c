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

#include "ratp.h"

void bootmagic_lite(void) {
    matrix_scan();
    wait_ms(DEBOUNCE * 2);
    matrix_scan();

    if (matrix_get_row(BOOTMAGIC_LITE_ROW) & (1 << BOOTMAGIC_LITE_COLUMN)) {
      // Jump to bootloader.
      bootloader_jump();
    }
}

bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) { return false;}
#ifdef CONSOLE_ENABLE
    uprintf("index: %u, active: %d\n", index, active);
#endif 
    if (index == 0) {
        default_layer_set(1UL << (active ? 0 : 1));
    }
    if (index == 1) {
        default_layer_set(1UL << (active ? 2 : 1));
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  if (record->event.key.row == 0) {
    if (record->event.key.col == 0) {
      writePin(F6, (record->event.pressed ? 1 : 0));
    }
    if (record->event.key.col == 1) {
      writePin(B1, (record->event.pressed ? 1 : 0));
    }
  }
  return true;
}

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(B1);
  setPinOutput(F6);
}