# WORK IN PROGRESS

# Personal Cheatsheet

PRs required:
- [PR zmkfirmware#1366](https://github.com/zmkfirmware/zmk/pull/1366)
- [PR zmkfirmware#1398](https://github.com/zmkfirmware/zmk/pull/1398)
Other required:
- [urob's zmk-nodefree-config](https://github.com/urob/zmk-nodefree-config)

# Behaviors

- In behaviors list: as below
- In keymap: `&name [parameter]`

## Caps Word
[Full ZMK Docs](https://zmk.dev/docs/behaviors/caps-word)

//ZMK_BEHAVIOR(name, caps_word,
//    continue-list = <UNDERSCORE MINUS>;
//    mods = <(MOD_LSFT)>;
//)

- Default: `&caps_word`; only include definition to alter default values (above)
- `mods` — optional; multiple mods (any of which can be held) are separated by " | "

## Hold-Tap
[Full ZMK Docs](https://zmk.dev/docs/behaviors/hold-tap)

//ZMK_BEHAVIOR(name, hold_tap,
//    flavor = "balanced";
//    tapping-term-ms = <200>;
//    quick-tap-ms = <200>;
//    require-prior-idle-ms = <125>;
//    retro-tap;
//    hold-while-undecided;
//    bindings = <&kp>, <&kp>;
//    hold-trigger-key-positions = <0>;
//)

- `flavor` — alternatives to `balanced`: `tap-preferred`, `hold-preferred`, `tap-unless-interrupted`
- `tapping-term-ms` — optional
- `quick-tap-ms` — optional
- `require-prior-idle-ms` — optional
- `retro-tap` — optional
- `hold-while-undecided` — optional; PR zmkfirmware#1398
- `hold-trigger-key-positions` — optional; positional hold-tap list

## Key Repeat
[Full ZMK Docs](https://zmk.dev/docs/behaviors/key-repeat)

//ZMK_BEHAVIOR(name, key_repeat,
//    usage-pages = <HID_USAGE_KEY>;
//)

- Default: `&key_repeat`; only include definition to alter default values (above)
- `usage-pages` — to also include consumer page keys, add ` HID_USAGE_CONSUMER`

## Macros
[Full ZMK Docs](https://zmk.dev/docs/behaviors/macros)

### No parameters, e.g. `&name` -> "zmk"

//ZMK_MACRO(name,
//    wait-ms = <30>;
//    tap-ms = <40>;
//    bindings = <&kp Z &kp M &kp K>; 
//)

- `wait-ms` — optional
- `tap-ms` — optional
- `bindings` — can include any keycodes from keymap, each included on a new line
- Macro-specific bindings:
  - `macro_press`
  - `macro_tap`
  - `macro_release`
  - `macro_wait_time` (updates wait-ms, takes one param)
  - `macro_tap_time` (updates tap-ms, takes one param)
  - `macro_pause_for_release` (no parameter)

### One parameter, e.g. `&name LSHFT` -> "ZMK"

//ZMK_BEHAVIOR(name, macro_one_param,
//    wait-ms = <30>;
//    tap-ms = <40>;
//    bindings = <&macro_param_1to1>
//             , <&macro_press &kp MACRO_PLACEHOLDER>
//             , <&macro_tap &kp Z &kp M &kp K>
//             , <&macro_param_1to1>
//             , <&macro_release &kp MACRO_PLACEHOLDER>
//             ;  
//)

- `wait-ms` — optional
- `tap-ms` — optional
- `bindings` — can include any keycodes from keymap, each included on a new line
- Macro-specific bindings:
  - `macro_press`
  - `macro_tap`
  - `macro_release`
  - `macro_wait_time` (updates wait-ms, takes one param)
  - `macro_tap_time` (updates tap-ms, takes one param)
  - `macro_pause_for_release` (no parameter)
- Parameterized-macro-specific bindings:
  - `&macro_param_1to1` (passes the **first** parameter of the macro into the **first** parameter of the next behavior in the `bindings` list)
  - `&macro_param_1to2` (passes the **first** parameter of the macro into the **second** parameter of the next behavior in the `bindings` list)
  - `&macro_param_2to1` (passes the **second** parameter of the macro into the **first** parameter of the next behavior in the `bindings` list)
  - `&macro_param_2to2` (passes the **second** parameter of the macro into the **second** parameter of the next behavior in the `bindings` list)

### Two parameters, e.g. `&name LSHFT EXCL` -> "ZMK!"

//ZMK_BEHAVIOR(name, macro_two_param
//    wait-ms = <30>;
//    tap-ms = <40>;
//    bindings = <&macro_param_1to1>
//             , <&macro_press &kp MACRO_PLACEHOLDER>
//             , <&macro_param_2to1>
//             , <&macro_tap &kp Z &kp M &kp K &kp MACRO_PLACEHOLDER>
//             , <&macro_param_1to1>
//             , <&macro_release &kp MACRO_PLACEHOLDER>
//             ;
//)

- `wait-ms` — optional
- `tap-ms` — optional
- `bindings` — can include any keycodes from keymap, each included on a new line
- Macro-specific bindings:
  - `macro_press`
  - `macro_tap`
  - `macro_release`
  - `macro_wait_time` (updates wait-ms, takes one param)
  - `macro_tap_time` (updates tap-ms, takes one param)
  - `macro_pause_for_release` (no parameter)
- Parameterized-macro-specific bindings:
  - `&macro_param_1to1` (passes the **first** parameter of the macro into the **first** parameter of the next behavior in the `bindings` list)
  - `&macro_param_1to2` (passes the **first** parameter of the macro into the **second** parameter of the next behavior in the `bindings` list)
  - `&macro_param_2to1` (passes the **second** parameter of the macro into the **first** parameter of the next behavior in the `bindings` list)
  - `&macro_param_2to2` (passes the **second** parameter of the macro into the **second** parameter of the next behavior in the `bindings` list)

### Mod-Morph
[Full ZMK Docs](https://zmk.dev/docs/behaviors/mod-morph)

//ZMK_BEHAVIOR(name, mod-morph,
//    bindings = <&kp ESC>, <&kp GRAVE>;
//    mods = <(MOD_LGUI|MOD_LSFT|MOD_RGUI|MOD_RSFT)>;
//    keep-mods = <0>;
//)

- `mods` — optional; only include to specify mods that you want to be kept pressed along with the shifted code
- `keep-mods` — optional; only include to specify mods that you want to be kept pressed along with the shifted code
- This particular mod-morph is included in ZMK: `&gresc`

### Sticky Key
[Full ZMK Docs]()

//ZMK_BEHAVIOR(name, sticky-key,
//    bindings = <&kp>;
//    release-after-ms = <1000>;
//    quick-release;
//    ignore-modifiers;
//)

- `quick-release` — optional; deactivates the sticky key on the next key being pressed, as opposed to released
- `ignore-modifiers` optional (on by default); enables the combination of several sticky modifiers; also requiled for chained modifier keycodes
- sticky layers — `&sl KEYCODE` — are [their own behavior](https://zmk.dev/docs/behaviors/sticky-layer) and default to quick-release

### Tap-Dance
[Full ZMK Docs](https://zmk.dev/docs/behaviors/tap-dance)

//ZMK_BEHAVIOR(name, tap-dance,
//    tapping-term-ms = <200>;
//    bindings = <&kp N1>, <&kp N2>, <&kp N3>;
//)

- `bindings` — an array corresponding to the number of taps required
- tap dances resolve immediately when interrupted by another keypress, according to the current value of its counter before the interrupting keybind is registered

### Tri-State
[PR zmkfirmware#1366](https://github.com/zmkfirmware/zmk/pull/1366)

//ZMK_BEHAVIOR(name, tri-state,
//    bindings = <&kp A>, <&kp B>, <&kt C>;
//    ignored-key-positions = <0>;
//    timeout-ms = <10>;
//)

- `timeout-ms` — optional; causes the deactivation behavior to fire when the time has elapsed after releasing the tri-state or a ignored key.