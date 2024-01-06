/* FEATURE TOGGLES (uncomment to enable) */

// #define ENABLE_PRONOUNS

/* LAYERS */

#define BASE 0
#define RAISE 1
#define LOWER 2
#define SYM 3
#define NUM 4

/* KEYMAP */

#define HYPER LC(LA(LG(LSHFT)))
#define HP(KEY) LC(LA(LG(LS(KEY))))
#define BT(N) BT_SEL N

/* COUNTS */

#define my_tapping_term 170
#define my_quick_tapping_term 112

/* COMBOS */

#define TYPE BASE SYM NUM

/* BEHAVIOURS */

&mt {
  tapping - term - ms = <my_tapping_term>;
  hold - while - undecided;
};
&sl { release - after - ms = <my_tapping_term>; };
&sk {
  release - after - ms = <2000>;
  quick - release;
};
&caps_word { continue - list = <UNDER MINUS BSPC DEL LEFT RIGHT>; };
&num_word { layers = <NUM>; };

/* NODEFREE CONFIG */
// Adapted from helper.h in https://github.com/urob/zmk-nodefree-config

// Behaviors: ZMK_BEHAVIOR
#define ZMK_BEHAVIOR_CORE_caps_word                                            \
  compatible = "zmk,behavior-caps-word";                                       \
  #binding - cells = <0>
#define ZMK_BEHAVIOR_CORE_dynamic_macro                                        \
  compatible = "zmk,behavior-dynamic-macro";                                   \
  #binding - cells = <1>
#define ZMK_BEHAVIOR_CORE_hold_tap                                             \
  compatible = "zmk,behavior-hold-tap";                                        \
  #binding - cells = <2>
#define ZMK_BEHAVIOR_CORE_key_repeat                                           \
  compatible = "zmk,behavior-key-repeat";                                      \
  #binding - cells = <0>
#define ZMK_BEHAVIOR_CORE_macro_one_param                                      \
  compatible = "zmk,behavior-macro-one-param";                                 \
  #binding - cells = <1>
#define ZMK_BEHAVIOR_CORE_macro_two_param                                      \
  compatible = "zmk,behavior-macro-two-param";                                 \
  #binding - cells = <2>
#define ZMK_BEHAVIOR_CORE_mod_morph                                            \
  compatible = "zmk,behavior-mod-morph";                                       \
  #binding - cells = <0>
#define ZMK_BEHAVIOR_CORE_sticky_key                                           \
  compatible = "zmk,behavior-sticky-key";                                      \
  #binding - cells = <1>
#define ZMK_BEHAVIOR_CORE_tap_dance                                            \
  compatible = "zmk,behavior-tap-dance";                                       \
  #binding - cells = <0>
#define ZMK_BEHAVIOR_CORE_tri_state                                            \
  compatible = "zmk,behavior-tri-state";                                       \
  #binding - cells = <0>
#define ZMK_BEHAVIOR(name, type, ...)                                          \
  name:                                                                        \
  name {                                                                       \
    ZMK_BEHAVIOR_CORE_##type;                                                  \
    __VA_ARGS__                                                                \
  };

// Layers: ZMK_LAYER
#define MACRO_CHOOSER3(_1, _2, _3, FUNC, ...) FUNC
#define ZMK_LAYER(...)                                                         \
  MACRO_CHOOSER3(__VA_ARGS__, ZMK_LAYER_3_ARGS, ZMK_LAYER_2_ARGS)(__VA_ARGS__)
#define ZMK_LAYER_2_ARGS(name, layout)                                         \
  name { bindings = <layout>; };
#define ZMK_LAYER_3_ARGS(name, layout, sensors)                                \
  name {                                                                       \
    bindings = <layout>;                                                       \
    sensor - bindings = <sensors>;                                             \
  };

// Combos: ZMK_COMBOS and ZMK_SK_COMBOS
#define ALL 0xff
#define ZMK_COMBO(name, combo_bindings, keypos, combo_layers)                  \
  name {                                                                       \
    bindings = <combo_bindings>;                                               \
    key - positions = <keypos>;                                                \
    layers = <combo_layers>;                                                   \
    timeout - ms = <30>;                                                       \
  };
#define ZMK_SK_COMBOS(name, combo_bindings, keypos, combo_layers)              \
  nome {                                                                       \
    bindings = <combo_bindings>;                                               \
    key - positions = <keypos>;                                                \
    layers = <combo_layers>;                                                   \
    timeout - ms = <30>;                                                       \
    slow - release;                                                            \
  };
