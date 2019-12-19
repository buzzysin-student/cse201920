#include <stdio.h>
#include <stdlib.h>

const char* fpth = "../text.txt";
const char* ftst = "../text_hex.txt";

char getHex(int n) {
  if (n >= 0 && n <= 9)
    return '0' + n;
  else if (n >= 10 && n <= 15)
    return 'A' + n - 10;
  else
    return '\0';
}

char getNibble(char n, char nibble) {
  0x41;
  // * 01000001
  // * 01000001 (after shift)
  // * 00001111 (mask)
  // * 00000001 <- 1
  // !
  // * 01000001
  // * 00000100
  // * 00001111
  // * 00000100 <- 4
  return 15 & (n >> (4 * nibble));
}

int main(int n, char* args[n]) {
  char* fscn = n == 2 ? args[1] : (char*)fpth;

  FILE* fin = fopen(fscn, "r");
  FILE* fout = fopen(ftst, "w");

  if (fin != NULL)
    printf("File is open %s\n", fscn);
  else {
    printf("File not found: %s\n", fscn);
    exit(1);
  }

  int outs = 1;

  while (!feof(fin)) {
    char in = fgetc(fin);

    fputc(getHex(getNibble(in, 1)), fout);
    fputc(getHex(getNibble(in, 0)), fout);
    fputc(' ', fout);

    if ((outs % 16) == 0) {
      fputc('\n', fout);
    }

    // * 00101101
    // * 0010 <- 2
    // * 1101 <- D

    outs++;
  }

  fclose(fout);
  fclose(fin);
}
