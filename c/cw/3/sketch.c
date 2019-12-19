// Basic program skeleton for a Sketch File (.sk) Viewer
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "displayfull.h"
#include "sketch.h"
#include "/home/tk/.local/lib/logger.h"

enum MASKS {
  MASK_OPCODE = 0xC0,
  MASK_OPERAND = /* 0011 1111 */ 0x3F,
  MASK_SIGN = 0x20
};

// * Reset the state to its base form
state* resetState(state* s) {
  s->data = 0;
  s->end = false, s->tool = LINE;
  s->tx = 0, s->ty = 0;
  s->x = 0, s->y = 0;
  return s;
}

// Allocate memory for a drawing state and initialise it
state* newState() {
  state* s = malloc(sizeof(state));
  resetState(s);
  s->start = false;
  return s;
}

// Release all memory associated with the drawing state
void freeState(state* s) { free(s); }

// Extract an opcode from a byte (two most significant bits).
int getOpcode(byte b) { return (b & MASK_OPCODE) >> 6; }

// Extract an operand (-32..31) from the rightmost 6 bits of a byte.
int getOperand(byte b) {
  int _b = b & MASK_OPERAND;
  return _b + (_b >> 5 ? (-1 & ~MASK_OPERAND) : 0);
}

// ? Basic x-axis movement
void _obeyDX(display* d, state* s, int opernd) { s->tx += opernd; }

// ? Basic y-axis movement/conditional line draw
// ? and position setting
void _obeyDY(display* d, state* s, int opernd) {
  // * Increment the y-target
  s->ty += opernd;

  if (s->tool == LINE)
    // * Draw a line if LINE tool is active
    line(d, s->x, s->y, s->tx, s->ty);

  if (s->tool == BLOCK)
    // * Draw a block if BLOCK tool is active
    block(d, s->x, s->y, s->tx - s->x, s->ty - s->y);

  // * Set the new position after operation is finished
  s->x = s->tx;
  s->y = s->ty;
}

// ? Tool Setter
void _obeyTool(display* d, state* s, int opernd) {
  // * Store the old tool if it is needed
  int prior = s->tool;
  // * Set the tool the the current operand
  s->tool = opernd;
  // * If the current tool is COLOUR
  if (s->tool == COLOUR) colour(d, s->data);
  // * If the current tool is TARGETX
  if (s->tool == TARGETX) s->tx = s->data;
  // * If the current tool is TARGETY
  if (s->tool == TARGETY) s->ty = s->data;
  // * SHow frame ahead of time
  if (s->tool == SHOW) show(d);
  // * Pause frame
  if (s->tool == PAUSE) pause(d, s->data);
  // * Skip frame
  if (s->tool == NEXTFRAME) s->end = true;
  // * Reset the TOOL if an INTERMEDIATE+ command was executed
  if (s->tool > COLOUR) s->tool = prior;
  // * Clear the data after every tool command
  s->data = 0;
}

// ? Data Setter
void _obeyData(display* d, state* s, int opernd) {
  s->data =
      // * shift data to the right 6 bits
      (s->data << 6) |
      // * BITWISE OR the empty 6 bits
      (opernd & MASK_OPERAND);
}

// Execute the next byte of the command sequence.
void obey(display* d, state* s, byte op) {
  // * Function pointer to store operation
  void (*perform)(display*, state*, int);
  // * Separate the operand and opcode
  int opcode = getOpcode(op);
  int opernd = getOperand(op);

  // * Set the action based on the opcode
  if (opcode == DX) perform = _obeyDX;
  if (opcode == DY) perform = _obeyDY;
  if (opcode == TOOL) perform = _obeyTool;
  if (opcode == DATA) perform = _obeyData;

  perform(d, s, opernd);
}

// Draw a frame of the sketch file. For basic and intermediate sketch files
// this means drawing the full sketch whenever this function is called.
// For advanced sketch files this means drawing the current frame whenever
// this function is called.
bool processSketch(display* d, void* data, const char pressedKey) {
  bool willQuit = (pressedKey == 27);

  // * See if the program should end
  if (!data) return willQuit;

  // * Initialise the state and the file
  state* s = (state*)data;
  FILE* sketch = fopen(getName(d), "r");
  int frame = 0;

  fseek(sketch, s->start, SEEK_SET);
  frame = s->start;

  // * While the end of the file is not reached
  while (!feof(sketch) || s->end) {
    // * Get the operation
    int op = fgetc(sketch);
    // * Follow the operation
    obey(d, s, op);
    // * Increment the frame counter
    frame++;

    
    if (s->end) {
      s->start = frame;
      break;
    }
  }

  if (feof(sketch)) s->start = 0;

  fclose(sketch);

  // * Show changes and reset state
  show(d);
  resetState(s);

  // * Exit/Next file
  return willQuit;
}

// View a sketch file in a 200x200 pixel window given the filename
void view(char* filename) {
  display* d = newDisplay(filename, 200, 200);
  state* s = newState();
  run(d, s, processSketch);
  freeState(s);
  freeDisplay(d);
}

// Include a main function only if we are not testing (make sketch),
// otherwise use the main function of the test.c file (make test).
#ifndef TESTING
int main(int n, char* args[n]) {
  if (n != 2) {  // return usage hint if not exactly one argument
    printf("Use ./sketch file\n");
    exit(1);
  } else
    view(args[1]);  // otherwise view sketch file in argument
  return 0;
}
#endif
