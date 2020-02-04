#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERROR(text)     \
  {                     \
    CURRENT = __LINE__; \
    error(text);        \
  }

char INPUT_FILE[0xFFFF];
int CURRENT = 0;

typedef struct PGMPencil {
  // * Position/Target
  int x, y, tx, ty;
  // * Current tool
  unsigned char tool;
  // * Current data
  unsigned int data;
} PGMPencil;

enum PGMPencilCase { NONE, LINE, COLOUR };

// * What do you usually Sketch with? A Pencil, Of Course!
PGMPencil* newPencil() {
  PGMPencil* pencil = malloc(sizeof(PGMPencil));
  pencil->x = 0, pencil->y = 0;
  pencil->tx = 0, pencil->ty = 0;
  pencil->data = 0;
  pencil->tool = 0;
  return pencil;
}

void freePencil(PGMPencil* pencil) { free(pencil); }

typedef struct PGMDimensions {
  // * The size of the pgm in pixels
  int width, height;
} PGMDimensions;
typedef struct PGM {
  // * The source characters from which a PGM
  // * is read
  char* source;
  // * The type of PGM (P2 or P5)
  char* type;
  // * The width/height of the pgm
  PGMDimensions* d;
  // * The PGM can either can have gray
  // * values between 1-65535. 1-255
  // * means that readSize = 1, otherwise
  // * readSize = 2;
  int readSize;
} PGM;

// * Close the file and free the struct
void fnFreePGM(PGM* pgm) {
  free(pgm->source);
  free(pgm->type);
  free(pgm->d);
  free(pgm);
}

// ! LOGGING
void error(char* text) {
  fprintf(stderr, "Exception on line %d: %s", CURRENT, text);
  exit(0);
}

// * Fetch a file, fail if not found
char* fnFetchBuffer(char* filename) {
  // * Open the file
  FILE* file = fopen(filename, "rb");
  if (file == NULL) ERROR("Cannot find requested file\n");

  // * Determine the size of the file
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  char* buffer = malloc(sizeof(char) * size);
  if (buffer == NULL) ERROR("Error reading requested file")
  rewind(file);

  // * Write file into buffer
  fread(buffer, size, sizeof(char), file);

  // * Dispose of the file
  fclose(file);

  // * Return the file buffer
  return buffer;
}

// * Read a PGM, fail if invalid
PGM* fnGetPGM(char* buffer) {
  PGM* pgm = malloc(sizeof(PGM));
  pgm->d = malloc(sizeof(PGMDimensions));
  pgm->type = malloc(sizeof(char) * 3);
  pgm->source = buffer;
  pgm->readSize = 1;
  char realBuffer[0xFFFF];

  int maxValue;

  sscanf(pgm->source, "%s%d%d%d%s", pgm->type, &pgm->d->width, &pgm->d->height,
         &maxValue, realBuffer);

  strcpy(pgm->source, realBuffer);

  if (maxValue > 0xFF) ERROR("Cannot read this file yet");
  pgm->readSize = 1;
  return pgm;
}

long pwr(int n, int p) {
  if (n == 0) return 1;
  if (n < 0) return p * pwr(n - 1, p);
}

void skTool(char* tool, PGMPencil* pencil, char* output, char curr) {
  if (strcmp(tool, "data") == 0) {
    int val = (int)curr;
    int pwr = 0;
    while (val > 64) val /= 64, pwr++;
    val = (int)curr;
    while (pwr > -1) {
      int operand = (val >> (6 * pwr)) & 0x3f;
      strcat(output, "\3");
      strcat(output, (char*)&operand);
      pwr--;
    }
  }
  if (strcmp(tool, "line") == 0) {
    strcat(output, "\2\1");
  }
  if (strcmp(tool, "colour") == 0) {
    strcat(output, "\2\3");
  }
  if (strcmp(tool, "dx") == 0) {
    strcat(output, "\0");
    strcat(output, (char*)&pencil->tx);
  }
  if (strcmp(tool, "dy") == 0) {
    strcat(output, "\1");
    strcat(output, (char*)&pencil->ty);
    pencil->x = pencil->tx;
    pencil->y = pencil->ty;
  }
}

// * Create a *.sk file to write into
void fnWritePGM(PGM* pgm) {
  printf("Type: %s, Width: %d, Height: %d\n", pgm->type, pgm->d->width,
         pgm->d->height);

  char* buffer = pgm->source;
  PGMPencil* pencil = newPencil();
  char curr;
  char prev;

  char outfile[0xFFFF];
  strncpy(outfile, INPUT_FILE, 2);
  strcat(outfile, ".sk");
  FILE* out = fopen(outfile, "w");

  char command[0xFFFF];
  int cnt = 0;

  for (int i = 0; i < strlen(buffer); i++) {
    // * Read a new section
    curr = buffer[i];

    // * Set the positions
    pencil->tx = i % pgm->d->width;
    pencil->ty = (int)(i / pgm->d->height);
    if (pencil->ty == 0) pencil->x = 0, pencil->y = 0;

    printf("(%d, %d), %x\n ", pencil->tx, pencil->ty, curr);

    if (curr != prev) {
      printf("Doing stuff\n");
      skTool("data", pencil, command, curr);
      printf("cmd: Op:%02x\n",
             (0xFF) & (command[2 * cnt] << 6 | command[2 * cnt + 1]));
      cnt++;
      skTool("colour", pencil, command, curr);
      printf("cmd: Op:%02x\n",
             (0x3F) & (command[2 * cnt] << 6 | command[2 * cnt + 1]));
      cnt++;
    }

    skTool("line", pencil, command, curr);
    printf("cmd: Op:%02x\n",
           (0x3F) & (command[2 * cnt] << 6 | command[2 * cnt + 1]));
    cnt++;
    skTool("dx", pencil, command, curr);
    printf("cmd: Op:%02x\n",
           (0x3F) & (command[2 * cnt] << 6 | command[2 * cnt + 1]));
    cnt++;
    skTool("dy", pencil, command, curr);
    printf("cmd: Op:%02x\n",
           (0x3F) & (command[2 * cnt] << 6 | command[2 * cnt + 1]));
    cnt++;

    printf("\n");

    prev = curr;

    if (i >= 50) break;
  }

  printf("Total bytes read: %ld\n", strlen(buffer));

  fputs(command, out);
  fclose(out);
  free(pencil);
}

// * Convert a .PGM to .SK
void fnPGMtoSK(char* filename) {
  char* buffer = fnFetchBuffer(filename);
  PGM* pgm = fnGetPGM(buffer);
  fnWritePGM(pgm);
  fnFreePGM(pgm);
}

void usage() {
  printf(
      "\n\
=========\n\
Converter\n\
=========\n\
\n\
Converts a PGM to an SK file for\n\
representation by SDL2 library.\n\
\n\
Usage:\n\
\n\
$ ./converter myfile.pgm\n");
}

int main(int n, char* args[n]) {
  if (n != 2)
    usage();
  else {
    strcpy(INPUT_FILE, args[1]);
    printf("Beginning conversion... %s\n", args[1]);
    fnPGMtoSK(args[1]);
  }
}
