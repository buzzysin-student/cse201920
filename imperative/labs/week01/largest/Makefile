# Find the OS platform using the uname command.
Linux := $(findstring Linux, $(shell uname -s))
MacOS := $(findstring Darwin, $(shell uname -s))
Windows := $(findstring NT, $(shell uname -s))

# For native Windows only (not supported in our unit), add the .exe extension
ifdef Windows

largest: largest.c
		clang -std=c11 -Wall -pedantic -g largest.c -o largest.exe


largest2: largest2.c
		clang -std=c11 -Wall -pedantic -g largest2.c -o largest2.exe

# For Linux/MacOS/LinuxSubSystemForWindows10, include the advanced debugging options
else

largest: largest.c
		clang -std=c11 -Wall -pedantic -g largest.c -o largest \
		    -fsanitize=undefined -fsanitize=address

largest2: largest2.c
		clang -std=c11 -Wall -pedantic -g largest2.c -o largest2 \
		    -fsanitize=undefined -fsanitize=address

endif
