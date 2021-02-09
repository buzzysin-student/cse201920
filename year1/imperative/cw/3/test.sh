compile -rmc test.c -i"I/usr/include/SDL2 sketch.c -DTESTING" ${@:2}
echo ${@:2}
