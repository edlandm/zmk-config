// These custom behaviors are thanks to Sunaku :)
//////////////////////////////////////////////////////////////////////
// NOTE: Use the `#define` settings below to customize this keymap! //
//////////////////////////////////////////////////////////////////////
// IMPORTANT: You need to set Firmware Version to "pr21.zmk-update" //
// under Settings > Advanced Settings in the Glove80 Layout Editor  //
// if you want to use the `hold-trigger-on-release` feature in ZMK  //
// and also the `require-prior-idle-ms` feature for home row mods.  //
//////////////////////////////////////////////////////////////////////
// CAUTION: The PR21 firmware is a beta preview to gather feedback: //
// https://discord.com/channels/877392805654306816/1165858059910918234
//////////////////////////////////////////////////////////////////////
//
// Sunaku's Keymap v27 featuring the Engrammer layout with Miryoku
// - https://github.com/sunaku/glove80-keymaps
//
//////////////////////////////////////////////////////////////////////

behaviors {
	//////////////////////////////////////////////////////////////////
	//
	// Miryoku layers and home row mods (ported from my QMK endgame)
	// - https://sunaku.github.io/home-row-mods.html#porting-to-zmk
	// - https://github.com/urob/zmk-config#timeless-homerow-mods
	//
	//////////////////////////////////////////////////////////////////
	//
	// HOMEY_HOLDING_TYPE defines the flavor of ZMK hold-tap behavior to use
	// for the pinky, ring, and middle fingers (which are assigned to Super,
	// Alt, and Ctrl respectively in the Miryoku system) on home row keys.
	//
	#define HOMEY_HOLDING_TYPE "tap-preferred"
	//
	// HOMEY_HOLDING_TIME defines how long you need to hold (milliseconds)
	// home row mod keys in order to send their modifiers to the computer
	// (i.e. "register" them) for mod-click mouse usage (e.g. Ctrl-Click).
	//
	#define HOMEY_HOLDING_TIME 270 // TAPPING_TERM + ALLOW_CROSSOVER_AFTER
	//
	// HOMEY_STREAK_DECAY defines how long you need to wait (milliseconds)
	// after typing before you can use home row mods again.  It prevents
	// unintended activation of home row mods when you're actively typing.
	//
	#define HOMEY_STREAK_DECAY 170 // global-quick-tap-ms
	//
	//
	// INDEX_HOLDING_TYPE defines the flavor of ZMK hold-tap behavior to use
	// for index fingers (which Miryoku assigns to Shift) on home row keys.
	//
	// NOTE: The "tap-preferred" flavor of ZMK hold-tap for index finger keys
	// allows faster activation of the Shift modifier (without having to wait
	// for the modified key to be released as the "balanced" flavor requires).
	// Typing streaks and the `hold-trigger-on-release` setting are disabled
	// for the index fingers so as not to hinder their speed and dexterity.
	//
	#define INDEX_HOLDING_TYPE "tap-preferred"
	//
	// INDEX_HOLDING_TIME defines how long you need to hold (milliseconds)
	// index finger keys in order to send their modifiers to the computer
	// (i.e. "register" them) for mod-click mouse usage (e.g. Shift-Click).
	//
	// CAUTION: You'll need to perform inward rolls from pinky->ring->middle
	// fingers toward the index fingers when activating multiple modifiers
	// because `hold-trigger-on-release` is disabled for the index fingers.
	// Otherwise, you may be surprised that the index fingers' modifier is
	// sent immediately without the rest of your multi-mod chord when you
	// perform outward rolls from your index fingers toward your pinkies.
	//
	#define INDEX_HOLDING_TIME 190
	//
	// INDEX_STREAK_DECAY defines how long you need to wait (milliseconds)
	// after typing before you can use home row mods again.  It prevents
	// unintended activation of home row mods when you're actively typing.
	//
	#define INDEX_STREAK_DECAY 90 // global-quick-tap-ms
	//
	// THUMB_HOLDING_TYPE defines the flavor of ZMK hold-tap behavior to use
	// for the thumbs (which are assigned to 6 layers in the Miryoku system).
	//
	// NOTE: The "balanced" flavor of ZMK hold-tap provides instant modifier
	// activation for the symbol layer (if the tapped symbol key is released
	// while the thumb layer key is still held down) for quicker programming.
	//
	#define THUMB_HOLDING_TYPE "balanced"
	//
	// THUMB_HOLDING_TIME defines how long you need to hold (milliseconds)
	// a thumb key to activate a layer.  Shorter holds are treated as taps.
	//
	#define THUMB_HOLDING_TIME 170
	//
	// THUMB_REPEAT_DECAY defines how much time you have left (milliseconds)
	// after tapping a key to hold it again in order to make it auto-repeat.
	//
	#define THUMB_REPEAT_DECAY 200 // "tap then hold" for key auto-repeat
	//
	// Glove80 key positions index for positional hold-tap
	// - https://discord.com/channels/877392805654306816/937645688244826154/1066713913351221248
	// - https://media.discordapp.net/attachments/937645688244826154/1066713913133121556/image.png
	//
	// |------------------------|------------------------|
	// | LEFT_HAND_KEYS         |        RIGHT_HAND_KEYS |
	// |                        |                        |
	// |  0  1  2  3  4         |          5  6  7  8  9 |
	// | 10 11 12 13 14 15      |      16 17 18 19 20 21 |
	// | 22 23 24 25 26 27      |      28 29 30 31 32 33 |
	// | 34 35 36 37 38 39      |      40 41 42 43 44 45 |
	// | 46 47 48 49 50 51      |      58 59 60 61 62 63 |
	// | 64 65 66 67 68         |         75 76 77 78 79 |
	// |                69 52   |   57 74                |
	// |                 70 53  |  56 73                 |
	// |                  71 54 | 55 72                  |
	// |------------------------|------------------------|
	//
	#define LEFT_HAND_KEYS      \
		0  1  2  3  4         \
		10 11 12 13 14 15      \
		22 23 24 25 26 27      \
		34 35 36 37 38 39      \
		46 47 48 49 50 51      \
		64 65 66 67 68
#define RIGHT_HAND_KEYS     \
															5  6  7  8  9 \
															16 17 18 19 20 21 \
															28 29 30 31 32 33 \
															40 41 42 43 44 45 \
															58 59 60 61 62 63 \
															75 76 77 78 79
#define THUMB_KEYS          \
										69 52       57 74                \
										70 53     56 73                 \
										71 54   55 72
	//
	// Home row mod-tap keys for all except index fingers
	//
	homey_left: miryoku_home_row_mods_left_hand {
		compatible = "zmk,behavior-hold-tap";
		label = "HOME_ROW_MODS_LEFT_HAND";
		flavor = HOMEY_HOLDING_TYPE;
		hold-trigger-key-positions = <RIGHT_HAND_KEYS THUMB_KEYS>;
		hold-trigger-on-release; // wait for other home row mods
		tapping-term-ms = <HOMEY_HOLDING_TIME>;
		quick-tap-ms = <HOMEY_STREAK_DECAY>;
		require-prior-idle-ms = <HOMEY_STREAK_DECAY>;
		#binding-cells = <2>;
		bindings = <&kp>, <&kp>;
	};
	homey_right: miryoku_home_row_mods_right_hand {
		compatible = "zmk,behavior-hold-tap";
		label = "HOME_ROW_MODS_RIGHT_HAND";
		flavor = HOMEY_HOLDING_TYPE;
		hold-trigger-key-positions = <LEFT_HAND_KEYS THUMB_KEYS>;
		hold-trigger-on-release; // wait for other home row mods
		tapping-term-ms = <HOMEY_HOLDING_TIME>;
		quick-tap-ms = <HOMEY_STREAK_DECAY>;
		require-prior-idle-ms = <HOMEY_STREAK_DECAY>;
		#binding-cells = <2>;
		bindings = <&kp>, <&kp>;
	};
	//
	// Special home row mod-tap keys for the index fingers
	//
	index_left: miryoku_home_row_mods_left_index_shift {
		compatible = "zmk,behavior-hold-tap";
		label = "HOME_ROW_MODS_LEFT_INDEX_SHIFT";
		flavor = INDEX_HOLDING_TYPE;
		hold-trigger-key-positions = <RIGHT_HAND_KEYS THUMB_KEYS>;
		//hold-trigger-on-release; // don't wait for other mods
		tapping-term-ms = <INDEX_HOLDING_TIME>;
		quick-tap-ms = <INDEX_STREAK_DECAY>;
		require-prior-idle-ms = <HOMEY_STREAK_DECAY>;
		#binding-cells = <2>;
		bindings = <&kp>, <&kp>;
	};
	index_right: miryoku_home_row_mods_right_index_shift {
		compatible = "zmk,behavior-hold-tap";
		label = "HOME_ROW_MODS_RIGHT_INDEX_SHIFT";
		flavor = INDEX_HOLDING_TYPE;
		hold-trigger-key-positions = <LEFT_HAND_KEYS THUMB_KEYS>;
		//hold-trigger-on-release; // don't wait for other mods
		tapping-term-ms = <INDEX_HOLDING_TIME>;
		quick-tap-ms = <INDEX_STREAK_DECAY>;
		require-prior-idle-ms = <HOMEY_STREAK_DECAY>;
		#binding-cells = <2>;
		bindings = <&kp>, <&kp>;
	};
	//
	// Thumb cluster hold-tap keys for Miryoku layers
	//
	thumb: miryoku_thumb_layer {
		compatible = "zmk,behavior-hold-tap";
		label = "MIRYOKU_LAYER_TAP_WITH_REPEAT";
		flavor = THUMB_HOLDING_TYPE;
		tapping-term-ms = <THUMB_HOLDING_TIME>;
		quick-tap-ms = <THUMB_REPEAT_DECAY>; // enable repeat
		retro-tap; // allow slow (hold-like) taps
		#binding-cells = <2>;
		bindings = <&mo>, <&kp>;
	};

	// Shift + LEFT_PARENTHESIS = LESS_THAN
	parang_left: left_parenthesis_and_less_than {
		compatible = "zmk,behavior-mod-morph";
		label = "LEFT_PARENTHESIS_AND_LESS_THAN";
		#binding-cells = <0>;
		bindings = <&kp LEFT_PARENTHESIS>, <&kp LESS_THAN>;
		mods = <(MOD_LSFT|MOD_RSFT)>;
	};

	// Shift + RIGHT_PARENTHESIS = GREATER_THAN
	parang_right: right_parenthesis_and_greater_than {
		compatible = "zmk,behavior-mod-morph";
		label = "RIGHT_PARENTHESIS_AND_GREATER_THAN";
		#binding-cells = <0>;
		bindings = <&kp RIGHT_PARENTHESIS>, <&kp GREATER_THAN>;
		mods = <(MOD_LSFT|MOD_RSFT)>;
	};

	// Shift + CapsWord = CapsLock
	cappy: capsword_and_capslock {
		compatible = "zmk,behavior-mod-morph";
		label = "CAPSWORD_AND_CAPSLOCK";
		#binding-cells = <0>;
		bindings = <&caps_word>, <&kp CAPSLOCK>;
		mods = <(MOD_LSFT|MOD_RSFT)>;
	};

	//
	// CapsWord - ported from Pascal Getreuer's extension for QMK
	// - https://zmk.dev/docs/behaviors/caps-word
	// - https://getreuer.info/posts/keyboards/caps-word/index.html
	//
	behavior_caps_word {
		continue-list = <UNDERSCORE MINUS BACKSPACE DELETE N1 N2 N3 N4 N5 N6 N7 N8 N9 N0>;
	};

    // increase sticky-key timeout
    sk {
        release-after-ms = <6000>;
    };

    // increase sticky-layer timeout
    sl {
        release-after-ms = <6000>;
    };
};

macros {
	//////////////////////////////////////////////////////////////////
	//
	// Approximation of Pascal Getreuer's Select Word macro from QMK
	// - https://getreuer.info/posts/keyboards/select-word/index.html
	//
	//////////////////////////////////////////////////////////////////
	//
	// SELECT_WORD_DELAY defines how long the macro waits (milliseconds)
	// after moving the cursor before it selects a word.  A larger delay
	// may allow the macro to move to the next word upon each invocation.
	//
	#define SELECT_WORD_DELAY 1
	//
	// select a word (jumps to next word upon each successive invocation)
	//
	select_word: select_word {
		compatible = "zmk,behavior-mod-morph";
		label = "SELECT_WORD";
		#binding-cells = <0>;
		bindings = <&select_word_right>, <&select_word_left>;
			mods = <(MOD_LSFT|MOD_RSFT)>;
	};
	ZMK_MACRO(select_word_right,
					 wait-ms = <SELECT_WORD_DELAY>;
					 tap-ms = <SELECT_WORD_DELAY>;
					 bindings = <&kp LC(RIGHT) &kp LC(LEFT) &kp LC(LS(RIGHT))>;
					 )
	ZMK_MACRO(select_word_left,
					 wait-ms = <SELECT_WORD_DELAY>;
					 tap-ms = <SELECT_WORD_DELAY>;
					 bindings = <&kp LC(LEFT) &kp LC(RIGHT) &kp LC(LS(LEFT))>;
					 )
	//
	// extend current selection by one word
	//
	extend_word: extend_word {
		compatible = "zmk,behavior-mod-morph";
		label = "EXTEND_WORD";
		#binding-cells = <0>;
		bindings = <&extend_word_right>, <&extend_word_left>;
			mods = <(MOD_LSFT|MOD_RSFT)>;
	};
	ZMK_MACRO(extend_word_right,
					 wait-ms = <SELECT_WORD_DELAY>;
					 tap-ms = <SELECT_WORD_DELAY>;
					 bindings = <&kp LC(LS(RIGHT))>;
					 )
	ZMK_MACRO(extend_word_left,
					 wait-ms = <SELECT_WORD_DELAY>;
					 tap-ms = <SELECT_WORD_DELAY>;
					 bindings = <&kp LC(LS(LEFT))>;
					 )
	//
	// select current line
	//
	select_line: select_line {
		compatible = "zmk,behavior-mod-morph";
		label = "SELECT_LINE";
		#binding-cells = <0>;
		bindings = <&select_line_right>, <&select_line_left>;
			mods = <(MOD_LSFT|MOD_RSFT)>;
	};
	ZMK_MACRO(select_line_right,
					 wait-ms = <SELECT_WORD_DELAY>;
					 tap-ms = <SELECT_WORD_DELAY>;
					 bindings = <&kp HOME &kp LS(END)>;
					 )
	ZMK_MACRO(select_line_left,
					 wait-ms = <SELECT_WORD_DELAY>;
					 tap-ms = <SELECT_WORD_DELAY>;
					 bindings = <&kp END &kp LS(HOME)>;
					 )
	//
	// extend current selection by one line
	//
	extend_line: extend_line {
		compatible = "zmk,behavior-mod-morph";
		label = "EXTEND_LINE";
		#binding-cells = <0>;
		bindings = <&extend_line_right>, <&extend_line_left>;
			mods = <(MOD_LSFT|MOD_RSFT)>;
	};
	ZMK_MACRO(extend_line_right,
					 wait-ms = <SELECT_WORD_DELAY>;
					 tap-ms = <SELECT_WORD_DELAY>;
					 bindings = <&kp LS(DOWN) &kp LS(END)>;
					 )
	ZMK_MACRO(extend_line_left,
					 wait-ms = <SELECT_WORD_DELAY>;
					 tap-ms = <SELECT_WORD_DELAY>;
					 bindings = <&kp LS(UP) &kp LS(HOME)>;
					 )

	#define COMBO(name, keypress, keypos) \
		combo_##name { \
		timeout-ms = <37>; \
		bindings = <keypress>; \
		key-positions = <keypos>; \
		layers = <3>; \
    };

	#define MACRO(name, keys) \
		name: name##_macro { \
		label = #name; \
		compatible = "zmk,behavior-macro"; \
		#binding-cells = <0>; \
		tap-ms = <1>; \
		wait-ms = <1>; \
		bindings = <keys>; \
	};

    // PUNCTUATION MACROS ====================================================
    // enter the punctuation and toggle sticky shift
    MACRO(punc_period, &kp BACKSPACE &kp PERIOD &kp SPC &sk LSFT)
    MACRO(punc_exclamation, &kp BACKSPACE &kp LS(N1) &kp SPC &sk LSFT)
    MACRO(punc_question, &kp BACKSPACE &kp LS(FSLH) &kp SPC &sk LSFT)
    MACRO(punc_space, &kp SPC &sk LSFT)
    // toggle sticky shift
    MACRO(ch_cap, &sk LSFT)
    MACRO(ch_underscore, &kp BACKSPACE &kp LS(MINUS))
    MACRO(ch_minus, &kp BACKSPACE &kp MINUS)
    // CHORDING =======================================================
    MACROS_PLACEHOLDER
};

// These combos only work from my Engram layer
// 74 is my space key
// 57 is underscore
// 69 is backspace
combos {
    compatible = "zmk,combos";
    COMBO(ch_cap, &ch_cap, 74 69)
    COMBO(ch_underscore, &ch_underscore, 69 57)
    COMBO(ch_dash, &ch_minus, 69 51)
    // WORD CHORDS ===========================================================
    COMBOS_PLACEHOLDER
};
