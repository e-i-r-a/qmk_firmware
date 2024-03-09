/* Copyright 2024 Raphael Eicher
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

// definitions of my special keys
#define MY_ESC   LT(1,KC_ESC)
#define MY_A     LT(1,KC_A)
#define MY_Z     MT(MOD_LSFT, KC_Z)
#define MY_X     MT(MOD_LCTL, KC_X)
#define MY_C     MT(MOD_LGUI, KC_C)
#define MY_V     MT(MOD_LALT, KC_V)
#define MY_M     MT(MOD_LALT, KC_M)
#define MY_COMM  MT(MOD_LGUI, KC_COMM)
#define MY_DOT   MT(MOD_RCTL, KC_DOT)
#define MY_SLSH  MT(MOD_RSFT, KC_SLSH)
#define MY_RGHT  MT(MOD_RALT, KC_RIGHT)
#define MY_L2    LT(2, KC_BSPC)
#define MY_L3    LT(3, KC_SPC)

enum Layer_name {
    QWERTY,
    NAV,
    SYMBOL,
    NUMBER,
    FUNCT,
    MEDIA
};

enum custom_keycodes {
    MACRO_0 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Keymap 0: QWERTY layer
     *
     * ,----------------------------------------------------------------.           ,----------------------------------------------------------------.
     * | 1        | 2      | 3      | 4      | 5      | 6      |        |           | Mute   | 7      | 8      | 9      | 0      | -      | =        |
     * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
     * |----------+--------+--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------+--------+----------|
     * | Tab      | Q      | W      | E      | R      | T      |        |           |        | Y      | U      | I      | O      | P      | Backsp   |
     * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
     * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
     * | Escape   | A      | S      | D      | F      | G      |________|           |________| H      | J      | K      | L      | ;      | Enter    |
     * | Layer1   | Layer1 |        |        |        |        |        |           |        |        |        |        |        |        |          |
     * |----------+--------+--------+--------+--------+--------| Layer5 |           | CapsL  |--------+--------+--------+--------+--------+----------|
     * | LShift   | Z      | X      | C      | V      | B      |        |           |        | N      | M      | ,      | .      | /      | RShift   |
     * |          | LShift | LCtrl  | LGui   | LAlt   |        |        |           |        |        | LAlt   | LGui   | RCtrl  | RShift |          |
     * `----------+--------+--------+--------+--------+-----------------'           `--------+--------+--------+--------+--------+--------+----------'
     *   | LCtrl  | LGui   |        |        | Layer4 |                                               | Layer4 | Left   | Down   | Up     | Right  |
     *   |        |        |        |        |        |                                               |        |        |        |        | AltGr  |
     *   `--------------------------------------------'                                               `--------------------------------------------'
     *                                                ,-----------------.           ,-----------------.
     *                                                | Left   | Right  |           | Macro0 | RAlt   |
     *                                                |        |        |           |        |        |
     *                                       ,--------|--------|--------|           |--------+--------+--------.
     *                                       |        |        | Up     |           | VolUp  |        |        |
     *                                       | Backsp | Del    |        |           |        | Enter  | Space  |
     *                                       |        |        |--------|           |--------|        |        |
     *                                       | Layer2 |        | Down   |           | VolDown|        | Layer3 |
     *                                       |        |        |        |           |        |        |        |
     *                                       `--------------------------'           `--------------------------'
     */
    LAYOUT_ergodox_pretty(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_NO, KC_MUTE, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQUAL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, MY_ESC, MY_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSFT, MY_Z, MY_X, MY_C, MY_V, KC_B, TG(5), KC_CAPS, KC_N, MY_M, MY_COMM, MY_DOT, MY_SLSH, KC_RSFT, KC_LCTL, KC_LGUI, KC_NO, KC_NO, MO(4), MO(4), KC_LEFT, KC_DOWN, KC_UP, MY_RGHT, KC_LEFT, KC_RGHT, MACRO_0, KC_RALT, KC_UP, KC_VOLU, MY_L2, KC_DEL, KC_DOWN, KC_VOLD, KC_ENT, MY_L3),
    /* Keymap 1: Navigation Layer
     *
     * ,----------------------------------------------------------------.           ,----------------------------------------------------------------.
     * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
     * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
     * |----------+--------+--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------+--------+----------|
     * | Trans    |        |        |        |        |        |        |           |        | Backsp | Del    | Ins    |        | PScr   | Trans    |
     * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
     * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
     * | Trans    | Trans  | LCtrl  | LAlt   | LShift |        |________|           |________| Left   | Down   | Up     | Right  | '      | "        |
     * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
     * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
     * | Trans    |        |        |        |        |        |        |           |        | Home   | PgDn   | PgUp   | End    | Trans  | Trans    |
     * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
     * `----------+--------+--------+--------+--------+-----------------'           `--------+--------+--------+--------+--------+--------+----------'
     *   | Trans  | Trans  |        |        | Trans  |                                               | Trans  | Trans  | Trans  | Trans  |        |
     *   |        |        |        |        |        |                                               |        |        |        |        |        |
     *   `--------------------------------------------'                                               `--------------------------------------------'
     *                                                 -----------------             -----------------
     *                                                | Trans  | Trans  |           | Trans  | Trans  |
     *                                                |        |        |           |        |        |
     *                                        --------|--------|--------|           |--------+--------+--------
     *                                       |        |        | Trans  |           | Trans  |        |        |
     *                                       | Trans  | Trans  |        |           |        | Trans  | Trans  |
     *                                       |        |        |--------|           |--------|        |        |
     *                                       |        |        | Trans  |           | Trans  |        |        |
     *                                       |        |        |        |           |        |        |        |
     *                                       `--------------------------'           `--------------------------'
     *
     *  TODO: Add Context Menu Button
 */
    LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_BSPC, KC_DEL,  KC_INS,  KC_NO,   KC_PSCR, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_LSFT, KC_NO,                                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_DQUO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
        KC_LCTL, KC_LGUI, KC_NO,   KC_NO,   MO(4),                                                  MO(4),   KC_LEFT, KC_DOWN, KC_UP,   MY_RGHT,
                                                     KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,
                                                              KC_TRNS,            KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Number layer
 *
 * ,----------------------------------------------------------------.           ,----------------------------------------------------------------.
 * | Trans    | Trans  | Trans  | Trans  | Trans  | Trans  | Trans  |           | Trans  | Trans  | Trans  | Trans  | Trans  | Trans  | Trans    |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------+--------+----------|
 * | Trans    | `      |        |        |        |        |        |           |        |        |        | [      | ]      | \      | Trans    |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
 * | 1        | 2      | 3      | 4      | 5      | 6      |________|           |________| 7      | 8      | 9      | 0      | -      | =        |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
 * | Trans    | LShift | LCtrl  | LGui   | LAlt   |        |        |           |        |        | LAlt   | LGui   | Trans  | RShift | Trans    |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * `----------+--------+--------+--------+--------+-----------------'           `--------+--------+--------+--------+--------+--------+----------'
 *   | Trans  | Trans  | Trans  | Trans  | Trans  |                                               | Trans  | Trans  | Trans  | Trans  | Trans  |
 *   |        |        |        |        |        |                                               |        |        |        |        |        |
 *   `--------------------------------------------'                                               `--------------------------------------------'
 *                                                 -----------------             -----------------
 *                                                | Trans  |Trans   |           | Trans  | Trans  |
 *                                                |        |        |           |        |        |
 *                                        --------|--------|--------|           |--------+--------+--------
 *                                       |        |        | Trans  |           | Trans  |        |        |
 *                                       | Trans  | Trans  |        |           |        | Trans  | Trans  |
 *                                       |        |        |--------|           |--------|        |        |
 *                                       |        |        | Trans  |           | Trans  |        |        |
 *                                       |        |        |        |           |        |        |        |
 *                                       `--------------------------'           `--------------------------'
 */
    LAYOUT_ergodox_pretty(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                                 KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_LALT, KC_LGUI, KC_TRNS, KC_RSFT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,
                                                              KC_TRNS,            KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,KC_TRNS
    ),
/* Keymap 3: Symobl layer
 *
 * ,----------------------------------------------------------------.           ,----------------------------------------------------------------.
 * | Trans    | Trans  | Trans  | Trans  | Trans  | Trans  | Trans  |           | Trans  | Trans  | Trans  | Trans  | Trans  | Trans  | Trans    |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------+--------+----------|
 * | Trans    | ~      |        |        |        |        |        |           |        |        |        | {      | }      | |      | Trans    |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
 * | !        | @      | #      | $      | %      | ^      |________|           |________| &      | *      | (      | )      | _      | +        |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
 * | Trans    | LShift | LCtrl  | LGui   | LAlt   |        |        |           |        |        | LAlt   | LGui   | Trans  | RShift | Trans    |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * `----------+--------+--------+--------+--------+-----------------'           `--------+--------+--------+--------+--------+--------+----------'
 *   | Trans  | Trans  | Trans  | Trans  | Trans  |                                               | Trans  | Trans  | Trans  | Trans  | Trans  |
 *   |        |        |        |        |        |                                               |        |        |        |        |        |
 *   `--------------------------------------------'                                               `--------------------------------------------'
 *                                                 -----------------             -----------------
 *                                                | Trans  |Trans   |           | Trans  | Trans  |
 *                                                |        |        |           |        |        |
 *                                        --------|--------|--------|           |--------+--------+--------
 *                                       |        |        | Trans  |           | Trans  |        |        |
 *                                       | Trans  | Trans  |        |           |        | Trans  | Trans  |
 *                                       |        |        |--------|           |--------|        |        |
 *                                       |        |        | Trans  |           | Trans  |        |        |
 *                                       |        |        |        |           |        |        |        |
 *                                       `--------------------------'           `--------------------------'
 */
    LAYOUT_ergodox_pretty(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TILD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                              KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_LALT, KC_LGUI, KC_TRNS, KC_RSFT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,
                                                              KC_TRNS,            KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,KC_TRNS
    ),
/* Keymap 4: Function layer
 *
 * ,----------------------------------------------------------------.           ,----------------------------------------------------------------.
 * | Trans    | Trans  | Trans  | Trans  | Trans  | Trans  | Trans  |           | Trans  | Trans  | Trans  | Trans  | Trans  | Trans  | Trans    |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------+--------+----------|
 * | Trans    |        |        |        |        |        |        |           |        |        |        |        |        |        | Trans    |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
 * | F1       | F2     | F3     | F4     | F5     | F6     |________|           |________| F7     | F8     | F9     | F10    | F11    | F12      |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
 * | Trans    | LShift | LCtrl  | LGui   | LAlt   |        |        |           |        |        | LAlt   | LGui   | RCtrl  | RShift | Trans    |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * `----------+--------+--------+--------+--------+-----------------'           `--------+--------+--------+--------+--------+--------+----------'
 *   | Trans  | Trans  | Trans  | Trans  | Trans  |                                               | Trans  | Trans  | Trans  | Trans  | Trans  |
 *   |        |        |        |        |        |                                               |        |        |        |        |        |
 *   `--------------------------------------------'                                               `--------------------------------------------'
 *                                                 -----------------             -----------------
 *                                                | Trans  |Trans   |           | Trans  | Trans  |
 *                                                |        |        |           |        |        |
 *                                        --------|--------|--------|           |--------+--------+--------
 *                                       |        |        | Trans  |           | Trans  |        |        |
 *                                       | Trans  | Trans  |        |           |        | Trans  | Trans  |
 *                                       |        |        |--------|           |--------|        |        |
 *                                       |        |        | Trans  |           | Trans  |        |        |
 *                                       |        |        |        |           |        |        |        |
 *                                       `--------------------------'           `--------------------------'
 */
    LAYOUT_ergodox_pretty(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_LALT, KC_LGUI, KC_TRNS, KC_RSFT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,
                                                              KC_TRNS,            KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,KC_TRNS
    ),
/* Keymap 5: Media layer
 *
 * ,----------------------------------------------------------------.           ,----------------------------------------------------------------.
 * | Reset    |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------|        |           |        |--------+--------+--------+--------+--------+----------|
 * | Layer0   |        |        |        |        |        |________|           |________|        |        |        |        |        |          |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |----------+--------+--------+--------+--------+--------| Trans  |           |        |--------+--------+--------+--------+--------+----------|
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * |          |        |        |        |        |        |        |           |        |        |        |        |        |        |          |
 * `----------+--------+--------+--------+--------+-----------------'           `--------+--------+--------+--------+--------+--------+----------'
 *   |        |        |        |        |        |                                               |        |        |        |        |        |
 *   |        |        |        |        |        |                                               |        |        |        |        |        |
 *   `--------------------------------------------'                                               `--------------------------------------------'
 *                                                 -----------------             -----------------
 *                                                |        |        |           | RGBHUD | RGBHUI |
 *                                                |        |        |           |        |        |
 *                                        --------|--------|--------|           |--------+--------+--------
 *                                       |        |        | RGBSAI |           | RGBVAI |        |        |
 *                                       | RGBTOG |        |        |           |        | RGBMOD | RGBRMOD|
 *                                       |        |        |--------|           |--------|        |        |
 *                                       |        |        | RGBSAD |           | RGBVAD |        |        |
 *                                       |        |        |        |           |        |        |        |
 *                                       `--------------------------'           `--------------------------'
 */
    LAYOUT_ergodox_pretty(
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        TO(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                     KC_NO,   KC_NO,              RGB_HUD, RGB_HUI,
                                                              RGB_SAI,            RGB_VAI,
                                            RGB_TOG, KC_NO,   RGB_SAD,            RGB_VAD, RGB_MOD, RGB_RMOD
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MACRO_0:
                /*
                 * I use this sequence (RALT, LALT+TAB) to
                 * toggle keyboard capture state in my VirtualBox VM (RALT)
                 * and then switch to other application (LALT+TAB)
                 */
                SEND_STRING(SS_TAP(X_RALT)SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_UP(X_LALT));
                return false;
        }
    }

    return true;
};
