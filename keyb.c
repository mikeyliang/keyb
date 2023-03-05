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

#include <stdbool.h>
#include "keyb.h"
#include "print.h"


led_config_t g_led_config = {
  {
    {2,  3,  4,  5,  6,  7,  16,  17,  18,  19,  20,  21,  22,  23,  NO_LED },
    {0,  1,  12,  13,  14,  15,  24,  25,  26,  27,  28,  29,  30,  31,  NO_LED},
    {8,  9,  10,  11,  56,  47,  46,  45,  44,  43,  42,  41,  NO_LED,  40,  NO_LED},
    {57,  58,  59,  60,  32,  33,  34,  35,  36,  37,  38,  NO_LED,  39,  48,  49},
    {61,  62,  63,  NO_LED,  NO_LED,  55,  NO_LED,  NO_LED,  NO_LED,  54,  53,  NO_LED,  52,  51,  50}
    },
    // LED Index to Physical Position
  {
    {32, 0}, {48, 0}, {64, 0}, {80, 0}, {96, 0}, {112, 0}, {32, 16}, {48, 16}, {64, 16}, {80, 16}, {96, 16}, {112, 16}, {128, 16}, {144, 16}, 
    {0, 0}, {16, 0}, {192, 0}, {208, 0}, {224, 0}, {16, 16}, {160, 16}, {176, 16}, {192, 16}, {208, 16}, {224, 16}, {16, 32}, {32, 32}, {48, 32}, 
    {128, 0}, {144, 0}, {160, 0}, {176, 0}, {16, 64}, {96, 48}, {80, 48}, {64, 48}, {48, 48}, {32, 48}, {16, 48}, {224, 32}, {192, 32}, {32, 64}, {48, 64}, {96, 64}, {160, 64}, 
    {64, 32}, {80, 32}, {96, 32}, {112, 32}, {128, 32}, {144, 32}, {160, 32}, {176, 32}, {112, 48}, {128, 48}, 
    {192, 64}, {208, 64}, {224, 64}, {0, 64}, {224, 48}, {208, 48}, {176, 48}, {160, 48}, {144, 48}},
  // LED Index to Flag
  {
    4, 4, 4, 4, 4, 4, 4, 4, 
    4, 4, 4, 4, 4, 4, 4, 4, 
    4, 4, 4, 4, 4, 4, 4, 4, 
    4, 4, 4, 4, 4, 4, 4, 4, 
    4, 4, 4, 4, 4, 4, 4, 4, 
    4, 4, 4, 4, 4, 4, 4, 4, 
    4, 4, 4, 4, 4, 4, 4, 4, 
    4, 4, 4, 4, 4, 4, 4, 4}};

const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {
    /* Refer to IS31 manual for these locations
     *   driver
     *   |  R location
     *   |  |      G location
     *   |  |      |      B location
     *   |  |      |      | */

    // Driver 1 - Matrix 1
    {0, C1_1, C3_2, C4_2},  // LED1
    {0, C1_2, C2_2, C4_3},  // LED2
    {0, C1_3, C2_3, C3_3},  // LED3
    {0, C1_4, C2_4, C3_4},  // LED4
    {0, C1_5, C2_5, C3_5},  // LED5
    {0, C1_6, C2_6, C3_6},  // LED6
    {0, C1_7, C2_7, C3_7},  // LED7
    {0, C1_8, C2_8, C3_8},  // LED8
    {0, C9_1, C8_1, C7_1},  // LED9
    {0, C9_2, C8_2, C7_2},  // LED10
    {0, C9_3, C8_3, C7_3},  // LED11
    {0, C9_4, C8_4, C7_4},  // LED12
    {0, C9_5, C8_5, C7_5},  // LED13
    {0, C9_6, C8_6, C7_6},  // LED14
    {0, C9_7, C8_7, C6_6},  // LED15
    {0, C9_8, C7_7, C6_7},  // LED16

    {0, C1_9, C3_10, C4_10},   // LED17
    {0, C1_10, C2_10, C4_11},  // LED18
    {0, C1_11, C2_11, C3_11},  // LED19
    {0, C1_12, C2_12, C3_12},  // LED20
    {0, C1_13, C2_13, C3_13},  // LED21
    {0, C1_14, C2_14, C3_14},  // LED22
    {0, C1_15, C2_15, C3_15},  // LED23
    {0, C1_16, C2_16, C3_16},  // LED24
    {0, C9_9, C8_9, C7_9},     // LED25
    {0, C9_10, C8_10, C7_10},  // LED26
    {0, C9_11, C8_11, C7_11},  // LED27
    {0, C9_12, C8_12, C7_12},  // LED28
    {0, C9_13, C8_13, C7_13},  // LED29
    {0, C9_14, C8_14, C7_14},  // LED30
    {0, C9_15, C8_15, C6_14},  // LED31
    {0, C9_16, C7_15, C6_15},  // LED32

    {1, C1_1, C3_2, C4_2},  // LED33
    {1, C1_2, C2_2, C4_3},  // LED34
    {1, C1_3, C2_3, C3_3},  // LED35
    {1, C1_4, C2_4, C3_4},  // LED36
    {1, C1_5, C2_5, C3_5},  // LED37
    {1, C1_6, C2_6, C3_6},  // LED38
    {1, C1_7, C2_7, C3_7},  // LED39
    {1, C1_8, C2_8, C3_8},  // LED40
    {1, C9_1, C8_1, C7_1},  // LED41
    {1, C9_2, C8_2, C7_2},  // LED42
    {1, C9_3, C8_3, C7_3},  // LED43
    {1, C9_4, C8_4, C7_4},  // LED44
    {1, C9_5, C8_5, C7_5},  // LED45
    {1, C9_6, C8_6, C7_6},  // LED46
    {1, C9_7, C8_7, C6_6},  // LED47
    {1, C9_8, C7_7, C6_7},  // LED48

    {1, C1_9, C3_10, C4_10},   // LED49
    {1, C1_10, C2_10, C4_11},  // LED50
    {1, C1_11, C2_11, C3_11},  // LED51
    {1, C1_12, C2_12, C3_12},  // LED52
    {1, C1_13, C2_13, C3_13},  // LED53
    {1, C1_14, C2_14, C3_14},  // LED54
    {1, C1_15, C2_15, C3_15},  // LED55
    {1, C1_16, C2_16, C3_16},  // LED56
    {1, C9_9, C8_9, C7_9},     // LED57
    {1, C9_10, C8_10, C7_10},  // LED58
    {1, C9_11, C8_11, C7_11},  // LED59
    {1, C9_12, C8_12, C7_12},  // LED60
    {1, C9_13, C8_13, C7_13},  // LED61
    {1, C9_14, C8_14, C7_14},  // LED62
    {1, C9_15, C8_15, C6_14},  // LED63
    {1, C9_16, C7_15, C6_15},  // LED64

};
