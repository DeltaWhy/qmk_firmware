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
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, KC_LBRC),
    COMBO(test_combo2, KC_RBRC),
    COMBO(test_combo3, KC_LCBR),
    COMBO(test_combo4, KC_RCBR),
    COMBO(test_combo5, KC_LPRN),
    COMBO(test_combo6, KC_RPRN),
    COMBO(test_combo7, CW_TOGG),
};

#define Q_ESC TD(0)
tap_dance_action_t tap_dance_actions[] = {
    ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        Q_ESC,      KC_W,           KC_F,           KC_P,           KC_B,           KC_J,       KC_L,           KC_U,       KC_Y,       KC_QUOT,      \
        GUI_A,      ALT_R,          CTL_S,          SHT_T,          KC_G,           KC_M,       SHT_N,          CTL_E,      ALT_I,      GUI_O,        \
        KC_Z,       ALG_X,          KC_C,           KC_D,           KC_V,           KC_K,       KC_H,           KC_COMM,    ALG_DOT,    KC_SLSH,      \
                                    TT(1),          KC_SPC,         LT(4, KC_TAB),         KC_ENT,     KC_BSPC,        TT(2)
    ),
    [1] = LAYOUT_split_3x5_3(
        KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_ESC,     KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,      \
        KC_LGUI,    KC_LALT,        KC_LCTL,        KC_LSFT,        KC_TRNS,        KC_MINUS,   KC_LEFT,        KC_DOWN,    KC_UP,      KC_RGHT,      \
        KC_TRNS,    KC_RALT,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_DEL,     KC_HOME,        KC_PGDN,    KC_PGUP,    KC_END,       \
                                    TG(1),          KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,        KC_TRNS
    ),
    [2] = LAYOUT_split_3x5_3(
        KC_LBRC,    KC_7,           KC_8,           KC_9,           KC_RBRC,        KC_ESC,     KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,      \
        KC_COLN,    KC_4,           KC_5,           KC_6,           KC_EQL,         KC_MINUS,   KC_RSFT,        KC_RCTL,    KC_LALT,    KC_RGUI,      \
        KC_GRV,     KC_1,           KC_2,           KC_3,           KC_BSLS,        KC_DEL,     KC_TRNS,        KC_TRNS,    KC_RALT,    KC_TRNS,      \
                                    KC_TRNS,        KC_0,           KC_DOT,         KC_TRNS,    KC_TRNS,        TG(2)
    ),
    [3] = LAYOUT_split_3x5_3(
        KC_F12,     KC_F7,          KC_F8,          KC_F9,          KC_PSCR,        KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,      \
        KC_F11,     KC_F4,          KC_F5,          KC_F6,          KC_SCRL,        KC_TRNS,    KC_RSFT,        KC_RCTL,    KC_LALT,    KC_RGUI,      \
        KC_F10,     KC_F1,          KC_F2,          KC_F3,          KC_PAUS,        KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_RALT,    KC_TRNS,      \
                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,    KC_TRNS,        KC_TRNS
    ),
    [4] = LAYOUT_split_3x5_3(
        KC_WH_L,    KC_WH_U,        KC_WH_D,        KC_WH_R,        KC_TRNS,        KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,      \
        KC_TRNS,    KC_BTN3,        KC_BTN2,        KC_BTN1,        KC_BTN5,        KC_BTN1,    KC_BTN2,        KC_BTN3,    KC_TRNS,    KC_TRNS,      \
        KC_TRNS,    KC_BTN3,        KC_BTN2,        KC_BTN1,        KC_BTN4,        KC_BTN1,    KC_BTN2,        KC_BTN3,    KC_TRNS,    KC_TRNS,      \
                                    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_BTN1,    KC_BTN2,        KC_BTN3
    ),
};

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

#ifdef CIRQUE_ENABLE
void pointing_device_init_user(void) {
    // set_auto_mouse_layer(4); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
    pointing_device_set_cpi(800);
}
#endif
