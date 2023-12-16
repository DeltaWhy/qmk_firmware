/*
Copyright 2022 aki27

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

#include QMK_KEYBOARD_H

// LEFT HAND HOME ROW MODS

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_R MT(MOD_LALT, KC_R)
#define CTL_S MT(MOD_LCTL, KC_S)
#define SHT_T MT(MOD_LSFT, KC_T)
#define ALG_X MT(MOD_RALT, KC_X)

// RIGHT HAND HOME ROW MODS

#define SHT_N MT(MOD_RSFT, KC_N)
#define CTL_E MT(MOD_RCTL, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define GUI_O MT(MOD_RGUI, KC_O)
#define ALG_DOT MT(MOD_RALT, KC_DOT)

const uint16_t PROGMEM test_combo1[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM test_combo5[] = {SHT_T, KC_G, COMBO_END};
const uint16_t PROGMEM test_combo6[] = {KC_M, SHT_N, COMBO_END};
const uint16_t PROGMEM test_combo7[] = {KC_G, KC_M, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_LBRC),
    COMBO(test_combo2, KC_RBRC),
    COMBO(test_combo3, KC_LCBR),
    COMBO(test_combo4, KC_RCBR),
    COMBO(test_combo5, KC_LPRN),
    COMBO(test_combo6, KC_RPRN),
    COMBO(test_combo7, CW_TOGG),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_Q,         KC_W,  KC_F,   KC_P,    KC_B,                                           KC_J,          KC_L,          KC_U,     KC_Y,   KC_QUOT,
        GUI_A,        ALT_R, CTL_S,  SHT_T,   KC_G,                                           KC_M,          SHT_N,         CTL_E,    ALT_I,  GUI_O,
        KC_Z,         ALG_X, KC_C,   KC_D,    KC_V,                                           KC_K,          KC_H,          KC_COMMA, ALG_DOT, KC_SLSH,
                             TT(1),  KC_SPC,  KC_TAB,        KC_MS_BTN1,    SCRL_MO,        KC_ENT,         KC_BSPC,       TT(2)
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______,                         KC_ESC,   _______, _______, _______, _______,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                         KC_MINS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, KC_RALT, _______, _______, _______,                         KC_DEL,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                          TG(1),   _______, _______,     _______, _______,   _______,  _______, _______
    ),
    [2] = LAYOUT(
        KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                         KC_ESC,   _______, _______, _______, _______,
        KC_COLN, KC_4,    KC_5,    KC_6,    KC_EQL,                          KC_MINUS, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                         KC_DEL,   _______, _______, KC_RALT, _______,
                          _______, KC_0,    KC_DOT,      _______, _______,   _______,  _______, TG(2)
    ),
    [3] = LAYOUT(
        KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                         _______,  _______, _______, _______, _______,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                         _______,  KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                         _______,  _______, _______, KC_RALT, _______,
                          _______, _______, _______,     _______, _______,   _______, _______, _______
    )
};

//bool encoder_update_user(uint8_t index, bool clockwise) {
    //if (index == 0) {
        //if (clockwise) {
            //tap_code(KC_VOLD);
            //tap_code(KC_MS_WH_UP);
        //} else {
            //tap_code(KC_VOLU);
            //tap_code(KC_MS_WH_DOWN);
        //}
    //}
    //return true;
//}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =  { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [1] =  { ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT)  },
    [2] =  { ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [3] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }
    //[4] =  { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }
};
#endif

//keyevent_t encoder1_ccw = {
    //.key = (keypos_t){.row = 3, .col = 0},
    //.pressed = false
//};

//keyevent_t encoder1_cw = {
    //.key = (keypos_t){.row = 3, .col = 9},
    //.pressed = false
//};

//bool encoder_update_user(uint8_t index, bool clockwise) {
    //if (index == 0) { /* First encoder */
        //if (clockwise) {
            //encoder1_cw.pressed = true;
            //encoder1_cw.time = (timer_read() | 1);
            //action_exec(encoder1_cw);
        //} else {
            //encoder1_ccw.pressed = true;
            //encoder1_ccw.time = (timer_read() | 1);
            //action_exec(encoder1_ccw);
        //}
    //}

    //return true;
//}

//void matrix_scan_user(void) {

    //if (IS_PRESSED(encoder1_ccw)) {
        //encoder1_ccw.pressed = false;
        //encoder1_ccw.time = (timer_read() | 1);
        //action_exec(encoder1_ccw);
    //}

    //if (IS_PRESSED(encoder1_cw)) {
        //encoder1_cw.pressed = false;
        //encoder1_cw.time = (timer_read() | 1);
        //action_exec(encoder1_cw);
    //}

//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case KC_COLN:
                if ((get_mods() & MOD_MASK_SHIFT)) {
                    uint8_t mods = get_mods();
                    clear_mods();
                    register_code(KC_SCLN);
                    set_mods(mods);
                    return false;
                } else {
                    return true;
                }
        }
    }
    return true;
}
