int main(void)
{
  // * Uses 8 bits to represent a number in the interval [0,255]
  // * (as opposed to `signed char` [-128,127])
  unsigned char bin_1;

  // ? = 2^1 + 2^2 + 2^3 = 2 + 4 + 8 = 14
  // ? The amount of information stored here is 1B (1 byte, 8 bits)
  bin_1 = 0b00001110;

  /*
   ? 4 bits     -> 1 Nibble (1 N)
   ? 8 bits     -> 1 Byte   (1 B)
   ? 8192 bits  -> 1024 Bytes -> 1 Kilobyte (1 KB)
   ? etc, etc.
   */

  /*
   * From bits to nibbles, split the integer bits into
   * groups of 4
   * e.g. 0b0000 0b1110 -> 0 14
   ? Nibble representation is ALWAYS UNSIGNED during conversion
   * 
   ? bin_1 in hexadecimal representation -> turn nibbles into base 16
   ? 0 14 -> 0x0 0xE -> 0x0E
   */

  unsigned char hex_1;
  hex_1 = 0x0E; // * 14

  // ? Unsigned short = 16 bits = [0, (2^16)-1]
  unsigned short word = 0x010E; // * 270 or 0000 0001 0000 1110

  // ? This is equivalent to x mod 255 (modular arithmetic)
  unsigned char overflow = 0xFF + 1; // ! = 0x00 (wraps around to 0)
  unsigned char undrflow = 0x00 - 1; // ! = 0xFF (wraps around to 255)

  /*
   * To print a hex number: %x
   * To print a hex number with a certain number of nibbles: %2x (2 nibbles)
   * To print a large hex number: %lx (long hex)
   * To print a hex with trailing zeros: %02x (2 nibbles, zeros and spaces)
   */

  return 0;
}