#include QMK_KEYBOARD_H

// definitions of my special keys
#define MY_ESC  LT(3,KC_ESC)
#define MY_A    LT(3,KC_A)
#define MY_Z    MT(MOD_LSFT, KC_Z)
#define MY_X    MT(MOD_LCTL, KC_X)
#define MY_C    MT(MOD_LGUI, KC_C)
#define MY_V    MT(MOD_LALT, KC_V)
#define MY_M    MT(MOD_LALT, KC_M)
#define MY_COMM MT(MOD_LGUI, KC_COMM)
#define MY_DOT  MT(MOD_RCTL, KC_DOT)
#define MY_SLSH MT(MOD_RSFT, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * Layer 0 /  The QWERTY Layer
     *
     *   Esc hold = Layer 3
     *   A hold   = Layer 3
     *
     *   Z hold = LSFT                                   M hold = LALT
     *   X hold = LCTL                                   , hold = LGUI
     *   C hold = LGUI                                   . hold = RCTL
     *   V hold = LALT                                   / hold = RSFT
     *
     *   MCR0 (MACRO_0) = Sequence RGUI, LALT+TAB
     *
     * ,-----------------------------------------------------------------------------------------------------------.
     * | Tab    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Bksp   |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Esc    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | Entr   |
     * | Layer3 | Layer3 |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | LSft   | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSft   |
     * |        | LSft   | LCtl   | LGui   | LAlt   |        |        | LAlt   | LGui   | RCtl   | RSft   |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------|
     * | Ctrl   | LGui   | Macro0 | Layer4 | Layer1 |      Space      | Layer2 | Left   | Down   | Up     | Right  |
     * |        |        |        |        |        |                 |        |        |        |        |        |
     * `-----------------------------------------------------------------------------------------------------------'
     */

    [0] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        MY_ESC,  MY_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, MY_Z,    MY_X,    MY_C,    MY_V,    KC_B,    KC_N,    MY_M,    MY_COMM, MY_DOT,  MY_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, MACRO_0, MO(4),   MO(1),       KC_SPC,       MO(2),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
        ),

    /*
     * Layer 1 / The Numbers Layer
     *
     * ,-----------------------------------------------------------------------------------------------------------.
     * | Trans  | `      |        |        |        |        |        |        | [      | ]      | \      | Trans  |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Trans  | LSft   | LCtl   | LGui   | LAlt   |        |        | LAlt   | LGui   | Trans  | RSft   | Trans  |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Trans  | Trans  |        |        | Trans  |      Trans      |        | Trans  | Trans  | Trans  | Trans  |
     * |        |        |        |        |        |                 |        |        |        |        |        |
     * `-----------------------------------------------------------------------------------------------------------'
     */

    [1] = LAYOUT_planck_mit(
        KC_TRNS, KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_LALT, KC_LGUI, KC_TRNS, KC_RSFT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_TRNS,     KC_TRNS,      KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    /*
     * Layer 2 / The Symbols Layer
     *
     * ,-----------------------------------------------------------------------------------------------------------.
     * | Trans  | ~      |        |        |        |        |        |        | {      | }      | |      | Trans  |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | !      | @      | #      | $      | %      | ^      | &      | *      | (      | )      | _      | +      |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Trans  | LSft   | LCtl   | LGui   | LAlt   |        |        | LAlt   | LGui   | Trans  | RSft   | Trans  |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Trans  | Trans  | RAlt   |        |        |      Trans      | Trans  | Trans  | Trans  | Trans  | Trans  |
     * |        |        |        |        |        |                 |        |        |        |        |        |
     * `-----------------------------------------------------------------------------------------------------------'
     */

    [2] = LAYOUT_planck_mit(
        KC_TRNS, KC_TILD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_LALT, KC_LGUI, KC_TRNS, KC_RSFT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_RALT, KC_NO,   KC_NO,       KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        ),

    /*
     * Layer 3 / The Navigation Layer
     *
     * ,-----------------------------------------------------------------------------------------------------------.
     * | Reset  |        |        |        |        |        | Bksp   | Del    | Ins    |        | PScr   | Trans  |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Trans  | Trans  | LCtl   | LAlt   | LSft   |        | Left   | Down   | Up     | Right  | '      | "      |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Trans  | LSft   | LCtl   | LGui   | LAlt   |        | Home   | PgDn   | PgUp   | End    |        | Caps   |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Trans  | Trans  |        |        |        |      Trans      |        | Trans  | Trans  | Trans  | App    |
     * |        |        |        |        |        |                 |        |        |        |        |        |
     * `-----------------------------------------------------------------------------------------------------------'
     */

    [3] = LAYOUT_planck_mit(
        RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC, KC_DEL,  KC_INS,  KC_NO,   KC_PSCR, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_LSFT, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_DQUO,
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_LCAP,
        KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,       KC_TRNS,      KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_APP
        ),

    /*
     * Layer 4 / The Function Key Layer
     *
     * ,-----------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Trans  | LSft   | LCtl   | LGui   | LAlt   |        |        | LAlt   | LGui   | RCtl   | RSft   | RSft   |
     * |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | Trans  | Trans  |        | Trans  |        |      Trans      |        | Trans  | Trans  | Trans  | Trans  |
     * |        |        |        |        |        |                 |        |        |        |        |        |
     * `-----------------------------------------------------------------------------------------------------------'
     */

    [4] = LAYOUT_planck_mit(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_LALT, KC_LGUI, KC_RCTL, KC_RSFT, KC_RSFT,
        KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, KC_NO,       KC_TRNS,      KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
