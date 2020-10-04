#include "display.h"

#define SCALE 16

typedef struct location {
  int x, y;
} location;

// Our function to be called repeatedly by the display module
bool runtime(display* d, void* data, const char pressedKey) {
  // cast incoming data to be location*
  location* l = (location*)data;

  // cast data to what it was originally created as
  // int *colourState = (int *)data;

  // set a custom colour
  colour(d, 0xFF);

  // draw a box with arguments (x,y,width,height)
  block(d, 80, 80, 160, 80);
  // show drawn things in the window
  show(d);

  // change colourState over time
  // *colourState += 0xFF;

  // change position state based on pressedKey input
  switch (pressedKey) {
    case 79:
      l->x += SCALE;
      break;  // go right
    case 80:
      l->x -= SCALE;
      break;  // go left
    case 81:
      l->y += SCALE;
      break;  // go down
    case 82:
      l->y -= SCALE;  // go up
      break;
  }

  // limit position state to size of the display window (wrap-around)
  *l = (location){(l->x + getWidth(d)) % getWidth(d),
                  (l->y + getHeight(d)) % getHeight(d)};

  colour(d, 0xFFFF);                   // set current colour to blue
  block(d, l->x, l->y, SCALE, SCALE);  // draw a box at new position (l->x,l->y)
  show(d);                             // show drawn stuff on the screen

  // indicate to stop once ESC is pressed
  return (pressedKey == 27);
}

int main() {
  // create a window with 320x240 pixels
  display* d = newDisplay("Hello Display", 320, 240);

  // some dynamic data to pass in
  // int colourState = 0x0000FFFF;

  location* l = malloc(sizeof(location));
  *l = (location){0, 0};

  // hand control to the display module + ask to call back our function
  run(d, l, runtime);
  // free all display memory, close the display window
  freeDisplay(d);
}