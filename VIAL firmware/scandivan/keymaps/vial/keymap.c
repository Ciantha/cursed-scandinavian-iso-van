// Copyright 2023 Ciantha
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include <stdio.h>
#include "os_detection.h"
#include "magic.h"

enum custom_keycode {
    JWRDL = QK_KB_0,
    JWRDR,
    SWRDL,
    SWRDR,
    TABL,
    TABR,
    DSKTPL,
    DSKTPR
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_HOME:
            if (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) {
                register_mods(MOD_LGUI);
                tap_code(KC_LEFT);
                unregister_mods(MOD_LGUI);
            } else {
                tap_code(KC_HOME);
            }
            break;
        case KC_END:
            if (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) {
                register_mods(MOD_LGUI);
                tap_code(KC_RIGHT);
                unregister_mods(MOD_LGUI);
            } else {
                tap_code(KC_END);
            }
            break;
        case KC_PGUP:
            if (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) {
                register_mods(MOD_LGUI);
                tap_code(KC_UP);
                unregister_mods(MOD_LGUI);
            } else {
                tap_code(KC_PGUP);
            }
            break;
        case KC_PGDN:
            if (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) {
                register_mods(MOD_LGUI);
                tap_code(KC_DOWN);
                unregister_mods(MOD_LGUI);
            } else {
                tap_code(KC_PGDN);
            }
            break;
        case KC_NUM_LOCK:
            if (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) {
                register_mods(MOD_LSFT);
                tap_code(KC_CLEAR);
                unregister_mods(MOD_LSFT);
            } else {
                tap_code(KC_NUM_LOCK);
            }
            break;
        case KC_SCROLL_LOCK:
            if (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) {
                register_mods(MOD_LCTL);
                tap_code(KC_F14);
                unregister_mods(MOD_LCTL);
            } else {
                tap_code(KC_SCROLL_LOCK);
            }
            break;
        case KC_PRINT_SCREEN:
            if (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) {
                register_mods(MOD_LSFT);
                register_mods(MOD_LGUI);
                tap_code(KC_5);
                unregister_mods(MOD_LGUI);
                unregister_mods(MOD_LSFT);
            } else {
                tap_code(KC_PRINT_SCREEN);
            }
            break;
        case JWRDL:
            if (record->event.pressed) {
                (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) ? register_mods(MOD_LALT) : register_mods(MOD_LCTL);
                tap_code(KC_LEFT);
                (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) ? unregister_mods(MOD_LALT) : unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case JWRDR:
            if (record->event.pressed) {
                (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) ? register_mods(MOD_LALT) : register_mods(MOD_LCTL);
                tap_code(KC_RIGHT);
                (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) ? unregister_mods(MOD_LALT) : unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case SWRDL:
            if (record->event.pressed) {
                register_mods(MOD_LSFT);
                (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) ? register_mods(MOD_LALT) : register_mods(MOD_LCTL);
                tap_code(KC_LEFT);
                (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) ? unregister_mods(MOD_LALT) : unregister_mods(MOD_LCTL);
                unregister_mods(MOD_LSFT);
            } else {
            }
            break;
        case SWRDR:
            if (record->event.pressed) {
                register_mods(MOD_LSFT);
                (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) ? register_mods(MOD_LALT) : register_mods(MOD_LCTL);
                tap_code(KC_RIGHT);
                (keymap_config.swap_lctl_lgui && keymap_config.swap_rctl_rgui) ? unregister_mods(MOD_LALT) : unregister_mods(MOD_LCTL);
                unregister_mods(MOD_LSFT);
            } else {
            }
            break;
        case TABL:
            if (record->event.pressed) {
                register_mods(MOD_LCTL);
                register_mods(MOD_LSFT);
                tap_code(KC_TAB);
                unregister_mods(MOD_LSFT);
                unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case TABR:
            if (record->event.pressed) {
                register_mods(MOD_LCTL);
                tap_code(KC_TAB);
                unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case DSKTPL:
            if (record->event.pressed) {
                register_mods(MOD_LCTL);
                if (!keymap_config.swap_lctl_lgui && !keymap_config.swap_rctl_rgui) { register_mods(MOD_LGUI); }
                tap_code(KC_LEFT);
                if (!keymap_config.swap_lctl_lgui && !keymap_config.swap_rctl_rgui) { unregister_mods(MOD_LGUI); }
                unregister_mods(MOD_LCTL);
            } else {
            }
            break;
        case DSKTPR:
            if (record->event.pressed) {
                register_mods(MOD_LCTL);
                if (!keymap_config.swap_lctl_lgui && !keymap_config.swap_rctl_rgui) { register_mods(MOD_LGUI); }
                tap_code(KC_RGHT);
                if (!keymap_config.swap_lctl_lgui && !keymap_config.swap_rctl_rgui) { unregister_mods(MOD_LGUI); }
                unregister_mods(MOD_LCTL);
            } else {
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
         KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,   KC_F1, KC_F2,
         KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_ENT, KC_F3, KC_F4,
         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,         KC_F5, KC_F6,
        KC_LCTL, KC_LALT,      KC_BSPC,              KC_SPC,         KC_LGUI,   KC_ESC, KC_F7, KC_F8
    ),

    [1] = LAYOUT(
         KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV, KC_BSLS, KC_F1, KC_F2,
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_F3, KC_F4,
         KC_MINS, KC_UNDS,  KC_LT,  KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_GT,   KC_EQL,          KC_F5, KC_F6,
         _______,  _______,      _______,              _______,                _______,  _______,  _______,  _______
    ),

    [2] = LAYOUT(
         _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,   _______,            _______,  _______,
         _______,  _______,        _______,                    _______,           _______,           _______,  _______,  _______
    )
};

bool my_is_apple(os_variant_t host) {
    return host == OS_MACOS || host == OS_IOS;
}

uint32_t my_set_magic_swap(uint32_t trigger_time, void *cb_arg) {
    os_variant_t host = detected_host_os();
    uint16_t retry_ms = 500;
    if (my_is_apple(host)) {
      
        keymap_config.swap_lctl_lgui = true;
        keymap_config.swap_rctl_rgui = true;
          
        retry_ms = 0;
    }

    return retry_ms;
}

void keyboard_post_init_user(void) {
    defer_exec(100, my_set_magic_swap, NULL);
}

