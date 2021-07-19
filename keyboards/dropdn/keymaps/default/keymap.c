/* Copyright 2021 drhigsby
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

enum layers{
  _BASE,
  _NUM
};

enum combo_events {
  combo_ESC,
  combo_BACK,
  combo_TAB,
  combo_DELETE,
  combo_ENTER,
  combo_LPRN,
  combo_RPRN,
  combo_ZERO
};

const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lprn_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM rprn_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM zero_combo[] = {KC_8, KC_9, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [combo_ESC] = COMBO(esc_combo, KC_ESC),
  [combo_BACK] = COMBO(bspc_combo, KC_BSPC),
  [combo_TAB] = COMBO(tab_combo, KC_TAB),
  [combo_DELETE] = COMBO(del_combo, KC_DEL),
  [combo_ENTER] = COMBO(enter_combo, KC_ENT),
  [combo_LPRN] = COMBO(lprn_combo, KC_LPRN),
  [combo_RPRN] = COMBO(rprn_combo, KC_RPRN),
  [combo_ZERO] = COMBO(zero_combo, KC_0),
};

#define NUM MO(_NUM)
#define xxx KC_TRNS
#define DEEZ KC_D
#define NUTS KC_N

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y,
        KC_A, KC_R, KC_S, KC_T, KC_G, KC_H, KC_E, KC_I, KC_O,
        LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_K, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),
                KC_LCTL, NUM, DEEZ, NUTS, KC_SPC, KC_RALT
  ),

    [_NUM] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_EQL, KC_MINS, 
        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_HOME, KC_END, KC_ASTR, KC_DQUO, KC_QUOT,
                  KC_CAPS, xxx, KC_GRV, KC_TILD, KC_PGUP, KC_PGDN      
  )

};
