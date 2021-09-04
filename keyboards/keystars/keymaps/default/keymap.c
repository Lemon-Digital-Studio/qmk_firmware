/* Copyright 2021 zhengchangzhou
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     QMKBEST = SAFE_RANGE,
//     QMKURL
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,          KC_F10,  KC_F11,  KC_F12,    KC_PSCR,    KC_SLCK,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,           KC_0,    KC_MINS, KC_EQL,    KC_BSPC,    KC_PAUS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,       KC_O,           KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,    KC_INS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,       KC_L,           KC_SCLN, KC_QUOT, KC_ENT,   KC_HOME,     KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,         KC_SLSH, KC_RSFT, KC_UP,    KC_DEL,      KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,           KC_RALT, KC_RGUI,    LT(1, KC_APP),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT,      KC_PGDN
    ),
    [_FN] = LAYOUT(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______,    _______,        _______, _______, _______,   _______,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,        _______, _______, _______,  _______,    _______,
        _______, BL_TOGG, RGB_TOG, _______, _______, _______, _______, _______, _______,    _______,        _______, _______, _______,  _______,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,        _______, _______, _______,  _______,    BL_INC,
        _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______,    _______,        _______, _______, BL_INC,   RGB_VAI,    RGB_SAI,
        _______, _______, _______,                   _______,          _______, _______,    _______,        _______, BL_INC,  BL_DEC,   RGB_MOD,    RGB_HUI
    )
};

led_config_t g_led_config = {{
        {0,     1,        2,        3,      4,       5,       6,       7,        8,        9,                10,       11,     12,        13,         14},
        {15,    16,       17,       18,     19,      20,      21,      22,       23,       24,               25,       26,     27,     28, 29},
        {32,    33,       34,       35,     36,      37,      38,      39,       40,       41,               42,       43,     44,        45,         46},
        {47,    48,       49,       50,     51,      52,      53,      54,       55,       56,               57,       58,  59,60, 61},
     {64, 67,       68,      69,      70,      71,      72,      73,       74,       75,               76,    77,78,79,  80},
        {83,    84,       85,                    86, 87, 88,            89,       90,       91,               92,       93,     94}
},
{
// LED 对应到物理位置，可以参考下面这个公式，我因为底灯接错了有点乱
// x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
// y = 64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION


      {0, 0}, {15,0},  {31, 0}, {46, 0},  {62, 0}, {77, 0}, {92, 0}, {108, 0}, {123, 0}, {138, 0},           {154, 0},{169, 0},{184, 0},    {207, 0},        {214, 0},
      {0, 11},{15,11}, {69, 11},{85, 15}, {100,15},{115,15},{131,15}, {146,15}, {161, 15},{177, 15},         {192,15},{211,15},{6,31},{27,31},{42,31},{42,31},{42,31},
      {0, 21},{54,21}, {58, 21},{73, 31}, {88, 31},{10,31},{12,31}, {134, 31}, {150, 31}, {165, 31},         {181, 31},{205,31},{8, 47},     {31, 47},        {31, 47},
      {0, 32},{15,32}, {69, 32},{85, 15},{100, 15},{115,15},{131,15},{146,15}, {161, 15},{177, 15},          {192, 15},{211,15},{6,31},{27,31},{42, 31},{31, 47},{31,47},
{0,42},{15,42},
      {0,42},{15,42}, {69, 42},{85, 15},{100, 15},{115,15},{131,15},{146,15}, {161, 15}, {177, 15},          {192, 15},{211,15},{6,31},{27,31},{42, 31},{31, 47},{31,47},
      {0, 53},{48,53}, {93, 53},      {125, 12},{48,60},{15,60},   {201, 12}, {171, 12}, {92, 60},           {125, 60},{177,60},{208,60},     {207, 0},        {214, 0}
},
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1
}};


// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /* Base */
//     [_BASE] = LAYOUT(
//         KC_A,    KC_1,    MO(_FN),
//             KC_TAB,   KC_SPC
//     ),
//     [_FN] = LAYOUT(
//         QMKBEST, QMKURL,  _______,
//             RESET,    XXXXXXX
//     )
// };

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case QMKBEST:
//             if (record->event.pressed) {
//                 // when keycode QMKBEST is pressed
//                 SEND_STRING("QMK is the best thing ever!");
//             } else {
//                 // when keycode QMKBEST is released
//             }
//             break;
//         case QMKURL:
//             if (record->event.pressed) {
//                 // when keycode QMKURL is pressed
//                 SEND_STRING("https://qmk.fm/\n");
//             } else {
//                 // when keycode QMKURL is released
//             }
//             break;
//     }
//     return true;
// }
