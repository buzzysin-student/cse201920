int main(void)
{
  // * Holds 0111 1111
  signed char signedByte = 127;

  /*
   * To represent -127, used the **RESERVED** 
   * significant bit to represent the sign of
   * the integer
   
   ! Applying Two's Complement to `signedByte`
   ? 1. Flip all the values (0 -> 1 and 1 -> 0) => 1000 0000
   ? 2. Add one to the result                   => 1000 0001
   */

  // * Holds 1000 0001
  signed char negSigned = -127;

  /* 
   ! Two's Complement (in this signed 8 bit case) does not
   ! apply for -128:

   ? -128     = 1000 0000
   ? -(-128)  = 0111 1111 + 1 = 1000 0000 = -128 (false!)
   */
}