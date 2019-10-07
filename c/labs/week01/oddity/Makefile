# Find the OS platform using the uname command.
Linux := $(findstring Linux, $(shell uname -s))
MacOS := $(findstring Darwin, $(shell uname -s))
Windows := $(findstring NT, $(shell uname -s))

# For native Windows only (not supported in our unit), add the .exe extension
ifdef Windows

oddity: oddity.c
		clang -std=c11 -Wall -pedantic -g oddity.c -o oddity.exe

# For Linux/MacOS/LinuxSubSystemForWindows10, include the advanced debugging options
else

oddity: oddity.c
		clang -std=c11 -Wall -pedantic -g oddity.c -o oddity \
		    -fsanitize=undefined -fsanitize=address

endif
