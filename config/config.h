/* LAYERS */

#define BASE  0
#define RAISE 1
#define LOWER 2
#define SYM   3
#define NUM   4

/* FEATURE TOGGLES (uncomment to enable) */

//#define ENABLE_PRONOUN_COMBOS

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