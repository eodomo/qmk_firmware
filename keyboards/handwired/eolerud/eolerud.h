// Copyright 2021 Eric Olerud (@eodomo)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,    k0e,                \
    k10,    k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e,                \
    k20,     k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c,     k2d,                \
    k31,        k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,       k3d,      k3f,      \
    k40,  k41,   k43,                k46,              k4a,  k4b,  k4d, k4e, k4f, k4g, k3g  \
) \
{ \
    { k00,   k01,   k02,   k03,   k04,   k05,   k06, k07,   k08,   k09,   k0a, k0b, k0c,   KC_NO, k0e,   KC_NO, KC_NO }, \
    { k10,   KC_NO, k12,   k13,   k14,   k15,   k16, k17,   k18,   k19,   k1a, k1b, k1c,   k1d,   k1e,   KC_NO, KC_NO }, \
    { k20,   KC_NO, k22,   k23,   k24,   k25,   k26, k27,   k28,   k29,   k2a, k2b, k2c,   k2d,   KC_NO, KC_NO, KC_NO }, \
    { KC_NO, k31,   k32,   k33,   k34,   k35,   k36, k37,   k38,   k39,   k3a, k3b, KC_NO, k3d,   KC_NO, k3f,   k3g   }, \
    { k40,   k41,   KC_NO, k43,   KC_NO, KC_NO, k46, KC_NO, KC_NO, KC_NO, k4a, k4b, KC_NO, k4d,   k4e,   k4f,   k4g   }  \
}
