# ? Makefile

%: %.c
	clang -std=c11 -Wall -pedantic -g $@.c -o $@ \
			-fsanitize=address -fsanitize=undefined