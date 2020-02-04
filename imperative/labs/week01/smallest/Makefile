# Find the OS platform using the uname command.
Linux := $(findstring Linux, $(shell uname -s))
MacOS := $(findstring Darwin, $(shell uname -s))
Windows := $(findstring NT, $(shell uname -s))

# For native Windows only (not supported in our unit), add the .exe extension
ifdef Windows

smallest: smallest.c
		clang -std=c11 -Wall -pedantic -g smallest.c -o smallest.exe


smallest2: smallest2.c
		clang -std=c11 -Wall -pedantic -g smallest2.c -o smallest2.exe

# For Linux/MacOS/LinuxSubSystemForWindows10, include the advanced debugging options
else

smallest: smallest.c
		clang -std=c11 -Wall -pedantic -g smallest.c -o smallest \
		    -fsanitize=undefined -fsanitize=address

smallest2: smallest2.c
		clang -std=c11 -Wall -pedantic -g smallest2.c -o smallest2 \
		    -fsanitize=undefined -fsanitize=address

endif
