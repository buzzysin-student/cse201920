
// Constants created for utility. 
// Represents the minimum boundary for a grade
enum GradeBounds { BOUND_G1 = 70, BOUND_G21 = 60, BOUND_G22 = 50, BOUND_G3 = 40, BOUND_FAIL = 30, BOUND_MIN = 0, BOUND_MAX = 100 };

// Constants created for utility.
// Represents the minimum length and character value for 
// elements in a given string of text
enum TextBounds { STR_MIN = 0, STR_MAX = 3, CHAR_MIN = '0', CHAR_MAX = '9' };

// Function created for utility. Returns the value of i ^ n
double pwr(double i, int n)
{ 
  return n ? i * pwr(i, n - 1) : 1; 
}

// Function created for utility. Returns whether a string
// is the correct length for the expected input (digit)
// count and the leading digit type.
int checkLengthBounds(int n, const char mark[])
{ 
  return 
    ! (n < STR_MIN) && 
    ! (n > STR_MAX) && 
    ! (mark[0] == CHAR_MIN && n > 1); 
}

// Function created for utility. Returns whether a character
// is within the defined range.
int checkCharBounds(char ascii)
{ 
  return 
    ascii >= CHAR_MIN && 
    ascii <= CHAR_MAX; 
}

// Function created for utility. Returns whether a calculated
// mark is within the defined range.
int checkIntBounds(int result)
{ 
  return 
    result <= BOUND_MAX && 
    result >= BOUND_MIN; 
}
