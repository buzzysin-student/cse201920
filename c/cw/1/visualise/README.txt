# Visualise

## Summary

### Supported types
* Signed: int, char, long[*1], short
* Unsigned: int, char, long[*1], short
* Unavailable: float, double, long float, long double, long long

### Example cases
```bash
$ ./visualise char -48 # Valid
# information about the representation of (unsigned) (type) (value)
# will appear down here. This includes:
# * Binary representation
# * Octal representation
# * Hexadecimal representation
# * Character representation, where applicable
$ ./visualise unsigned int 255 # Valid
$ ./visualise foo long 27 # VALID! (see usage notes)
$ ./visualise bar 89 # INVALID
$ ./visualise unsigned short -254 # INVALID
```

## Notes

### Usage notes
1. The program does not check to see if the first string entered
when there are 4 entities in the argument vector is equal to
'unsigned' - it is entirely implied.

2. The program does not calculate the representation for floats 
or doubles.

3. Longs are too long for the program to represent correctly! 

### Developer notes
1. The call of test() takes place in the *summarise* function. 

2. All tests are limit case tests

3. [*1]My choice of using *long long*s causes then program to interpret *ULONG_MAX* to be
*-1*. Therefore, 5 of the 16 tests were compromised.

(c) - Taharka Okai, 2019