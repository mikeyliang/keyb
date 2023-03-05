/* Copyright 2022 keyb
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
#include "print.h"

enum layers {
    BASE,  // qwerty
    _FL,   // function key layer
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
    rgb_matrix_enable();
    if (rgb_matrix_is_enabled()) { 
        print("rgb matrix enabled");
    } else {
        print("not enabled");
    }
    rgb_matrix_set_color_all(200, 200, 200);
}


/*
 * ,---------------------------------------------------------------|
 * |esc|1  |2  |3  |4  |5  |6  |7  |8  |9  |0   |-   |=  |Backspace| ROT
 * |---------------------------------------------------------------|
 * |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  | ]  |   \    |
 * |---------------------------------------------------------------|
 * |Caps  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |   Enter    |
 * |---------------------------------------------------------------|
 * |Shft    |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift |Up|oled|
 * |---------------------------------------------------------------|
 * |Ctrl|Alt |CMD |     Space              |Fn |Ctrl |  Lt |Dn |Rt |
 * `---------------------------------------------------------------|'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_ESC, KC_1,   KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,
        KC_TAB, KC_Q,   KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,           KC_ENT, 
        KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M, KC_COMM, KC_DOT,KC_SLSH,          KC_RSFT, KC_UP,   KC_RIGHT_GUI,
        KC_LEFT_CTRL, KC_LEFT_ALT, KC_LCMD,                  KC_SPC,                      MO(_FL), KC_RIGHT_CTRL, KC_LEFT, KC_DOWN, KC_RGHT),

    [_FL] = LAYOUT(
        KC_GRV,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,_______,
        _______, _______, _______,                   _______,                            MO(_FL), _______, KC_BRID, KC_VOLD, KC_BRIU),
};