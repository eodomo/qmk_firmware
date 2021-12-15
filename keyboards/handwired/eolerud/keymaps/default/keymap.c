// Copyright 2021 Eric Olerud (@eodomo)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, KC_EQL,           KC_BSPC,
		KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,       KC_ENT,
		KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,               KC_RSFT,             KC_UP,
		KC_LCTL, KC_LGUI, KC_LALT,                        KC_SPC,                         KC_RALT,    KC_RGUI, MO(_RAISE),    KC_RCTL,   KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    /* Raise */
    [_RAISE] = LAYOUT(
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, KC_F12,               KC_DEL,
	       _______,  _______, _______, _______,   RESET, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,   _______,
               _______,  _______, _______, _______, _______, _______, KC_HOME, _______, _______, _______,    _______,  _______,        KC_LEAD,
	       _______,   _______, DM_REC1, DM_RSTP, DM_PLY1, _______,  KC_END, _______,    _______,_______,  _______,                 _______,            _______,
	       _______, _______, _______,                       _______,                         _______,    _______, _______,         _______,   _______, _______, _______

    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (layer_state_is(_BASE)) {
		if (clockwise) {
				tap_code(KC_MS_WH_UP);
		} else {
				tap_code(KC_MS_WH_DOWN);
		}
	} else if (layer_state_is(_RAISE)) {
		if (clockwise) {
			tap_code(KC_VOLD);
		} else {
			tap_code(KC_VOLU);
		}
	}
	return false;
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		SEQ_ONE_KEY(KC_C) {
			SEND_STRING("cromwell.k12.ct.us");
		}
	}
}
