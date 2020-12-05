# ? Makefile

display: display.c
	clang -std=c11 -Wall -pedantic -I/usr/include/SDL2 -lSDL2 -c $@.c -o $@.o

hellodisplay: hellodisplay.c
	clang -std=c11 -Wall -pedantic display.o hellodisplay.c \
		-lSDL2 -o hellodisplay \
		&& ./hellodisplay
		