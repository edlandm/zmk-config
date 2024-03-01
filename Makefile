all: validate clean test.txt config.c

outputs := chords.output combos.output macros.output

.PHONY: validate
validate: chords.txt
	@test -z "$$(cut -d: -f1 chords.txt | sort | uniq -c | sort -n | sed '/^\s*1/d')" \
		|| { printf 'duplicate chord:\n %s\n' "$$(cut -d: -f1 chords.txt | sort | uniq -c | sort -n | sed '/^\s*1/d')"; exit 1; };
	@test -z "$$(cut -d: -f2 chords.txt | sort | uniq -c | sort -n | sed '/^\s*1/d')" \
		|| { printf 'duplicate chord output:\n %s\n' "$$(cut -d: -f2 chords.txt | sort | uniq -c | sort -n | sed '/^\s*1/d')"; exit 2; };

.PHONY: clean
clean:
	@rm -f $(outputs) test.txt config.c;

test.txt: chords.txt
	@cut -d: -f2 chords.txt | cut -d' ' -f1 | sort | uniq > test.txt;

chords.output: chords.txt
	@fennel zmk-chord-maker.fnl chords.txt > chords.output;

combos.output macros.output: chords.output
	@awk '/COMBO/ { print "\t" $$0 >> "combos.output" } /MACRO/ { print "\t" $$0 >> "macros.output" }' chords.output;

config.c: config.template.c chords.output combos.output macros.output
	@sed -r \
		-e '/^.*COMBOS_PLACEHOLDER.*$$/r combos.output' \
		-e '/^.*MACROS_PLACEHOLDER.*$$/r macros.output' \
		config.template.c \
		| sed '/_PLACEHOLDER/d' > config.c;
	@rm -f $(outputs);
	@echo 'config.c created.'
