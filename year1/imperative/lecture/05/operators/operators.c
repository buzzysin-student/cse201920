int odd(int n)
{
  if ((n & 0x1) == 0x1) return 1;
  else return 0;
}

int main(void)
{
  /*
   * Bitwise operators:
   * &  -> AND
   * |  -> OR
   * ^  -> XOR
   * >> -> LEFT SHIFT
   * << -> RIGHT SHIFT
   * ~  -> NOT
   */

  // * 1001 1110
  unsigned char a = 0x9E;
  // * 1111 0000
  unsigned char b = 0xF0;
  // * 1001 0000
  unsigned char c = (a & b);

  // ? The above is an example of BIT MASKING
  // ? e.g. Odd function masks the number with
  // ? the least significant bit
  odd(5); // * Returns 1

  // * 0111 0111
  unsigned char a = 0x77;
  // * 0011 1011
  // ? Similar to dividing by 2 (and discarding the remainder)
  unsigned char b = a >> 1;

  unsigned char c = 0x77;
  // * 1110 1110
  unsigned char d = c << 1;

  // ! Beware of type-casting - bit shifts should ONLY
  // ! be used with UNSIGNED integers - use casting if 
  // ! absolutely necessary

  return 0;
}