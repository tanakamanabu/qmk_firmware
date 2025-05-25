#include QMK_KEYBOARD_H
#include "config.h"


enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | `    |   1  |   2  |   3  |   4  |   5  |  F7  |                    |   Ps |   6  |   7  |   8  |   9  |   0  |  [   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  =   |   Q  |   W  |   E  |   R  |   T  |  F8  |                    |  Up  |   Y  |   U  |   I  |   O  |   P  |  ]   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  -   |   A  |   S  |   D  |   F  |   G  |  F9  |                    | Down |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  ESC |   Z  |   X  |   C  |   V  |   B  | Ctrl |                    | Ctrl |   N  |   M  |   ,  |   .  |   /  | Zen  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |Lower |  Han |  Alt | Win  |||||||| Bksp | Shift|  Tab |||||||| Enter| Shift| Space|||||||| Left | Right|   \ | Lower |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_GRV ,   KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_F7,                    LSG(KC_S),KC_6,   KC_7, KC_8,    KC_9,    KC_0,    KC_LBRC,
    KC_EQL ,   KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_F8,                          KC_UP,    KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_RBRC,
    KC_MINS,   KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_F9,                          KC_DOWN,  KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_ESC ,   KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_LCTL,                        KC_RCTL,  KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_F14,
    MO(_LOWER),KC_F15,KC_LALT, KC_LWIN,          KC_BSPC, KC_LSFT, KC_TAB,         KC_ENT,KC_RSFT,  KC_SPC,       KC_LEFT, KC_RIGHT,KC_NUBS, MO(_LOWER)
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | BOOT |  F1  |  F2  |  F3  |  F4  |  F5  |  F7  |                    |   PS  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  =   |   1  |   2  |   3  |   4  |   5  |  F8  |                    | Up   |   6  |   7  |   8  |   9  |   0  |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  -   |   A  |   S  |   D  |   F  |   G  |  F9  |                    | Down |  Left|  Down|  Up  |  Right|   ;  | F13 |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  ESC |   Z  |   X  |   C  |   V  |   B  | Ctrl |                    | Ctrl |   N  |   M  |   ,  |   .  |   /  | Kana |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Raise| Kana |  Alt | Win  ||||||||  Del | Shift|  Tab |||||||| Enter| Shift| Space|||||||| HOME | END  |   \  | Raise|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    QK_REBOOT , KC_F1,KC_F2, KC_F3, KC_F4, KC_F5, KC_F7,                        LSG(KC_S), KC_F6, KC_F7,KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_EQL    , KC_1, KC_2,  KC_3,  KC_4,  KC_5,  KC_F8,                          KC_PGUP,   KC_6,  KC_7, KC_8,    KC_9,    KC_0,    KC_F12,
    KC_MINS   , KC_A, KC_S,  KC_D,  KC_F,  KC_G,  KC_F9,                          KC_PGDN, KC_LEFT,  KC_DOWN, KC_UP,    KC_RIGHT,    KC_SCLN, KC_F13,
    KC_ESC    , KC_Z, KC_X,  KC_C,  KC_V,  KC_B,  KC_LCTL,                        KC_RCTL, KC_N,  KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_F13,
    TG(_RAISE),KC_F13,KC_LALT, KC_LWIN,    KC_DEL, KC_LSFT, KC_TAB,         KC_ENT,KC_RSFT, KC_SPC,      KC_HOME, KC_END,KC_NUBS, TG(_RAISE)
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | BOOT |  F1  |  F2  |  F3  |  F4  |  F5  |  F7  |                    |   PS  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |   ↑  |      |      |      |  F8  |                    | Up   |   6  |   7  |   8  |   9  |   0  |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   ←  |   ↓  |   →  |      |      |  F9  |                    | Down |  A|  S|  D  |  F|   G  | F13 |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  ESC |   Z  |   X  |   C  |   V  |   B  | Ctrl |                    | Ctrl |   Z  |   X  |   C  |   V  |   B  | Kana |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Raise| Kana |  Alt | Win  ||||||||  Del | Shift|  Tab |||||||| Enter| Shift| Space|||||||| HOME | END  |   \  | Raise|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    QK_REBOOT ,  KC_F1,KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F7,                        LSG(KC_S), KC_F6, KC_F7,KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_NO , KC_NO, KC_UP,    KC_NO,    KC_NO,    KC_NO,    KC_F8,                          KC_PGUP,   KC_NO,  KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_F12,
    KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT,    KC_NO,    KC_NO,    KC_F9,                         KC_PGDN, KC_A,  KC_S, KC_D,    KC_F,    KC_G, KC_F13,
    KC_ESC , KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    KC_LCTL,                        KC_RCTL, KC_Z,  KC_X, KC_C, KC_V,  KC_B, KC_F13,
    TG(_RAISE),KC_F13, KC_LALT, KC_LWIN,          KC_DEL, KC_LSFT, KC_TAB,         KC_ENT,KC_RSFT, KC_SPC,      KC_HOME, KC_END,KC_NUBS, TG(_RAISE)
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, QK_BOOT, UG_TOGG, UG_NEXT, UG_HUED, UG_HUEU,_______,                       _______, UG_SATD, UG_SATU, UG_VALD, UG_VALU, _______, _______,
    _______, _______, BL_TOGG, BL_BRTG, BL_UP  , BL_DOWN,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
