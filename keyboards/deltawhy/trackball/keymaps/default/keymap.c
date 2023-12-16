// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_custom(
        KC_A,   KC_B
    )
};

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_kb(void) {
    pmw33xx_init(0);
    pointing_device_init_user();
}
#endif

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=false;
    debug_keyboard=true;
    debug_mouse=true;
    pointing_device_set_cpi(800);
    uprintf("hello\n");
    uprintf("CPI: %u\n", pointing_device_get_cpi());
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    debug_enable=true;
    debug_matrix=false;
    debug_keyboard=true;
    debug_mouse=true;
    pointing_device_set_cpi(800);
    uprintf("hello\n");
    uprintf("CPI: %u\n", pointing_device_get_cpi());
#endif
  return true;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
#ifdef CONSOLE_ENABLE
    if (mouse_report.x != 0 || mouse_report.y != 0) {
        uprintf("mouse_report: x=%3d y=%3d\n", mouse_report.x, mouse_report.y);
    }
#endif
    return mouse_report;
}
