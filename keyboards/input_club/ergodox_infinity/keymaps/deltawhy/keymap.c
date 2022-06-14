#include "keymap_gen.c"

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
	    default:
		return true;
	}
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case DF(0) ... DF(0xFF):
			// persist default layer changes
			if (record->event.pressed) {
				set_single_persistent_default_layer(keycode & 0xFF);
			}
			return;
	}
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
	case KC_LSPO:
	case KC_RSPC:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

#ifdef ST7565_ENABLE
void st7565_task_user(void) {
	// Host Keyboard Layer Status
	st7565_write_P(PSTR("Layer: "), false);

	switch (get_highest_layer(default_layer_state)) {
		case 0:
			st7565_write_P(PSTR("Default\n"), false);
			break;
		case 1:
			st7565_write_P(PSTR("Miryoku\n"), false);
			break;
		case 2:
			st7565_write_P(PSTR("Qwertyoku\n"), false);
			break;
		case 3:
			st7565_write_P(PSTR("Colemak-DH\n"), false);
			break;
		case 4:
			st7565_write_P(PSTR("Game\n"), false);
			break;
		default:
			// Or use the write_ln shortcut over adding '\n' to the end of your string
			st7565_write_ln_P(PSTR("Undefined"), false);
	}
	switch (get_highest_layer(layer_state)) {
		case 0:
			break;
		case 5:
			st7565_write_P(PSTR("Game Flipped\n"), false);
			break;
		case 6:
			st7565_write_P(PSTR("Symbol\n"), false);
			break;
		case 7:
			st7565_write_P(PSTR("Mouse & Media\n"), false);
			break;
		case 8:
			st7565_write_P(PSTR("Media\n"), false);
			break;
		case 9:
			st7565_write_P(PSTR("Nav\n"), false);
			break;
		case 10:
			st7565_write_P(PSTR("Mouse\n"), false);
			break;
		case 11:
			st7565_write_P(PSTR("Symbol\n"), false);
			break;
		case 12:
			st7565_write_P(PSTR("Number\n"), false);
			break;
		case 13:
			st7565_write_P(PSTR("Function\n"), false);
			break;
		default:
			// Or use the write_ln shortcut over adding '\n' to the end of your string
			st7565_write_ln_P(PSTR("Undefined"), false);
	}

	// Host Keyboard LED Status
	led_t led_state = host_keyboard_led_state();
	st7565_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
	st7565_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
	st7565_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
