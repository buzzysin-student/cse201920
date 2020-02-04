#include <stdio.h>
#include <stdlib.h>

const char* fpth = "../text.txt";
const char* ftst = "../text_caps.txt";

char getCaps(char n) {
  if (n >= 'a' && n <= 'z')
    return n - ('a' - 'A');
  else
    return n;
}

int main(int n, char* args[n]) {
  char* fscn = n == 2 ? args[1] : (char*)fpth;

  FILE* fin = fopen(fscn, "r");
  FILE* fout = fopen(ftst, "w");

  if (fin != NULL)
    printf("File is open %s\n", fpth);
  else {
    printf("File not found: %s\n", fpth);
    exit(1);
  }

  while (!feof(fin)) {
    char in = fgetc(fin);
    fputc(getCaps(in), fout);
  }

  fclose(fout);
  fclose(fin);
}
