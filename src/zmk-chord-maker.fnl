(local KEYCODES
  {:b 23 :y 24 :o 25 :u 26 "'" 27     ";" 28 :l 29 :d 30 :w 31 :v 32 ;:z 33
   :c 35 :i 36 :e 37 :a 38 "," 39     "." 40 :h 41 :t 42 :s 43 :n 44 :q 45
   :g 47 :x 48 :j 49 :k 50 "-" 51     "q" 58 :r 59 :m 60 :f 61 :p 62
                          :TH4 52             :TH2 57
                       :TH3 69                 :TH1 74
  })

(local CHAR_NAMES
  ; TODO: add more as needed
  {" " "SPC"
   "'" "APOS"
   "." "PERIOD"
   "," "COMMA"
   "!" "BACKSPACE"
   ";" "SEMI"
   "-" "MINUS"
   "_" "LS(MINUS)"
   })

(lambda cap [str]
  "uppercase the first letter of a string"
  (let [first (str:sub 1 1)
              rest  (str:sub 2)]
    (.. (first:upper) rest)))

(lambda ?upper [char]
  "return whether a string is uppercase"
  (char:match "^[A-Z]$"))

(lambda ?letter [char]
  "return whether a string is a letter"
  (char:match "^[A-Za-z]$"))

(lambda take [n list]
  "return the first n values of a list"
  (icollect [i v (ipairs list)
               &until (> i n)]
    v))

(fn nilif [a b]
    "return a unless a is equal to b, in which case return nil"
    (if (= a b) nil a))

(lambda join [list sep]
  "join a list of strings together, placing `sep` between each"
  (accumulate [str nil _ s (ipairs list)]
    (if str (.. str sep s) s)))

(lambda split [str delim]
  "return an an iterator of substrings of `str` split on `delim`"
  (let [matches (-> (.. str delim)
                    (: :gmatch (.. "(.-)" delim)))]
    (icollect [i _ matches] i)))

(lambda chars [str]
  "convert a string to a list of characters"
  (icollect [char _ (: str :gmatch ".")] char))

(lambda str->keycodes [str]
  "split a string and convert each character to the corresponding keycode"
  (icollect [i char (ipairs (chars str))]
    (do
      (if (or (?letter char) (char:match "^[-',;.]$"))
        (. KEYCODES char)
        (assert
          (case char
            " " (. KEYCODES :TH1) ; space
            "_" (. KEYCODES :TH2) ; underscore
            "!" (. KEYCODES :TH3) ; backspace
            ">" (. KEYCODES :TH4)) ; tab
          (.. "INVALID CHARACTER: " char))))
    ))

(lambda str->keypresses [str]
  "split a string and convert each character to the corresponding keypress"
  (icollect [i char (ipairs (chars str))]
    (.. "&kp "
        (if (?letter char)
          (if (?upper char)
            (.. "LS(" char ")")
            (char:upper))
          (assert (. CHAR_NAMES char)
                  (.. "character name not defined for " char))))))

(lambda str->name [str]
  "transform a string into a macro-friendly name"
  (-> str
      (string.lower)
      (string.gsub "!" "bs_")
      (string.gsub "-" "dash_")
      (string.gsub "," "comma_")
      (string.gsub ";" "semi_")
      (string.gsub "'" "apos_")
      (string.gsub " " "_")
      (string.gsub "['.]" "__")))

(lambda str->combo [chord str]
  "transform a string into a COMBO declaration"
  (let [name (str->name str)
        keycodes (-> (str->keycodes chord)
                     (join " "))]
    (.. "COMBO(ch_" name ", &ch_" name ", " keycodes ")")))

(lambda str->macro [str]
  "transform a string into a MACRO declaration"
  (let [name (str->name str)
        keypresses (-> (str->keypresses str)
                       (join " "))]
    (.. "MACRO(ch_" name ", " keypresses " &kp SPC)")))

(lambda gen-chords [line]
  "generate combo and macro declarations for a chord line"
  (let [pieces (split line ":")
        keys (. pieces 1)
        str  (. pieces 2)]
    (..
      (str->combo keys str)
      "\n"
      (str->macro str))))

(lambda main [chords-file]
  "parse a chords file and write combo and macro declarations.
  the chords file should be one chord per line, with each line in the
  following format:
    <keys>:<expanded-text>"
  (let [f (assert (io.open chords-file "r") "chords-file not found")
        lines (split (f:read "*all") "\n")]
    (f:close)
    (each [_ line (ipairs lines)]
      (when (nilif line "")
        (io.write (.. (gen-chords line) "\n"))))))

(main "chords.txt")
; (main (assert (. arg 1) "chords-file required"))
