#include QMK_KEYBOARD_H
#include "pincontrol.h"

enum custom_keycodes {
    C_RST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_LALT,				KC_Z,	KC_X,	KC_F3,	KC_F2,	KC_M,	KC_N,	KC_B,	KC_V,	KC_C,					KC_INS,
				KC_LCTL,		KC_A,	KC_S,	KC_F5,	KC_F4,	KC_J,	KC_H,	KC_G,	KC_F,	KC_D,					KC_DEL,
						KC_RSFT,KC_BSPC,KC_EQL,	KC_PSCR,KC_F12,	KC_7,	KC_8,	KC_9,	KC_0,	KC_MINS,	    KC_BSLS,
				KC_CAPS,		KC_GRV,	KC_1,	KC_BRK,	KC_SLCK,KC_6,	KC_5,	KC_4,	KC_3,	KC_2,	KC_RGHT,KC_DOWN,KC_LEFT,
				KC_RCTL,		KC_ENT,	KC_RBRC,KC_F11,	KC_F10,	KC_U,	KC_I,	KC_O,	KC_P,	KC_LBRC,				KC_UP,
		KC_RALT,								KC_F9,	KC_F8,	KC_K,	KC_L,	KC_SCLN,KC_QUOT,						KC_NLCK,
												KC_F7,	KC_F6,	KC_COMM,KC_DOT,	KC_SLSH,KC_SPC,	
						KC_LSFT,KC_TAB,	KC_Q, 	KC_F1,	KC_ESC,	KC_Y,	KC_T,	KC_R,	KC_E,	KC_W
        ),

    LAYOUT(
        _______,				_______,_______,_______,KC_F12 ,_______,_______,_______,_______,_______,				_______,
				_______,		_______,_______,_______,_______,_______,_______,_______,_______,_______,				C_RST,
						_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,		_______,
				_______,		_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_END, KC_PGDN,KC_HOME,
				_______,		_______,_______,_______,_______,_______,_______,_______,_______,_______,				KC_PGUP,
		_______,								_______,_______,_______,_______,_______,_______,						_______,
												_______,_______,_______,_______,_______,_______,
						_______,_______,_______,KC_F11 ,_______,_______,_______,_______,_______,_______
        )
};

void keyboard_pre_init_user(void) {
	setPinInputHigh(FN_KEY_PIN);
	setPinOutput(NUM_LOCK_LED_PIN);
	setPinOutput(CAPS_LOCK_LED_PIN);
	setPinOutput(SCROLL_LOCK_LED_PIN);
	digitalWrite(NUM_LOCK_LED_PIN, 1);
	digitalWrite(CAPS_LOCK_LED_PIN, 1);
	digitalWrite(SCROLL_LOCK_LED_PIN, 1);
	
	setPinOutput(RESET_PIN);
	digitalWrite(RESET_PIN, 1);
	if(digitalRead(FN_KEY_PIN) == 0) {
		digitalWrite(RESET_PIN, 0);
	}
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
	if(digitalRead(FN_KEY_PIN) == 0) {
		layer_on(1);
	} else {
		layer_off(1);
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case C_RST:
			if (record->event.pressed) {
				digitalWrite(RESET_PIN, 0);
			}
			return false;
		default:
			return true;
	}
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
		digitalWrite(NUM_LOCK_LED_PIN, 0);
    } else {
        digitalWrite(NUM_LOCK_LED_PIN, 1);
    }
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
		digitalWrite(CAPS_LOCK_LED_PIN, 0);
    } else {
        digitalWrite(CAPS_LOCK_LED_PIN, 1);
    }
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        digitalWrite(SCROLL_LOCK_LED_PIN, 0);
    } else {
		digitalWrite(SCROLL_LOCK_LED_PIN, 1);
    }
}