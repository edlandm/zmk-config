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
	MACRO(ch_being, &kp B &kp E &kp I &kp N &kp G &kp SPC)
	MACRO(ch_best, &kp B &kp E &kp S &kp T &kp SPC)
	MACRO(ch_ed, &kp E &kp D &kp SPC)
	MACRO(ch_es, &kp E &kp S &kp SPC)
	MACRO(ch_ing, &kp I &kp N &kp G &kp SPC)
	MACRO(ch_ly, &kp L &kp Y &kp SPC)
	MACRO(ch_er, &kp E &kp R &kp SPC)
	MACRO(ch_s, &kp S &kp SPC)
	MACRO(ch_ion, &kp I &kp O &kp N &kp SPC)
	MACRO(ch_y, &kp Y &kp SPC)
	MACRO(ch_bs_apos_, &kp BACKSPACE &kp APOS &kp SPC)
	MACRO(ch_bs_comma_, &kp BACKSPACE &kp COMMA &kp SPC)
	MACRO(ch_bs___, &kp BACKSPACE &kp PERIOD &kp SPC)
	MACRO(ch_bs_semi_, &kp BACKSPACE &kp SEMI &kp SPC)
	MACRO(ch_bs_ed, &kp BACKSPACE &kp E &kp D &kp SPC)
	MACRO(ch_bs_es, &kp BACKSPACE &kp E &kp S &kp SPC)
	MACRO(ch_bs_ing, &kp BACKSPACE &kp I &kp N &kp G &kp SPC)
	MACRO(ch_bs_ly, &kp BACKSPACE &kp L &kp Y &kp SPC)
	MACRO(ch_bs_er, &kp BACKSPACE &kp E &kp R &kp SPC)
	MACRO(ch_bs_s, &kp BACKSPACE &kp S &kp SPC)
	MACRO(ch_bs_tion, &kp BACKSPACE &kp T &kp I &kp O &kp N &kp SPC)
	MACRO(ch_bs_y, &kp BACKSPACE &kp Y &kp SPC)
	MACRO(ch_bs_apos_d, &kp BACKSPACE &kp APOS &kp D &kp SPC)
	MACRO(ch_bs_apos_ll, &kp BACKSPACE &kp APOS &kp L &kp L &kp SPC)
	MACRO(ch_bs_napos_t, &kp BACKSPACE &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_bs_apos_re, &kp BACKSPACE &kp APOS &kp R &kp E &kp SPC)
	MACRO(ch_bs_apos_s, &kp BACKSPACE &kp APOS &kp S &kp SPC)
	MACRO(ch_bs_apos_ve, &kp BACKSPACE &kp APOS &kp V &kp E &kp SPC)
	MACRO(ch_a, &kp A &kp SPC)
	MACRO(ch_about, &kp A &kp B &kp O &kp U &kp T &kp SPC)
	MACRO(ch_able, &kp A &kp B &kp L &kp E &kp SPC)
	MACRO(ch_maybe, &kp M &kp A &kp Y &kp B &kp E &kp SPC)
	MACRO(ch_fact, &kp F &kp A &kp C &kp T &kp SPC)
	MACRO(ch_change, &kp C &kp H &kp A &kp N &kp G &kp E &kp SPC)
	MACRO(ch_call, &kp C &kp A &kp L &kp L &kp SPC)
	MACRO(ch_came, &kp C &kp A &kp M &kp E &kp SPC)
	MACRO(ch_case, &kp C &kp A &kp S &kp E &kp SPC)
	MACRO(ch_each, &kp E &kp A &kp C &kp H &kp SPC)
	MACRO(ch_head, &kp H &kp E &kp A &kp D &kp SPC)
	MACRO(ch_mean, &kp M &kp E &kp A &kp N &kp SPC)
	MACRO(ch_year, &kp Y &kp E &kp A &kp R &kp SPC)
	MACRO(ch_after, &kp A &kp F &kp T &kp E &kp R &kp SPC)
	MACRO(ch_farm, &kp F &kp A &kp R &kp M &kp SPC)
	MACRO(ch_far, &kp F &kp A &kp R &kp SPC)
	MACRO(ch_again, &kp A &kp G &kp A &kp I &kp N &kp SPC)
	MACRO(ch_gonna, &kp G &kp O &kp N &kp N &kp A &kp SPC)
	MACRO(ch_has, &kp H &kp A &kp S &kp SPC)
	MACRO(ch_than, &kp T &kp H &kp A &kp N &kp SPC)
	MACRO(ch_although, &kp A &kp L &kp T &kp H &kp O &kp U &kp G &kp H &kp SPC)
	MACRO(ch_wait, &kp W &kp A &kp I &kp T &kp SPC)
	MACRO(ch_all_the, &kp A &kp L &kp L &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_all, &kp A &kp L &kp L &kp SPC)
	MACRO(ch_already, &kp A &kp L &kp R &kp E &kp A &kp D &kp Y &kp SPC)
	MACRO(ch_late, &kp L &kp A &kp T &kp E &kp SPC)
	MACRO(ch_always, &kp A &kp L &kp W &kp A &kp Y &kp S &kp SPC)
	MACRO(ch_am_the, &kp A &kp M &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_am, &kp A &kp M &kp SPC)
	MACRO(ch_am_a, &kp A &kp M &kp SPC &kp A &kp SPC)
	MACRO(ch_man, &kp M &kp A &kp N &kp SPC)
	MACRO(ch_same, &kp S &kp A &kp M &kp E &kp SPC)
	MACRO(ch_may, &kp M &kp A &kp Y &kp SPC)
	MACRO(ch_an, &kp A &kp N &kp SPC)
	MACRO(ch_another, &kp A &kp N &kp O &kp T &kp H &kp E &kp R &kp SPC)
	MACRO(ch_want, &kp W &kp A &kp N &kp T &kp SPC)
	MACRO(ch_also, &kp A &kp L &kp S &kp O &kp SPC)
	MACRO(ch_are_the, &kp A &kp R &kp E &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_arenapos_t, &kp A &kp R &kp E &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_are, &kp A &kp R &kp E &kp SPC)
	MACRO(ch_are_a, &kp A &kp R &kp E &kp SPC &kp A &kp SPC)
	MACRO(ch_around, &kp A &kp R &kp O &kp U &kp N &kp D &kp SPC)
	MACRO(ch_real, &kp R &kp E &kp A &kp L &kp SPC)
	MACRO(ch_as_the, &kp A &kp S &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_as, &kp A &kp S &kp SPC)
	MACRO(ch_as_a, &kp A &kp S &kp SPC &kp A &kp SPC)
	MACRO(ch_as_if, &kp A &kp S &kp SPC &kp I &kp F &kp SPC)
	MACRO(ch_status, &kp S &kp T &kp A &kp T &kp U &kp S &kp SPC)
	MACRO(ch_at_the, &kp A &kp T &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_at, &kp A &kp T &kp SPC)
	MACRO(ch_at_a, &kp A &kp T &kp SPC &kp A &kp SPC)
	MACRO(ch_await, &kp A &kp W &kp A &kp I &kp T &kp SPC)
	MACRO(ch_today, &kp T &kp O &kp D &kp A &kp Y &kp SPC)
	MACRO(ch_was_the, &kp W &kp A &kp S &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_wasnapos_t, &kp W &kp A &kp S &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_was, &kp W &kp A &kp S &kp SPC)
	MACRO(ch_was_a, &kp W &kp A &kp S &kp SPC &kp A &kp SPC)
	MACRO(ch_away, &kp A &kp W &kp A &kp Y &kp SPC)
	MACRO(ch_be, &kp B &kp E &kp SPC)
	MACRO(ch_be_the, &kp B &kp E &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_be_a, &kp B &kp E &kp SPC &kp A &kp SPC)
	MACRO(ch_been, &kp B &kp E &kp E &kp N &kp SPC)
	MACRO(ch_before, &kp B &kp E &kp F &kp O &kp R &kp E &kp SPC)
	MACRO(ch_back, &kp B &kp A &kp C &kp K &kp SPC)
	MACRO(ch_backward, &kp B &kp A &kp C &kp K &kp W &kp A &kp R &kp D &kp SPC)
	MACRO(ch_believe, &kp B &kp E &kp L &kp I &kp E &kp V &kp E &kp SPC)
	MACRO(ch_will_be, &kp W &kp I &kp L &kp L &kp SPC &kp B &kp E &kp SPC)
	MACRO(ch_become, &kp B &kp E &kp C &kp O &kp M &kp E &kp SPC)
	MACRO(ch_begin, &kp B &kp E &kp G &kp I &kp N &kp SPC)
	MACRO(ch_both, &kp B &kp O &kp T &kp H &kp SPC)
	MACRO(ch_to_be, &kp T &kp O &kp SPC &kp B &kp E &kp SPC)
	MACRO(ch_better, &kp B &kp E &kp T &kp T &kp E &kp R &kp SPC)
	MACRO(ch_everybody, &kp E &kp V &kp E &kp R &kp Y &kp B &kp O &kp D &kp Y &kp SPC)
	MACRO(ch_but_the, &kp B &kp U &kp T &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_but, &kp B &kp U &kp T &kp SPC)
	MACRO(ch_but_a, &kp B &kp U &kp T &kp SPC &kp A &kp SPC)
	MACRO(ch_between, &kp B &kp E &kp T &kp W &kp E &kp E &kp N &kp SPC)
	MACRO(ch_by_the, &kp B &kp Y &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_by, &kp B &kp Y &kp SPC)
	MACRO(ch_by_a, &kp B &kp Y &kp SPC &kp A &kp SPC)
	MACRO(ch_declare, &kp D &kp E &kp C &kp L &kp A &kp R &kp E &kp SPC)
	MACRO(ch_much, &kp M &kp U &kp C &kp H &kp SPC)
	MACRO(ch_such, &kp S &kp U &kp C &kp H &kp SPC)
	MACRO(ch_with_the, &kp W &kp I &kp T &kp H &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_with, &kp W &kp I &kp T &kp H &kp SPC)
	MACRO(ch_with_a, &kp W &kp I &kp T &kp H &kp SPC &kp A &kp SPC)
	MACRO(ch_couldnapos_t, &kp C &kp O &kp U &kp L &kp D &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_could, &kp C &kp O &kp U &kp L &kp D &kp SPC)
	MACRO(ch_actual, &kp A &kp C &kp T &kp U &kp A &kp L &kp SPC)
	MACRO(ch_actually, &kp A &kp C &kp T &kp U &kp A &kp L &kp L &kp Y &kp SPC)
	MACRO(ch_come, &kp C &kp O &kp M &kp E &kp SPC)
	MACRO(ch_computer, &kp C &kp O &kp M &kp P &kp U &kp T &kp E &kp R &kp SPC)
	MACRO(ch_can_the, &kp C &kp A &kp N &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_canapos_t, &kp C &kp A &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_can, &kp C &kp A &kp N &kp SPC)
	MACRO(ch_can_a, &kp C &kp A &kp N &kp SPC &kp A &kp SPC)
	MACRO(ch_cannot, &kp C &kp A &kp N &kp N &kp O &kp T &kp SPC)
	MACRO(ch_container, &kp C &kp O &kp N &kp T &kp A &kp I &kp N &kp E &kp R &kp SPC)
	MACRO(ch_since, &kp S &kp I &kp N &kp C &kp E &kp SPC)
	MACRO(ch_once, &kp O &kp N &kp C &kp E &kp SPC)
	MACRO(ch_process, &kp P &kp R &kp O &kp C &kp E &kp S &kp S &kp SPC)
	MACRO(ch_without_the, &kp W &kp I &kp T &kp H &kp O &kp U &kp T &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_without, &kp W &kp I &kp T &kp H &kp O &kp U &kp T &kp SPC)
	MACRO(ch_without_a, &kp W &kp I &kp T &kp H &kp O &kp U &kp T &kp SPC &kp A &kp SPC)
	MACRO(ch_which_the, &kp W &kp H &kp I &kp C &kp H &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_which, &kp W &kp H &kp I &kp C &kp H &kp SPC)
	MACRO(ch_which_a, &kp W &kp H &kp I &kp C &kp H &kp SPC &kp A &kp SPC)
	MACRO(ch_and_the, &kp A &kp N &kp D &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_and, &kp A &kp N &kp D &kp SPC)
	MACRO(ch_and_a, &kp A &kp N &kp D &kp SPC &kp A &kp SPC)
	MACRO(ch_end, &kp E &kp N &kp D &kp SPC)
	MACRO(ch_good, &kp G &kp O &kp O &kp D &kp SPC)
	MACRO(ch_had_the, &kp H &kp A &kp D &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_had, &kp H &kp A &kp D &kp SPC)
	MACRO(ch_had_a, &kp H &kp A &kp D &kp SPC &kp A &kp SPC)
	MACRO(ch_didnapos_t, &kp D &kp I &kp D &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_did, &kp D &kp I &kp D &kp SPC)
	MACRO(ch_would, &kp W &kp O &kp U &kp L &kp D &kp SPC)
	MACRO(ch_done, &kp D &kp O &kp N &kp E &kp SPC)
	MACRO(ch_donapos_t, &kp D &kp O &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_do, &kp D &kp O &kp SPC)
	MACRO(ch_order, &kp O &kp R &kp D &kp E &kp R &kp SPC)
	MACRO(ch_youapos_d, &kp Y &kp O &kp U &kp APOS &kp D &kp SPC)
	MACRO(ch_everyday, &kp E &kp V &kp E &kp R &kp Y &kp D &kp A &kp Y &kp SPC)
	MACRO(ch_ready, &kp R &kp E &kp A &kp D &kp Y &kp SPC)
	MACRO(ch_doesnapos_t, &kp D &kp O &kp E &kp S &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_does, &kp D &kp O &kp E &kp S &kp SPC)
	MACRO(ch_day, &kp D &kp A &kp Y &kp SPC)
	MACRO(ch_she, &kp S &kp H &kp E &kp SPC)
	MACRO(ch_sometime, &kp S &kp O &kp M &kp E &kp T &kp I &kp M &kp E &kp SPC)
	MACRO(ch_sometimes, &kp S &kp O &kp M &kp E &kp T &kp I &kp M &kp E &kp S &kp SPC)
	MACRO(ch_time, &kp T &kp I &kp M &kp E &kp SPC)
	MACRO(ch_left, &kp L &kp E &kp F &kp T &kp SPC)
	MACRO(ch_please, &kp P &kp L &kp E &kp A &kp S &kp E &kp SPC)
	MACRO(ch_select, &kp S &kp E &kp L &kp E &kp C &kp T &kp SPC)
	MACRO(ch_let, &kp L &kp E &kp T &kp SPC)
	MACRO(ch_well, &kp W &kp E &kp L &kp L &kp SPC)
	MACRO(ch_me, &kp M &kp E &kp SPC)
	MACRO(ch_need_the, &kp N &kp E &kp E &kp D &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_need, &kp N &kp E &kp E &kp D &kp SPC)
	MACRO(ch_need_a, &kp N &kp E &kp E &kp D &kp SPC &kp A &kp SPC)
	MACRO(ch_never, &kp N &kp E &kp V &kp E &kp R &kp SPC)
	MACRO(ch_need_to, &kp N &kp E &kp E &kp D &kp SPC &kp T &kp O &kp SPC)
	MACRO(ch_new, &kp N &kp E &kp W &kp SPC)
	MACRO(ch_people, &kp P &kp E &kp O &kp P &kp L &kp E &kp SPC)
	MACRO(ch_here, &kp H &kp E &kp R &kp E &kp SPC)
	MACRO(ch_return, &kp R &kp E &kp T &kp U &kp R &kp N &kp SPC)
	MACRO(ch_set, &kp S &kp E &kp T &kp SPC)
	MACRO(ch_use, &kp U &kp S &kp E &kp SPC)
	MACRO(ch_the, &kp T &kp H &kp E &kp SPC)
	MACRO(ch_even, &kp E &kp V &kp E &kp N &kp SPC)
	MACRO(ch_ever, &kp E &kp V &kp E &kp R &kp SPC)
	MACRO(ch_we, &kp W &kp E &kp SPC)
	MACRO(ch_whether, &kp W &kp H &kp E &kp T &kp H &kp E &kp R &kp SPC)
	MACRO(ch_find, &kp F &kp I &kp N &kp D &kp SPC)
	MACRO(ch_moving, &kp M &kp O &kp V &kp I &kp N &kp G &kp SPC)
	MACRO(ch_if_the, &kp I &kp F &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_if, &kp I &kp F &kp SPC)
	MACRO(ch_if_a, &kp I &kp F &kp SPC &kp A &kp SPC)
	MACRO(ch_first, &kp F &kp I &kp R &kp S &kp T &kp SPC)
	MACRO(ch_move, &kp M &kp O &kp V &kp E &kp SPC)
	MACRO(ch_form, &kp F &kp O &kp R &kp M &kp SPC)
	MACRO(ch_from_the, &kp F &kp R &kp O &kp M &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_from, &kp F &kp R &kp O &kp M &kp SPC)
	MACRO(ch_from_a, &kp F &kp R &kp O &kp M &kp SPC &kp A &kp SPC)
	MACRO(ch_of_the, &kp O &kp F &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_of, &kp O &kp F &kp SPC)
	MACRO(ch_of_a, &kp O &kp F &kp SPC &kp A &kp SPC)
	MACRO(ch_printf, &kp P &kp R &kp I &kp N &kp T &kp F &kp SPC)
	MACRO(ch_for_the, &kp F &kp O &kp R &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_for, &kp F &kp O &kp R &kp SPC)
	MACRO(ch_for_a, &kp F &kp O &kp R &kp SPC &kp A &kp SPC)
	MACRO(ch_function, &kp F &kp U &kp N &kp C &kp T &kp I &kp O &kp N &kp SPC)
	MACRO(ch_thing, &kp T &kp H &kp I &kp N &kp G &kp SPC)
	MACRO(ch_anything, &kp A &kp N &kp Y &kp T &kp H &kp I &kp N &kp G &kp SPC)
	MACRO(ch_nothing, &kp N &kp O &kp T &kp H &kp I &kp N &kp G &kp SPC)
	MACRO(ch_might, &kp M &kp I &kp G &kp H &kp T &kp SPC)
	MACRO(ch_going, &kp G &kp O &kp I &kp N &kp G &kp SPC)
	MACRO(ch_something, &kp S &kp O &kp M &kp E &kp T &kp H &kp I &kp N &kp G &kp SPC)
	MACRO(ch_gone, &kp G &kp O &kp N &kp E &kp SPC)
	MACRO(ch_going_to, &kp G &kp O &kp I &kp N &kp G &kp SPC &kp T &kp O &kp SPC)
	MACRO(ch_go, &kp G &kp O &kp SPC)
	MACRO(ch_got, &kp G &kp O &kp T &kp SPC)
	MACRO(ch_great, &kp G &kp R &kp E &kp A &kp T &kp SPC)
	MACRO(ch_everything, &kp E &kp V &kp E &kp R &kp Y &kp T &kp H &kp I &kp N &kp G &kp SPC)
	MACRO(ch_get, &kp G &kp E &kp T &kp SPC)
	MACRO(ch_give, &kp G &kp I &kp V &kp E &kp SPC)
	MACRO(ch_how, &kp H &kp O &kp W &kp SPC)
	MACRO(ch_he, &kp H &kp E &kp SPC)
	MACRO(ch_having, &kp H &kp A &kp V &kp I &kp N &kp G &kp SPC)
	MACRO(ch_this, &kp T &kp H &kp I &kp S &kp SPC)
	MACRO(ch_him, &kp H &kp I &kp M &kp SPC)
	MACRO(ch_while, &kp W &kp H &kp I &kp L &kp E &kp SPC)
	MACRO(ch_think, &kp T &kp H &kp I &kp N &kp K &kp SPC)
	MACRO(ch_thanks, &kp T &kp H &kp A &kp N &kp K &kp S &kp SPC)
	MACRO(ch_them, &kp T &kp H &kp E &kp M &kp SPC)
	MACRO(ch_home, &kp H &kp O &kp M &kp E &kp SPC)
	MACRO(ch_then, &kp T &kp H &kp E &kp N &kp SPC)
	MACRO(ch_those, &kp T &kp H &kp O &kp S &kp E &kp SPC)
	MACRO(ch_other, &kp O &kp T &kp H &kp E &kp R &kp SPC)
	MACRO(ch_though, &kp T &kp H &kp O &kp U &kp G &kp H &kp SPC)
	MACRO(ch_however, &kp H &kp O &kp W &kp E &kp V &kp E &kp R &kp SPC)
	MACRO(ch_whose, &kp W &kp H &kp O &kp S &kp E &kp SPC)
	MACRO(ch_help, &kp H &kp E &kp L &kp P &kp SPC)
	MACRO(ch_these, &kp T &kp H &kp E &kp S &kp E &kp SPC)
	MACRO(ch_that_the, &kp T &kp H &kp A &kp T &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_thatapos_s, &kp T &kp H &kp A &kp T &kp APOS &kp S &kp SPC)
	MACRO(ch_that, &kp T &kp H &kp A &kp T &kp SPC)
	MACRO(ch_that_a, &kp T &kp H &kp A &kp T &kp SPC &kp A &kp SPC)
	MACRO(ch_through, &kp T &kp H &kp R &kp O &kp U &kp G &kp H &kp SPC)
	MACRO(ch_havenapos_t, &kp H &kp A &kp V &kp E &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_have, &kp H &kp A &kp V &kp E &kp SPC)
	MACRO(ch_where, &kp W &kp H &kp E &kp R &kp E &kp SPC)
	MACRO(ch_they, &kp T &kp H &kp E &kp Y &kp SPC)
	MACRO(ch_i, &kp LS(I) &kp SPC)
	MACRO(ch_git, &kp G &kp I &kp T &kp SPC)
	MACRO(ch_like_the, &kp L &kp I &kp K &kp E &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_like, &kp L &kp I &kp K &kp E &kp SPC)
	MACRO(ch_like_a, &kp L &kp I &kp K &kp E &kp SPC &kp A &kp SPC)
	MACRO(ch_iapos_ll, &kp LS(I) &kp APOS &kp L &kp L &kp SPC)
	MACRO(ch_list, &kp L &kp I &kp S &kp T &kp SPC)
	MACRO(ch_still, &kp S &kp T &kp I &kp L &kp L &kp SPC)
	MACRO(ch_little, &kp L &kp I &kp T &kp T &kp L &kp E &kp SPC)
	MACRO(ch_iapos_m, &kp LS(I) &kp APOS &kp M &kp SPC)
	MACRO(ch_important, &kp I &kp M &kp P &kp O &kp R &kp T &kp A &kp N &kp T &kp SPC)
	MACRO(ch_in_the, &kp I &kp N &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_in, &kp I &kp N &kp SPC)
	MACRO(ch_in_a, &kp I &kp N &kp SPC &kp A &kp SPC)
	MACRO(ch_into_the, &kp I &kp N &kp T &kp O &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_into, &kp I &kp N &kp T &kp O &kp SPC)
	MACRO(ch_into_a, &kp I &kp N &kp T &kp O &kp SPC &kp A &kp SPC)
	MACRO(ch_right, &kp R &kp I &kp G &kp H &kp T &kp SPC)
	MACRO(ch_their, &kp T &kp H &kp E &kp I &kp R &kp SPC)
	MACRO(ch_is_the, &kp I &kp S &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_isnapos_t, &kp I &kp S &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_is, &kp I &kp S &kp SPC)
	MACRO(ch_is_a, &kp I &kp S &kp SPC &kp A &kp SPC)
	MACRO(ch_its, &kp I &kp T &kp S &kp SPC)
	MACRO(ch_itapos_s_the, &kp I &kp T &kp APOS &kp S &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_itapos_s, &kp I &kp T &kp APOS &kp S &kp SPC)
	MACRO(ch_itapos_s_a, &kp I &kp T &kp APOS &kp S &kp SPC &kp A &kp SPC)
	MACRO(ch_it, &kp I &kp T &kp SPC)
	MACRO(ch_iapos_ve, &kp LS(I) &kp APOS &kp V &kp E &kp SPC)
	MACRO(ch_will_the, &kp W &kp I &kp L &kp L &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_wonapos_t, &kp W &kp O &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_will, &kp W &kp I &kp L &kp L &kp SPC)
	MACRO(ch_will_a, &kp W &kp I &kp L &kp L &kp SPC &kp A &kp SPC)
	MACRO(ch_made_the, &kp M &kp A &kp D &kp E &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_made, &kp M &kp A &kp D &kp E &kp SPC)
	MACRO(ch_made_a, &kp M &kp A &kp D &kp E &kp SPC &kp A &kp SPC)
	MACRO(ch_just_the, &kp J &kp U &kp S &kp T &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_just, &kp J &kp U &kp S &kp T &kp SPC)
	MACRO(ch_just_a, &kp J &kp U &kp S &kp T &kp SPC &kp A &kp SPC)
	MACRO(ch_make_the, &kp M &kp A &kp K &kp E &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_make, &kp M &kp A &kp K &kp E &kp SPC)
	MACRO(ch_make_a, &kp M &kp A &kp K &kp E &kp SPC &kp A &kp SPC)
	MACRO(ch_know, &kp K &kp N &kp O &kp W &kp SPC)
	MACRO(ch_keep, &kp K &kp E &kp E &kp P &kp SPC)
	MACRO(ch_because_the, &kp B &kp E &kp C &kp A &kp U &kp S &kp E &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_because, &kp B &kp E &kp C &kp A &kp U &kp S &kp E &kp SPC)
	MACRO(ch_because_a, &kp B &kp E &kp C &kp A &kp U &kp S &kp E &kp SPC &kp A &kp SPC)
	MACRO(ch_work, &kp W &kp O &kp R &kp K &kp SPC)
	MACRO(ch_look, &kp L &kp O &kp O &kp K &kp SPC)
	MACRO(ch_looks, &kp L &kp O &kp O &kp K &kp S &kp SPC)
	MACRO(ch_only_the, &kp O &kp N &kp L &kp Y &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_only, &kp O &kp N &kp L &kp Y &kp SPC)
	MACRO(ch_only_a, &kp O &kp N &kp L &kp Y &kp SPC &kp A &kp SPC)
	MACRO(ch_youapos_ll, &kp Y &kp O &kp U &kp APOS &kp L &kp L &kp SPC)
	MACRO(ch_should_the, &kp S &kp H &kp O &kp U &kp L &kp D &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_shouldnapos_t, &kp S &kp H &kp O &kp U &kp L &kp D &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_should, &kp S &kp H &kp O &kp U &kp L &kp D &kp SPC)
	MACRO(ch_should_a, &kp S &kp H &kp O &kp U &kp L &kp D &kp SPC &kp A &kp SPC)
	MACRO(ch_last, &kp L &kp A &kp S &kp T &kp SPC)
	MACRO(ch_tell, &kp T &kp E &kp L &kp L &kp SPC)
	MACRO(ch_leave, &kp L &kp E &kp A &kp V &kp E &kp SPC)
	MACRO(ch_wouldnapos_t, &kp W &kp O &kp U &kp L &kp D &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_many, &kp M &kp A &kp N &kp Y &kp SPC)
	MACRO(ch_money, &kp M &kp O &kp N &kp E &kp Y &kp SPC)
	MACRO(ch_most, &kp M &kp O &kp S &kp T &kp SPC)
	MACRO(ch_mostly, &kp M &kp O &kp S &kp T &kp L &kp Y &kp SPC)
	MACRO(ch_more, &kp M &kp O &kp R &kp E &kp SPC)
	MACRO(ch_some, &kp S &kp O &kp M &kp E &kp SPC)
	MACRO(ch_system, &kp S &kp Y &kp S &kp T &kp E &kp M &kp SPC)
	MACRO(ch_mustapos_ve, &kp M &kp U &kp S &kp T &kp APOS &kp V &kp E &kp SPC)
	MACRO(ch_must, &kp M &kp U &kp S &kp T &kp SPC)
	MACRO(ch_my, &kp M &kp Y &kp SPC)
	MACRO(ch_no, &kp N &kp O &kp SPC)
	MACRO(ch_ainapos_t, &kp A &kp I &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_on_the, &kp O &kp N &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_on, &kp O &kp N &kp SPC)
	MACRO(ch_on_a, &kp O &kp N &kp SPC &kp A &kp SPC)
	MACRO(ch_now, &kp N &kp O &kp W &kp SPC)
	MACRO(ch_near, &kp N &kp E &kp A &kp R &kp SPC)
	MACRO(ch_not_the, &kp N &kp O &kp T &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_not, &kp N &kp O &kp T &kp SPC)
	MACRO(ch_not_a, &kp N &kp O &kp T &kp SPC &kp A &kp SPC)
	MACRO(ch_onto_the, &kp O &kp N &kp T &kp O &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_onto, &kp O &kp N &kp T &kp O &kp SPC)
	MACRO(ch_onto_a, &kp O &kp N &kp T &kp O &kp SPC &kp A &kp SPC)
	MACRO(ch_when_the, &kp W &kp H &kp E &kp N &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_when, &kp W &kp H &kp E &kp N &kp SPC)
	MACRO(ch_when_a, &kp W &kp H &kp E &kp N &kp SPC &kp A &kp SPC)
	MACRO(ch_next, &kp N &kp E &kp X &kp T &kp SPC)
	MACRO(ch_any, &kp A &kp N &kp Y &kp SPC)
	MACRO(ch_open, &kp O &kp P &kp E &kp N &kp SPC)
	MACRO(ch_or_the, &kp O &kp R &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_or, &kp O &kp R &kp SPC)
	MACRO(ch_or_a, &kp O &kp R &kp SPC &kp A &kp SPC)
	MACRO(ch_tomorrow, &kp T &kp O &kp M &kp O &kp R &kp R &kp O &kp W &kp SPC)
	MACRO(ch_our, &kp O &kp U &kp R &kp SPC)
	MACRO(ch_your, &kp Y &kp O &kp U &kp R &kp SPC)
	MACRO(ch_everyone, &kp E &kp V &kp E &kp R &kp Y &kp O &kp N &kp E &kp SPC)
	MACRO(ch_world, &kp W &kp O &kp R &kp L &kp D &kp SPC)
	MACRO(ch_so_the, &kp S &kp O &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_so, &kp S &kp O &kp SPC)
	MACRO(ch_so_a, &kp S &kp O &kp SPC &kp A &kp SPC)
	MACRO(ch_to_the, &kp T &kp O &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_to, &kp T &kp O &kp SPC)
	MACRO(ch_to_a, &kp T &kp O &kp SPC &kp A &kp SPC)
	MACRO(ch_out, &kp O &kp U &kp T &kp SPC)
	MACRO(ch_youapos_ve, &kp Y &kp O &kp U &kp APOS &kp V &kp E &kp SPC)
	MACRO(ch_you, &kp Y &kp O &kp U &kp SPC)
	MACRO(ch_over_the, &kp O &kp V &kp E &kp R &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_over, &kp O &kp V &kp E &kp R &kp SPC)
	MACRO(ch_over_a, &kp O &kp V &kp E &kp R &kp SPC &kp A &kp SPC)
	MACRO(ch_who, &kp W &kp H &kp O &kp SPC)
	MACRO(ch_print, &kp P &kp R &kp I &kp N &kp T &kp SPC)
	MACRO(ch_up, &kp U &kp P &kp SPC)
	MACRO(ch_request, &kp R &kp E &kp Q &kp U &kp E &kp S &kp T &kp SPC)
	MACRO(ch_query, &kp Q &kp U &kp E &kp R &kp Y &kp SPC)
	MACRO(ch_sure, &kp S &kp U &kp R &kp E &kp SPC)
	MACRO(ch_there, &kp T &kp H &kp E &kp R &kp E &kp SPC)
	MACRO(ch_every, &kp E &kp V &kp E &kp R &kp Y &kp SPC)
	MACRO(ch_were_the, &kp W &kp E &kp R &kp E &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_werenapos_t, &kp W &kp E &kp R &kp E &kp N &kp APOS &kp T &kp SPC)
	MACRO(ch_were, &kp W &kp E &kp R &kp E &kp SPC)
	MACRO(ch_were_a, &kp W &kp E &kp R &kp E &kp SPC &kp A &kp SPC)
	MACRO(ch_everywhere, &kp E &kp V &kp E &kp R &kp Y &kp W &kp H &kp E &kp R &kp E &kp SPC)
	MACRO(ch_really, &kp R &kp E &kp A &kp L &kp L &kp Y &kp SPC)
	MACRO(ch_yesterday, &kp Y &kp E &kp S &kp T &kp E &kp R &kp D &kp A &kp Y &kp SPC)
	MACRO(ch_us, &kp U &kp S &kp SPC)
	MACRO(ch_take_the, &kp T &kp A &kp K &kp E &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_take, &kp T &kp A &kp K &kp E &kp SPC)
	MACRO(ch_take_a, &kp T &kp A &kp K &kp E &kp SPC &kp A &kp SPC)
	MACRO(ch_took_the, &kp T &kp O &kp O &kp K &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_took, &kp T &kp O &kp O &kp K &kp SPC)
	MACRO(ch_took_a, &kp T &kp O &kp O &kp K &kp SPC &kp A &kp SPC)
	MACRO(ch_too, &kp T &kp O &kp O &kp SPC)
	MACRO(ch_what_the, &kp W &kp H &kp A &kp T &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_what, &kp W &kp H &kp A &kp T &kp SPC)
	MACRO(ch_what_a, &kp W &kp H &kp A &kp T &kp SPC &kp A &kp SPC)
	MACRO(ch_until_the, &kp U &kp N &kp T &kp I &kp L &kp SPC &kp T &kp H &kp E &kp SPC)
	MACRO(ch_until, &kp U &kp N &kp T &kp I &kp L &kp SPC)
	MACRO(ch_until_a, &kp U &kp N &kp T &kp I &kp L &kp SPC &kp A &kp SPC)
	MACRO(ch_way, &kp W &kp A &kp Y &kp SPC)
	MACRO(ch_very, &kp V &kp E &kp R &kp Y &kp SPC)
	MACRO(ch_why, &kp W &kp H &kp Y &kp SPC)
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
	COMBO(ch_being, &ch_being, 74 23 37 36)
	COMBO(ch_best, &ch_best, 74 23 43 42)
	COMBO(ch_ed, &ch_ed, 74 30)
	COMBO(ch_es, &ch_es, 74 37)
	COMBO(ch_ing, &ch_ing, 74 47)
	COMBO(ch_ly, &ch_ly, 74 29)
	COMBO(ch_er, &ch_er, 74 59)
	COMBO(ch_s, &ch_s, 74 43)
	COMBO(ch_ion, &ch_ion, 74 48)
	COMBO(ch_y, &ch_y, 74 24)
	COMBO(ch_bs_apos_, &ch_bs_apos_, 69 27)
	COMBO(ch_bs_comma_, &ch_bs_comma_, 69 39)
	COMBO(ch_bs___, &ch_bs___, 69 40)
	COMBO(ch_bs_semi_, &ch_bs_semi_, 69 28)
	COMBO(ch_bs_ed, &ch_bs_ed, 69 30)
	COMBO(ch_bs_es, &ch_bs_es, 69 37)
	COMBO(ch_bs_ing, &ch_bs_ing, 69 47)
	COMBO(ch_bs_ly, &ch_bs_ly, 69 29)
	COMBO(ch_bs_er, &ch_bs_er, 69 59)
	COMBO(ch_bs_s, &ch_bs_s, 69 43)
	COMBO(ch_bs_tion, &ch_bs_tion, 69 48)
	COMBO(ch_bs_y, &ch_bs_y, 69 24)
	COMBO(ch_bs_apos_d, &ch_bs_apos_d, 27 30)
	COMBO(ch_bs_apos_ll, &ch_bs_apos_ll, 27 29)
	COMBO(ch_bs_napos_t, &ch_bs_napos_t, 27 44)
	COMBO(ch_bs_apos_re, &ch_bs_apos_re, 27 59)
	COMBO(ch_bs_apos_s, &ch_bs_apos_s, 27 43)
	COMBO(ch_bs_apos_ve, &ch_bs_apos_ve, 27 32)
	COMBO(ch_a, &ch_a, 38 74)
	COMBO(ch_about, &ch_about, 38 23)
	COMBO(ch_able, &ch_able, 38 23 29)
	COMBO(ch_maybe, &ch_maybe, 38 23 60)
	COMBO(ch_fact, &ch_fact, 38 35 61)
	COMBO(ch_change, &ch_change, 38 35 41)
	COMBO(ch_call, &ch_call, 38 35 29)
	COMBO(ch_came, &ch_came, 38 35 60)
	COMBO(ch_case, &ch_case, 38 35 43)
	COMBO(ch_each, &ch_each, 38 37 41)
	COMBO(ch_head, &ch_head, 38 37 41 30)
	COMBO(ch_mean, &ch_mean, 38 37 60 44)
	COMBO(ch_year, &ch_year, 38 37 24)
	COMBO(ch_after, &ch_after, 38 61)
	COMBO(ch_farm, &ch_farm, 38 61 60 59)
	COMBO(ch_far, &ch_far, 38 61 59)
	COMBO(ch_again, &ch_again, 38 47)
	COMBO(ch_gonna, &ch_gonna, 38 47 44)
	COMBO(ch_has, &ch_has, 38 41)
	COMBO(ch_than, &ch_than, 38 41 44)
	COMBO(ch_although, &ch_although, 38 41 25)
	COMBO(ch_wait, &ch_wait, 38 36 42 31)
	COMBO(ch_all_the, &ch_all_the, 38 29 74)
	COMBO(ch_all, &ch_all, 38 29)
	COMBO(ch_already, &ch_already, 38 29 30)
	COMBO(ch_late, &ch_late, 38 29 42)
	COMBO(ch_always, &ch_always, 38 29 31)
	COMBO(ch_am_the, &ch_am_the, 38 60 74)
	COMBO(ch_am, &ch_am, 38 60)
	COMBO(ch_am_a, &ch_am_a, 38 60 57)
	COMBO(ch_man, &ch_man, 38 60 44)
	COMBO(ch_same, &ch_same, 38 60 43)
	COMBO(ch_may, &ch_may, 38 60 24)
	COMBO(ch_an, &ch_an, 38 44)
	COMBO(ch_another, &ch_another, 38 44 25)
	COMBO(ch_want, &ch_want, 38 44 31)
	COMBO(ch_also, &ch_also, 38 25)
	COMBO(ch_are_the, &ch_are_the, 38 59 74)
	COMBO(ch_arenapos_t, &ch_arenapos_t, 38 59 69)
	COMBO(ch_are, &ch_are, 38 59)
	COMBO(ch_are_a, &ch_are_a, 38 59 57)
	COMBO(ch_around, &ch_around, 38 59 30)
	COMBO(ch_real, &ch_real, 38 59 37)
	COMBO(ch_as_the, &ch_as_the, 38 43 74)
	COMBO(ch_as, &ch_as, 38 43)
	COMBO(ch_as_a, &ch_as_a, 38 43 57)
	COMBO(ch_as_if, &ch_as_if, 38 43 36)
	COMBO(ch_status, &ch_status, 38 43 42)
	COMBO(ch_at_the, &ch_at_the, 38 42 74)
	COMBO(ch_at, &ch_at, 38 42)
	COMBO(ch_at_a, &ch_at_a, 38 42 57)
	COMBO(ch_await, &ch_await, 38 42 31)
	COMBO(ch_today, &ch_today, 38 42 24)
	COMBO(ch_was_the, &ch_was_the, 38 31 74)
	COMBO(ch_wasnapos_t, &ch_wasnapos_t, 38 31 69)
	COMBO(ch_was, &ch_was, 38 31)
	COMBO(ch_was_a, &ch_was_a, 38 31 57)
	COMBO(ch_away, &ch_away, 38 31 24)
	COMBO(ch_be, &ch_be, 23 74)
	COMBO(ch_be_the, &ch_be_the, 23 37 74)
	COMBO(ch_be_a, &ch_be_a, 23 37 57)
	COMBO(ch_been, &ch_been, 23 37 44)
	COMBO(ch_before, &ch_before, 23 61)
	COMBO(ch_back, &ch_back, 23 50)
	COMBO(ch_backward, &ch_backward, 23 50 31)
	COMBO(ch_believe, &ch_believe, 23 29 32)
	COMBO(ch_will_be, &ch_will_be, 23 29 31)
	COMBO(ch_become, &ch_become, 23 60)
	COMBO(ch_begin, &ch_begin, 23 44)
	COMBO(ch_both, &ch_both, 23 25)
	COMBO(ch_to_be, &ch_to_be, 23 25 42)
	COMBO(ch_better, &ch_better, 23 59 42)
	COMBO(ch_everybody, &ch_everybody, 23 59 32)
	COMBO(ch_but_the, &ch_but_the, 23 42 26 74)
	COMBO(ch_but, &ch_but, 23 42 26)
	COMBO(ch_but_a, &ch_but_a, 23 42 26 57)
	COMBO(ch_between, &ch_between, 23 42 31)
	COMBO(ch_by_the, &ch_by_the, 23 24 74)
	COMBO(ch_by, &ch_by, 23 24)
	COMBO(ch_by_a, &ch_by_a, 23 24 57)
	COMBO(ch_declare, &ch_declare, 35 30 29)
	COMBO(ch_much, &ch_much, 35 41 60)
	COMBO(ch_such, &ch_such, 35 41 43)
	COMBO(ch_with_the, &ch_with_the, 35 36 74)
	COMBO(ch_with, &ch_with, 35 36)
	COMBO(ch_with_a, &ch_with_a, 35 36 57)
	COMBO(ch_couldnapos_t, &ch_couldnapos_t, 35 29 69)
	COMBO(ch_could, &ch_could, 35 29)
	COMBO(ch_actual, &ch_actual, 35 29 26)
	COMBO(ch_actually, &ch_actually, 35 29 26 24)
	COMBO(ch_come, &ch_come, 35 60)
	COMBO(ch_computer, &ch_computer, 35 60 62 59)
	COMBO(ch_can_the, &ch_can_the, 35 44 74)
	COMBO(ch_canapos_t, &ch_canapos_t, 35 44 69)
	COMBO(ch_can, &ch_can, 35 44)
	COMBO(ch_can_a, &ch_can_a, 35 44 57)
	COMBO(ch_cannot, &ch_cannot, 35 44 25 42)
	COMBO(ch_container, &ch_container, 35 44 59 42)
	COMBO(ch_since, &ch_since, 35 44 43)
	COMBO(ch_once, &ch_once, 35 25)
	COMBO(ch_process, &ch_process, 35 25 62 59)
	COMBO(ch_without_the, &ch_without_the, 35 42 74)
	COMBO(ch_without, &ch_without, 35 42)
	COMBO(ch_without_a, &ch_without_a, 35 42 57)
	COMBO(ch_which_the, &ch_which_the, 35 31 74)
	COMBO(ch_which, &ch_which, 35 31)
	COMBO(ch_which_a, &ch_which_a, 35 31 57)
	COMBO(ch_and_the, &ch_and_the, 30 37 74)
	COMBO(ch_and, &ch_and, 30 37)
	COMBO(ch_and_a, &ch_and_a, 30 37 57)
	COMBO(ch_end, &ch_end, 30 37 44)
	COMBO(ch_good, &ch_good, 30 47)
	COMBO(ch_had_the, &ch_had_the, 30 41 74)
	COMBO(ch_had, &ch_had, 30 41)
	COMBO(ch_had_a, &ch_had_a, 30 41 57)
	COMBO(ch_didnapos_t, &ch_didnapos_t, 30 36 69)
	COMBO(ch_did, &ch_did, 30 36)
	COMBO(ch_would, &ch_would, 30 29 31)
	COMBO(ch_done, &ch_done, 30 44)
	COMBO(ch_donapos_t, &ch_donapos_t, 30 25 69)
	COMBO(ch_do, &ch_do, 30 25)
	COMBO(ch_order, &ch_order, 30 25 59)
	COMBO(ch_youapos_d, &ch_youapos_d, 30 25 26 24)
	COMBO(ch_everyday, &ch_everyday, 30 59 32)
	COMBO(ch_ready, &ch_ready, 30 59 24)
	COMBO(ch_doesnapos_t, &ch_doesnapos_t, 30 43 69)
	COMBO(ch_does, &ch_does, 30 43)
	COMBO(ch_day, &ch_day, 30 24)
	COMBO(ch_she, &ch_she, 37 41 43)
	COMBO(ch_sometime, &ch_sometime, 37 36 60)
	COMBO(ch_sometimes, &ch_sometimes, 37 36 60 43)
	COMBO(ch_time, &ch_time, 37 36 42)
	COMBO(ch_left, &ch_left, 37 29 61)
	COMBO(ch_please, &ch_please, 37 29 62)
	COMBO(ch_select, &ch_select, 37 29 43)
	COMBO(ch_let, &ch_let, 37 29 42)
	COMBO(ch_well, &ch_well, 37 29 31)
	COMBO(ch_me, &ch_me, 37 60)
	COMBO(ch_need_the, &ch_need_the, 37 44 74)
	COMBO(ch_need, &ch_need, 37 44)
	COMBO(ch_need_a, &ch_need_a, 37 44 57)
	COMBO(ch_never, &ch_never, 37 44 59)
	COMBO(ch_need_to, &ch_need_to, 37 44 42)
	COMBO(ch_new, &ch_new, 37 44 31)
	COMBO(ch_people, &ch_people, 37 62)
	COMBO(ch_here, &ch_here, 37 59)
	COMBO(ch_return, &ch_return, 37 59 42)
	COMBO(ch_set, &ch_set, 37 43 42)
	COMBO(ch_use, &ch_use, 37 43 26)
	COMBO(ch_the, &ch_the, 37 42)
	COMBO(ch_even, &ch_even, 37 32)
	COMBO(ch_ever, &ch_ever, 37 32 59)
	COMBO(ch_we, &ch_we, 37 31)
	COMBO(ch_whether, &ch_whether, 37 31 59)
	COMBO(ch_find, &ch_find, 61 35 36)
	COMBO(ch_moving, &ch_moving, 61 47 60)
	COMBO(ch_if_the, &ch_if_the, 61 36 74)
	COMBO(ch_if, &ch_if, 61 36)
	COMBO(ch_if_a, &ch_if_a, 61 36 57)
	COMBO(ch_first, &ch_first, 61 36 59)
	COMBO(ch_move, &ch_move, 61 60)
	COMBO(ch_form, &ch_form, 61 60 25 59)
	COMBO(ch_from_the, &ch_from_the, 61 60 59 74)
	COMBO(ch_from, &ch_from, 61 60 59)
	COMBO(ch_from_a, &ch_from_a, 61 60 59 57)
	COMBO(ch_of_the, &ch_of_the, 61 25 74)
	COMBO(ch_of, &ch_of, 61 25)
	COMBO(ch_of_a, &ch_of_a, 61 25 57)
	COMBO(ch_printf, &ch_printf, 61 62 59)
	COMBO(ch_for_the, &ch_for_the, 61 59 74)
	COMBO(ch_for, &ch_for, 61 59)
	COMBO(ch_for_a, &ch_for_a, 61 59 57)
	COMBO(ch_function, &ch_function, 61 48)
	COMBO(ch_thing, &ch_thing, 47 41)
	COMBO(ch_anything, &ch_anything, 47 41 44)
	COMBO(ch_nothing, &ch_nothing, 47 41 44 25)
	COMBO(ch_might, &ch_might, 47 36 60)
	COMBO(ch_going, &ch_going, 47 36 25)
	COMBO(ch_something, &ch_something, 47 60 43)
	COMBO(ch_gone, &ch_gone, 47 44 25)
	COMBO(ch_going_to, &ch_going_to, 47 44 42)
	COMBO(ch_go, &ch_go, 47 25)
	COMBO(ch_got, &ch_got, 47 25 42)
	COMBO(ch_great, &ch_great, 47 59 42)
	COMBO(ch_everything, &ch_everything, 47 59 32)
	COMBO(ch_get, &ch_get, 47 42)
	COMBO(ch_give, &ch_give, 47 32)
	COMBO(ch_how, &ch_how, 41 74)
	COMBO(ch_he, &ch_he, 41 37)
	COMBO(ch_having, &ch_having, 41 47 32)
	COMBO(ch_this, &ch_this, 41 36)
	COMBO(ch_him, &ch_him, 41 36 60)
	COMBO(ch_while, &ch_while, 41 36 31)
	COMBO(ch_think, &ch_think, 41 50)
	COMBO(ch_thanks, &ch_thanks, 41 50 44 43)
	COMBO(ch_them, &ch_them, 41 60)
	COMBO(ch_home, &ch_home, 41 60 25)
	COMBO(ch_then, &ch_then, 41 44)
	COMBO(ch_those, &ch_those, 41 25)
	COMBO(ch_other, &ch_other, 41 25 42)
	COMBO(ch_though, &ch_though, 41 25 26)
	COMBO(ch_however, &ch_however, 41 25 32)
	COMBO(ch_whose, &ch_whose, 41 25 31)
	COMBO(ch_help, &ch_help, 41 62)
	COMBO(ch_these, &ch_these, 41 43)
	COMBO(ch_that_the, &ch_that_the, 41 42 74)
	COMBO(ch_thatapos_s, &ch_thatapos_s, 41 42 69)
	COMBO(ch_that, &ch_that, 41 42)
	COMBO(ch_that_a, &ch_that_a, 41 42 57)
	COMBO(ch_through, &ch_through, 41 42 26)
	COMBO(ch_havenapos_t, &ch_havenapos_t, 41 32 69)
	COMBO(ch_have, &ch_have, 41 32)
	COMBO(ch_where, &ch_where, 41 31)
	COMBO(ch_they, &ch_they, 41 24)
	COMBO(ch_i, &ch_i, 36 74)
	COMBO(ch_git, &ch_git, 36 47 42)
	COMBO(ch_like_the, &ch_like_the, 36 50 29 74)
	COMBO(ch_like, &ch_like, 36 50 29)
	COMBO(ch_like_a, &ch_like_a, 36 50 29 57)
	COMBO(ch_iapos_ll, &ch_iapos_ll, 36 29)
	COMBO(ch_list, &ch_list, 36 29 43)
	COMBO(ch_still, &ch_still, 36 29 43 42)
	COMBO(ch_little, &ch_little, 36 29 42)
	COMBO(ch_iapos_m, &ch_iapos_m, 36 60)
	COMBO(ch_important, &ch_important, 36 60 62)
	COMBO(ch_in_the, &ch_in_the, 36 44 74)
	COMBO(ch_in, &ch_in, 36 44)
	COMBO(ch_in_a, &ch_in_a, 36 44 57)
	COMBO(ch_into_the, &ch_into_the, 36 44 42 74)
	COMBO(ch_into, &ch_into, 36 44 42)
	COMBO(ch_into_a, &ch_into_a, 36 44 42 57)
	COMBO(ch_right, &ch_right, 36 59)
	COMBO(ch_their, &ch_their, 36 59 42)
	COMBO(ch_is_the, &ch_is_the, 36 43 74)
	COMBO(ch_isnapos_t, &ch_isnapos_t, 36 43 69)
	COMBO(ch_is, &ch_is, 36 43)
	COMBO(ch_is_a, &ch_is_a, 36 43 57)
	COMBO(ch_its, &ch_its, 36 43 42)
	COMBO(ch_itapos_s_the, &ch_itapos_s_the, 36 42 69 74)
	COMBO(ch_itapos_s, &ch_itapos_s, 36 42 69)
	COMBO(ch_itapos_s_a, &ch_itapos_s_a, 36 42 69 57)
	COMBO(ch_it, &ch_it, 36 42)
	COMBO(ch_iapos_ve, &ch_iapos_ve, 36 32)
	COMBO(ch_will_the, &ch_will_the, 36 31 74)
	COMBO(ch_wonapos_t, &ch_wonapos_t, 36 31 69)
	COMBO(ch_will, &ch_will, 36 31)
	COMBO(ch_will_a, &ch_will_a, 36 31 57)
	COMBO(ch_made_the, &ch_made_the, 49 60 74)
	COMBO(ch_made, &ch_made, 49 60)
	COMBO(ch_made_a, &ch_made_a, 49 60 57)
	COMBO(ch_just_the, &ch_just_the, 49 43 42 74)
	COMBO(ch_just, &ch_just, 49 43 42)
	COMBO(ch_just_a, &ch_just_a, 49 43 42 57)
	COMBO(ch_make_the, &ch_make_the, 50 60 74)
	COMBO(ch_make, &ch_make, 50 60)
	COMBO(ch_make_a, &ch_make_a, 50 60 57)
	COMBO(ch_know, &ch_know, 50 44)
	COMBO(ch_keep, &ch_keep, 50 62)
	COMBO(ch_because_the, &ch_because_the, 50 43 74)
	COMBO(ch_because, &ch_because, 50 43)
	COMBO(ch_because_a, &ch_because_a, 50 43 57)
	COMBO(ch_work, &ch_work, 50 31)
	COMBO(ch_look, &ch_look, 29 50)
	COMBO(ch_looks, &ch_looks, 29 50 43)
	COMBO(ch_only_the, &ch_only_the, 29 44 25 74)
	COMBO(ch_only, &ch_only, 29 44 25)
	COMBO(ch_only_a, &ch_only_a, 29 44 25 57)
	COMBO(ch_youapos_ll, &ch_youapos_ll, 29 25 26 24)
	COMBO(ch_should_the, &ch_should_the, 29 43 74)
	COMBO(ch_shouldnapos_t, &ch_shouldnapos_t, 29 43 69)
	COMBO(ch_should, &ch_should, 29 43)
	COMBO(ch_should_a, &ch_should_a, 29 43 57)
	COMBO(ch_last, &ch_last, 29 43 42)
	COMBO(ch_tell, &ch_tell, 29 42)
	COMBO(ch_leave, &ch_leave, 29 32)
	COMBO(ch_wouldnapos_t, &ch_wouldnapos_t, 29 31 69)
	COMBO(ch_many, &ch_many, 60 44)
	COMBO(ch_money, &ch_money, 60 44 25)
	COMBO(ch_most, &ch_most, 60 25)
	COMBO(ch_mostly, &ch_mostly, 60 25 24)
	COMBO(ch_more, &ch_more, 60 59)
	COMBO(ch_some, &ch_some, 60 43)
	COMBO(ch_system, &ch_system, 60 43 24)
	COMBO(ch_mustapos_ve, &ch_mustapos_ve, 60 26 69)
	COMBO(ch_must, &ch_must, 60 26)
	COMBO(ch_my, &ch_my, 60 24)
	COMBO(ch_no, &ch_no, 44 74)
	COMBO(ch_ainapos_t, &ch_ainapos_t, 44 69)
	COMBO(ch_on_the, &ch_on_the, 44 25 74)
	COMBO(ch_on, &ch_on, 44 25)
	COMBO(ch_on_a, &ch_on_a, 44 25 57)
	COMBO(ch_now, &ch_now, 44 25 31)
	COMBO(ch_near, &ch_near, 44 59)
	COMBO(ch_not_the, &ch_not_the, 44 42 74)
	COMBO(ch_not, &ch_not, 44 42)
	COMBO(ch_not_a, &ch_not_a, 44 42 57)
	COMBO(ch_onto_the, &ch_onto_the, 44 42 25 74)
	COMBO(ch_onto, &ch_onto, 44 42 25)
	COMBO(ch_onto_a, &ch_onto_a, 44 42 25 57)
	COMBO(ch_when_the, &ch_when_the, 44 31 74)
	COMBO(ch_when, &ch_when, 44 31)
	COMBO(ch_when_a, &ch_when_a, 44 31 57)
	COMBO(ch_next, &ch_next, 44 48)
	COMBO(ch_any, &ch_any, 44 24)
	COMBO(ch_open, &ch_open, 25 62)
	COMBO(ch_or_the, &ch_or_the, 25 59 74)
	COMBO(ch_or, &ch_or, 25 59)
	COMBO(ch_or_a, &ch_or_a, 25 59 57)
	COMBO(ch_tomorrow, &ch_tomorrow, 25 59 42)
	COMBO(ch_our, &ch_our, 25 59 26)
	COMBO(ch_your, &ch_your, 25 59 26 24)
	COMBO(ch_everyone, &ch_everyone, 25 59 32)
	COMBO(ch_world, &ch_world, 25 59 31)
	COMBO(ch_so_the, &ch_so_the, 25 43 74)
	COMBO(ch_so, &ch_so, 25 43)
	COMBO(ch_so_a, &ch_so_a, 25 43 57)
	COMBO(ch_to_the, &ch_to_the, 25 42 74)
	COMBO(ch_to, &ch_to, 25 42)
	COMBO(ch_to_a, &ch_to_a, 25 42 57)
	COMBO(ch_out, &ch_out, 25 42 26)
	COMBO(ch_youapos_ve, &ch_youapos_ve, 25 26 32 24)
	COMBO(ch_you, &ch_you, 25 26 24)
	COMBO(ch_over_the, &ch_over_the, 25 32 74)
	COMBO(ch_over, &ch_over, 25 32)
	COMBO(ch_over_a, &ch_over_a, 25 32 57)
	COMBO(ch_who, &ch_who, 25 31)
	COMBO(ch_print, &ch_print, 62 59)
	COMBO(ch_up, &ch_up, 62 26)
	COMBO(ch_request, &ch_request, 58 59)
	COMBO(ch_query, &ch_query, 58 59 24)
	COMBO(ch_sure, &ch_sure, 59 43)
	COMBO(ch_there, &ch_there, 59 42)
	COMBO(ch_every, &ch_every, 59 32)
	COMBO(ch_were_the, &ch_were_the, 59 31 74)
	COMBO(ch_werenapos_t, &ch_werenapos_t, 59 31 69)
	COMBO(ch_were, &ch_were, 59 31)
	COMBO(ch_were_a, &ch_were_a, 59 31 57)
	COMBO(ch_everywhere, &ch_everywhere, 59 31 32)
	COMBO(ch_really, &ch_really, 59 24)
	COMBO(ch_yesterday, &ch_yesterday, 43 42 24)
	COMBO(ch_us, &ch_us, 43 26)
	COMBO(ch_take_the, &ch_take_the, 42 50 74)
	COMBO(ch_take, &ch_take, 42 50)
	COMBO(ch_take_a, &ch_take_a, 42 50 57)
	COMBO(ch_took_the, &ch_took_the, 42 25 50 74)
	COMBO(ch_took, &ch_took, 42 25 50)
	COMBO(ch_took_a, &ch_took_a, 42 25 50 57)
	COMBO(ch_too, &ch_too, 42 26)
	COMBO(ch_what_the, &ch_what_the, 42 31 74)
	COMBO(ch_what, &ch_what, 42 31)
	COMBO(ch_what_a, &ch_what_a, 42 31 57)
	COMBO(ch_until_the, &ch_until_the, 26 44 42 74)
	COMBO(ch_until, &ch_until, 26 44 42)
	COMBO(ch_until_a, &ch_until_a, 26 44 42 57)
	COMBO(ch_way, &ch_way, 26 24)
	COMBO(ch_very, &ch_very, 32 24)
	COMBO(ch_why, &ch_why, 31 24)
};
