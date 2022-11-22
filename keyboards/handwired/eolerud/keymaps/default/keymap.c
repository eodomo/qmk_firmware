// Copyright 2021 Eric Olerud (@eodomo)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/autocorrection.h"
#include "features/select_word.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _RAISE,
    _LOWER
};

enum my_keycodes {
	TICKET = SAFE_RANGE,
	DASH,
	SELWORD,
	LOCK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, KC_EQL,           KC_BSPC,
		KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,       KC_ENT,
		KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,               KC_RSFT,             KC_UP,
		KC_LCTL, KC_LGUI, KC_LALT,                        KC_SPC,                         KC_RALT, MO(_LOWER), MO(_RAISE),    KC_RCTL,   KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    /* Raise */
    [_RAISE] = LAYOUT(
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, KC_F12,               KC_DEL,
	       _______,  _______, SELWORD, _______,   RESET, _______, _______,  TICKET,  KC_INS, _______, KC_PSCR, _______, _______,   _______,
               _______,  _______, _______, _______, _______, _______, KC_HOME, _______, _______, _______,    _______,  _______,        KC_LEAD,
	       _______,   DM_PLY1, DM_PLY2, DM_RSTP, DM_REC1, DM_REC2,  KC_END, _______,    _______,_______,  _______,                 _______,            KC_MS_U,
	       _______, _______, _______,                          DASH,                         _______,    _______, _______,         _______,   KC_MS_L, KC_MS_D, KC_MS_R

    ),
    // LOWER
    [_LOWER] = LAYOUT(
      _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______, _______, _______, _______, _______, _______,_______,              _______,
	       _______,KC_KP_4,  KC_KP_5, KC_KP_6,  _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,
               _______,KC_KP_1,  KC_KP_2, KC_KP_3,  _______, _______, _______, _______,   _______,RGUI(KC_L),    _______,  _______,        _______,
	       _______, _______,   KC_KP_0, _______, _______, _______, _______, _______,    _______,_______,  _______,                 _______,            _______,
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

void _user_tap5(uint16_t keycode) {
	for (int i = 0; i < 5; i++ ){
		tap_code(keycode);
	}
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		SEQ_ONE_KEY(KC_C) {
			SEND_STRING("charlesit.com");
		}
		SEQ_ONE_KEY(KC_ENT) {		//leader key + enter -> mouse button 1
			tap_code(KC_BTN1);
		}
		SEQ_ONE_KEY(KC_LEFT) {		//leader key + arrow key -> arrow key x10
			_user_tap5(KC_LEFT);
		}
		SEQ_ONE_KEY(KC_UP) {
			_user_tap5(KC_UP);
		}
		SEQ_ONE_KEY(KC_DOWN) {
			_user_tap5(KC_DOWN);
		}
		SEQ_ONE_KEY(KC_RIGHT) {
			_user_tap5(KC_RIGHT);
		}
		SEQ_TWO_KEYS(KC_LEFT, KC_LEFT){
		    _user_tap5(KC_LEFT); _user_tap5(KC_LEFT);
		}
		SEQ_TWO_KEYS(KC_RIGHT, KC_RIGHT){
		    _user_tap5(KC_RIGHT); _user_tap5(KC_RIGHT);
		}
		SEQ_TWO_KEYS(KC_DOWN, KC_DOWN){
		    _user_tap5(KC_DOWN); _user_tap5(KC_DOWN);
		}
		SEQ_TWO_KEYS(KC_UP, KC_UP){
		    _user_tap5(KC_UP); _user_tap5(KC_UP);
		}
		SEQ_ONE_KEY(KC_I) {
			send_string("If you have any questions about this, please feel free to give me a call at 860.344.9628.");
		}
		SEQ_ONE_KEY(KC_W) {
			send_string("When you have some time for me to look at this, please give me a call at 860.344.9628, or you can reply-all to this email to schedule a meeting time.");
		}
		SEQ_ONE_KEY(KC_S) {
			send_string("Start-ADSyncSyncCycle -PolicyType Delta");
		}
		SEQ_TWO_KEYS(KC_S, KC_S) {
			send_string("net user jsnow /active:yes");
		}
		SEQ_TWO_KEYS(KC_P, KC_P){
            send_string("860.344.9628");
		}
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_autocorrection(keycode, record)) {return false;}
	if (!process_select_word(keycode, record, SELWORD)) {return false;}
	switch(keycode) {
		case TICKET:
			if (record->event.pressed) {
				send_string("* ");
				tap_code(KC_ENTER);
				tap_code(KC_ENTER);
				send_string("Work done:");
				tap_code(KC_ENTER);
				send_string("- ");
			}
			return false;
		case DASH:
			if (record->event.pressed) {
				send_string("----");
			}
			return false;
		default:
			return true;
	}
}
