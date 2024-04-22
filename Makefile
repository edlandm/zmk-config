all: validate clean build
build: build/config.c build/test.txt

.PHONY: validate clean build image run

outputs := chords.output combos.output macros.output

validate: chords.txt
	@test -z "$$(cut -d: -f1 chords.txt | sort | uniq -c | sort -n | sed '/^\s*1/d')" \
		|| { printf 'duplicate chord:\n %s\n' "$$(cut -d: -f1 chords.txt | sort | uniq -c | sort -n | sed '/^\s*1/d')"; exit 1; };
	@test -z "$$(cut -d: -f2 chords.txt | sort | uniq -c | sort -n | sed '/^\s*1/d')" \
		|| { printf 'duplicate chord output:\n %s\n' "$$(cut -d: -f2 chords.txt | sort | uniq -c | sort -n | sed '/^\s*1/d')"; exit 2; };

clean:
	@rm -f $(outputs) build/*

build/test.txt: chords.txt
	@cut -d: -f2 chords.txt \
		| cut -d' ' -f1 \
		| sed '/^[^[:alpha:]]/d' \
		| sort \
		| uniq > build/test.txt;

chords.output: chords.txt
	@fennel src/zmk-chord-maker.fnl chords.txt > chords.output;

combos.output macros.output: chords.output
	@awk '/COMBO/ { print "\t" $$0 >> "combos.output" } /MACRO/ { print "\t" $$0 >> "macros.output" }' chords.output;

build/config.c: src/config.template.c $(outputs)
	@sed -r \
		-e '/^.*COMBOS_PLACEHOLDER.*$$/r combos.output' \
		-e '/^.*MACROS_PLACEHOLDER.*$$/r macros.output' \
		src/config.template.c \
		| sed '/_PLACEHOLDER/d' > build/config.c;
	@rm -f $(outputs);
	@echo 'build/config.c created.'

image: Dockerfile
	docker image build -t zmk-config .

run: image
	@mkdir -p $$PWD/build
	docker run --rm --mount type=bind,source=$$PWD/build/,target=/zmk/build zmk-config
