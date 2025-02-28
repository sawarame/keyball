/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  // https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
  // https://github.com/Yowkees/keyball/blob/main/qmk_firmware/keyboards/keyball/lib/keyball/keycodes.md
  [0] = LAYOUT_universal(
    // 左一段目
    KC_TAB,
    KC_Q, 
    KC_W, 
    KC_E, 
    KC_R, 
    KC_T, 
    // 右一段目
    KC_Y, 
    KC_U, 
    KC_I, 
    KC_O, 
    KC_P, 
    KC_EQUAL,
    // 左二段目
    LCTL_T(KC_LEFT_BRACKET),
    KC_A,
    KC_S,
    KC_D,
    KC_F,
    KC_G,
    // 右二段目
    KC_H, 
    KC_J, 
    KC_K, 
    KC_L, 
    LT(5,KC_SEMICOLON),
    RCTL_T(KC_MINUS),
    // 左三段目
    LSFT_T(KC_RIGHT_BRACKET), 
    KC_Z, 
    LALT_T(KC_X),
    LGUI_T(KC_C), 
    KC_V, 
    KC_B, 
    // 右三段目
    KC_N,
    KC_M,
    RGUI_T(KC_COMM),
    RALT_T(KC_DOT),
    KC_SLSH,
    RSFT_T(KC_BACKSLASH),
    // 左四段目
    KBC_RST,
    KBC_SAVE,
    LT(1,KC_TAB),
    LT(2,KC_SPACE),
    LT(3,KC_ESCAPE),                  
    // 右四段目
    LT(4,KC_BACKSPACE), 
    LT(5,KC_ENTER), 
    _______,
    _______,
    AML_TO
  ),

  [1] = LAYOUT_universal(
    // 左一段目
    _______,
    KC_F1, 
    KC_F2, 
    KC_F3, 
    KC_F4, 
    KC_F5, 
    // 右一段目
    _______,
    _______,
    LSG(KC_LEFT_BRACKET), 
    LSG(KC_LEFT_BRACKET), 
    _______,
    _______,
    // 左二段目
    _______,
    KC_F6,
    KC_F7,
    KC_F8,
    KC_F9,
    KC_F10,
    // 右二段目
    KC_LEFT, 
    KC_DOWN, 
    KC_UP, 
    KC_RIGHT, 
    _______,
    _______,
    // 左三段目
    _______,
    KC_F11, 
    KC_F12, 
    _______,
    _______,
    _______,
    // 右三段目
    _______,
    LSG(KC_V),
    LSG(KC_A),
    LSG(KC_E),
    LCTL(KC_GRAVE),
    _______,
    // 左四段目
    _______,
    _______,
    _______,
    _______,
    _______,
    // 右四段目
    _______,
    _______,
    _______,
    _______,
    _______
  ),

  [2] = LAYOUT_universal(
    // 左一段目
    _______,
    KC_GRAVE, 
    KC_7, 
    KC_8, 
    KC_9, 
    _______, 
    // 右一段目
    _______,
    LSFT(KC_GRAVE),
    LSFT(KC_9), 
    LSFT(KC_0), 
    _______,
    _______,
    // 左二段目
    _______,
    KC_MINUS,
    KC_4,
    KC_5,
    KC_6,
    _______,
    // 右二段目
    LSFT(KC_QUOTE), 
    KC_QUOTE, 
    KC_LEFT_BRACKET, 
    KC_RIGHT_BRACKET, 
    LSFT(KC_BACKSLASH),
    _______,
    // 左三段目
    _______,
    LSFT(KC_EQUAL), 
    KC_1, 
    KC_2,
    KC_3,
    _______,
    // 右三段目
    LSFT(KC_MINUS),
    KC_EQUAL,
    LSFT(KC_LEFT_BRACKET),
    LSFT(KC_RIGHT_BRACKET), 
    KC_BACKSLASH,
    _______,
    // 左四段目
    _______,
    KC_0,
    _______,
    _______,
    _______,
    // 右四段目
    _______,
    _______,
    _______,
    KC_LANGUAGE_2,
    KC_LANGUAGE_1
  ),

  [3] = LAYOUT_universal(
    // 左一段目
    _______,
    _______, 
    _______, 
    _______, 
    _______, 
    _______, 
    // 右一段目
    _______,
    _______,
    _______, 
    _______, 
    _______,
    _______,
    // 左二段目
    _______,
    _______,
    _______,
    _______,
    _______,
    _______,
    // 右二段目
    _______, 
    _______, 
    _______, 
    _______, 
    _______,
    _______,
    // 左三段目
    _______,
    _______, 
    _______, 
    _______,
    _______,
    _______,
    // 右三段目
    _______,
    _______,
    _______,
    _______, 
    _______,
    _______,
    // 左四段目
    _______,
    _______,
    _______,
    _______,
    _______,
    // 右四段目
    _______,
    _______,
    _______,
    _______,
    _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  // Auto enable scroll mode when the highest layer is 2 
  keyball_set_scroll_mode(get_highest_layer(state) == 2);
  return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case LCTL_T(KC_LEFT_BRACKET):
          return true;
      case LSFT_T(KC_RIGHT_BRACKET):
          return true;
      case LALT_T(KC_X):
          return true;
      case LGUI_T(KC_C):
          return true;
      case RCTL_T(KC_QUOTE):
          return true;
      case RCTL_T(KC_MINUS):
          return true;
      case RSFT_T(KC_BACKSLASH):
          return true;
      case RALT_T(KC_DOT):
          return true;
      case RGUI_T(KC_COMMA):
          return true;
      default:
          return false;
  }
}

/* RGB Timeout behaves similar to OLED Timeout where it turns off underglow 
lighting on your QMK board after X seconds of inactivity. The logic is 
best described by this reddit comment - https://bit.ly/3zCYIRl
To begin, add the following variables and function definitions to your keymap.c file */

static uint16_t key_timer; // timer to track the last keyboard activity
static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke whenever activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean


void refresh_rgb() {
  key_timer = timer_read(); // store time of last refresh
  if (is_rgb_timeout) { // only do something if rgb has timed out
    print("Activity detected, removing timeout\n");
    is_rgb_timeout = false;
    rgblight_wakeup();
  }
}

void check_rgb_timeout() {
  if (!is_rgb_timeout && timer_elapsed(key_timer) > RGBLIGHT_TIMEOUT) {
    rgblight_suspend();
    is_rgb_timeout = true;
  }
}


/* Then, call the above functions from QMK's built in post processing functions like so */

/* Runs at the end of each scan loop, check if RGB timeout has occured */
void housekeeping_task_user(void) {
  #ifdef RGBLIGHT_TIMEOUT
  check_rgb_timeout();
  #endif
  
  /* rest of the function code here */
}

/* Runs after each key press, check if activity occurred */
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef RGBLIGHT_TIMEOUT
  if (record->event.pressed) refresh_rgb();
  #endif

  /* rest of the function code here */
}

/* Runs after each encoder tick, check if activity occurred */
void post_encoder_update_user(uint8_t index, bool clockwise) {
  #ifdef RGBLIGHT_TIMEOUT
  refresh_rgb();
  #endif
  
  /* rest of the function code here */
}