/*
 * adapted from helper.h in https://github.com/urob/zmk-nodefree-config
 */

#pragma once

/* ZMK_BEHAVIOR */

#define ZMK_BEHAVIOR_CORE_caps_word       compatible = "zmk,behavior-caps-word";       #binding-cells = <0>
#define ZMK_BEHAVIOR_CORE_dynamic_macro   compatible = "zmk,behavior-dynamic-macro";   #binding-cells = <1>
#define ZMK_BEHAVIOR_CORE_hold_tap        compatible = "zmk,behavior-hold-tap";        #binding-cells = <2>
#define ZMK_BEHAVIOR_CORE_key_repeat      compatible = "zmk,behavior-key-repeat";      #binding-cells = <0>
#define ZMK_BEHAVIOR_CORE_macro_one_param compatible = "zmk,behavior-macro-one-param"; #binding-cells = <1>
#define ZMK_BEHAVIOR_CORE_macro_two_param compatible = "zmk,behavior-macro-two-param"; #binding-cells = <2>
#define ZMK_BEHAVIOR_CORE_mod_morph       compatible = "zmk,behavior-mod-morph";       #binding-cells = <0>
#define ZMK_BEHAVIOR_CORE_sticky_key      compatible = "zmk,behavior-sticky-key";      #binding-cells = <1>
#define ZMK_BEHAVIOR_CORE_tap_dance       compatible = "zmk,behavior-tap-dance";       #binding-cells = <0>
#define ZMK_BEHAVIOR_CORE_tri_state       compatible = "zmk,behavior-tri-state";       #binding-cells = <0>

#define ZMK_BEHAVIOR(name, type, ...) \
    name: name { \
        ZMK_BEHAVIOR_CORE_ ## type; \
        __VA_ARGS__ \
    };

/* ZMK_LAYER */

#define MACRO_CHOOSER3(_1, _2, _3, FUNC, ...) FUNC
#define ZMK_LAYER(...) MACRO_CHOOSER3(__VA_ARGS__, ZMK_LAYER_3_ARGS, ZMK_LAYER_2_ARGS)(__VA_ARGS__)
#define ZMK_LAYER_2_ARGS(name, layout) \
    name { \
        bindings = <layout>; \
    };

#define ZMK_LAYER_3_ARGS(name, layout, sensors) \
    name { \
        bindings = <layout>; \
        sensor-bindings = <sensors>; \
    };

/* ZMK_COMBOS */

#define ALL 0xff
#define ZMK_COMBO(name, combo_bindings, keypos, combo_layers) \
    name { \
        bindings = <combo_bindings>; \
        key-positions = <keypos>; \
        layers = <combo_layers>; \
        timeout-ms = <30>; \
    };