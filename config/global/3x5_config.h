//  Adapted from moutis_config.dtsi in moutis/zmk-config

/*    Key positions for 3x5
    ╭──────────────────────╮ ╭──────────────────────╮
    │   0   1   2   3  4   │ │   5   6   7   8   9  │
    │  10  11  12  13  14  │ │  15  16  17  18  19  │
    │  20  21  22  23  24  │ │  25  26  27  28  29  │
    ╰────────╮ 30  31  32  │ │  33  34  35 ╭────────╯
             ╰─────────────╯ ╰─────────────╯
    ╭──────────────────────╮ ╭──────────────────────╮
    │ LT5 LT4 LT3 LT2 LT2x │ │ RT2x RT1 RT2 RT3 RT4 │
    │ LM4 LM3 LM2 LM1 LM2x │ │ RM2x RM1 RM2 RM3 RM4 │
    │ LB4 LB3 LB2 LB1 LB2x │ │ RB2x RB1 RB2 RB3 RB4 │
    ╰───────╮ L1c L1h L1x  │ │ R1x R1h R1c  ╭───────╯
            ╰──────────────╯ ╰──────────────╯
*/

#define LT2x 4
#define LT2 3
#define LT3 2
#define LT4 1
#define LT5 0
#define RT2x 5
#define RT2 6
#define RT3 7
#define RT4 8
#define RT5 9

#define LM2x 14
#define LM2 13
#define LM3 12
#define LM4 11
#define LM5 10
#define RM2x 15
#define RM2 16
#define RM3 17
#define RM4 18
#define RM5 19

#define LB2x 24
#define LB2 23
#define LB3 22
#define LB4 21
#define LB5 20
#define RB2x 25
#define RB2 26
#define RB3 27
#define RB4 28
#define RB5 29

#define L1c 30
#define L1h 31
#define L1x 32
#define R1x 33
#define R1h 34
#define R1c 35

#define KEYS_L LT2x LT2 LT3 LT4 LT5 LM2x LM2 LM3 LM4 LM5 LB2x LB2 LB3 LB4 LB5 // left-hand keys
#define KEYS_R RT2x RT2 RT3 RT4 RT5 RM2x RM2 RM3 RM4 RM5 RB2x RB2 RB3 RB4 RB5  // right-hand keys
#define THUMBS L1c L1h L1x R1x R1h R1c                                      // thumb keys

// LAYERS

#define BASE  0
#define NAV   1
#define SYM   2
#define NUM   3
#define SYS   4

// TAPPING TERMS

#define my_tapping_term 170
#define my_quick_tapping_term 112

&mt {
    tapping-term-ms = <my_tapping_term>;
    hold-while-undecided;
};
&sl {
    release-after-ms = <my_tapping_term>;
};
&sk {
  release-after-ms = <2000>;
  quick-release;
};
&caps_word {
    continue-list = <UNDER MINUS BSPC DEL LEFT RIGHT>;
};