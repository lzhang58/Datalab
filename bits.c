/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Lianpeng Zhang  ID: lzhang58
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students: v
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitNand -  using only ~ and | 
 *   return the NAND of the two numbers -- NAND is the logical complement of AND
 *   Example: bitNand(6, 5) = 0xfffffffb  (only the 4 bit is 1 in both numbers)
 *   Legal ops: ~ |
 *   Max ops: 6
 *   Rating: 1
 */
int bitNand(int x, int y) {
    return ~x|~y;
}
/*
 * isEqualThree - Returns 1 if all three numbers are equal otherwise 0
 *
 * Examples: isEqualThree(1, 2, 3) = 0
 *           isEqualThree(4, 4, 4) = 1
 *
 * Legal Ops: ! ~ & ^ | + << >>
 * Max Ops: 10
 * Rating: 2
 */
int isEqualThree(int x, int y, int z) {
  return !((x^y)|(x^z));
}
/* 
 * swap30 -- switch the 0 and 3rd bits of every hex digit of the number
 *   Example: swap30(0) = 0
 *            swap30(8) = 1
              swap30(0x812) = 0x182
              swap30(0x12345678) = 0x82a4c6e1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 2
 */
int swap30(int x) {
    int thirdbit = 0x88;
    int firstbit = 0x11;
    int middlebit = 0x66;
    firstbit = firstbit<<8 | firstbit;
    firstbit = firstbit<<16 | firstbit;
    thirdbit = firstbit<<3;
    middlebit = ~(thirdbit+firstbit);
    return ((x<<3)&thirdbit)+((x>>3)&firstbit)+(x&middlebit);
}
/* 
 * logicalByteAdd - Add two bytes without using +.  Note that the sum may be bigger than 255
 *   Example: logicalByteAddBytes(0x20,0x30) = 0x50, logicalByteAddBytes(0xff,0xff) = 0x1fe
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 30
 *   Rating: 3
 */
int logicalByteAdd(int x, int y) {
    int var1_s = x^y;
    int var1_c = (x&y) <<1;
    int var2_s = var1_s^var1_c;
    int var2_c = (var1_s&var1_c)<<1;
    int var3_s = var2_s^var2_c;
    int var3_c = (var2_s&var2_c)<<1;
    int var4_s = var3_s^var3_c;
    int var4_c = (var3_s&var3_c)<<1;
    int var5_s = var4_s^var4_c;
    int var5_c = (var4_s&var4_c)<<1;
    int var6_s = var5_s^var5_c;
    int var6_c = (var5_s&var5_c)<<1;
    int var7_s = var6_s^var6_c;
    int var7_c = (var6_s&var6_c)<<1;
    int var8_s = var7_s^var7_c;
    int var8_c = (var7_s&var7_c)<<1;
    return var8_s|var8_c;
}
/* 
 * rotateNibbleLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateNibbleLeft(0x87654321,1) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateNibbleLeft(int x, int n) {
    int leftmove = n<<2;
    int bitmove = (~leftmove)+29;
    int rightmove = bitmove+4;
    int moveleft = x<<leftmove;
    int moveright = x>>rightmove;
    int bit = 0xf0<<24;
    bit =~(bit>>bitmove);
    return (bit&moveright)+moveleft;
}
/*
 * bitBurstSize - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: bitBurstSize(-1) = 32, bitBurstSize(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int bitBurstSize(int x) {
    int n=0;	
    int first16;
    int first24;
    int first28;
    int first30;
    int last2;
    int value;
    first16 =((!(~(x>>16)))<<4);
    n=n+first16;
    x=x<<first16;
    first24 =((!(~(x>>24)))<<3);
    n=n+first24;
    x=x<<first24;
    first28 =((!(~(x>>28)))<<2);
    n=n+first28;
    x=x<<first28;
    first30 =((!(~(x>>30)))<<1);
    n=n+first30;
    x=(x<<first30);
    last2=(x>>30)&0x3;
    value=(x>>31)&(last2+(~0));
    n=n+value;
    return n;
}
/* 
 * isNegatable - Check whether x is a number that is not its own negative (which is any number other than zero and Tmin)
 *   Examples: isNegatable(3) = 1, isNegatable(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2 
 */
int isNegatable(int x) {
    return !(x<<1);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    int t = x>>31;
    return t|(!!x);
}
/*
 * maxOfThree - Returns the maximum of three integers.
 * NOTE: x, y, z are all in the range [0, TMax].
 *
 * Examples: maxOfThree(1, 2, 3) = 3
 *           maxOfThree(4, 4, 4) = 4
 *
 * Legal Ops: ! ~ & ^ | + << >>
 * Max Ops: 25
 * Rating: 4
 */
int maxOfThree(int x, int y, int z) {
    int compare1;
    int compare2;
    int max;
    compare1 = x+(~y);
    compare1 = compare1>>31;
    max = (x&(~compare1))|(y&compare1);
    compare2 = max+(~z);
    compare2 = compare2>>31;
    max = (max&(~compare2))|(z&compare2);
    return max;
}
/* 
 * isInRange - return 1 if the first argument is in the range between
 * the second and third arguments (inclusive), 0 otherwise.
 * Note that if the second argument is larger than the third, you should return 0
 * Arguments take the range of unsigned characters (0 to 255)
 *   Example: isInRange(0x35,0x00,0x45) = 1.
 *            isInRange(0x3a,0x40,0x30) = 0.
 *            isInRange(0x05,0x00,0x05) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int isInRange(int x, int lbound, int ubound) {
       int comparelow = lbound+~x;
       int compareup = x+~ubound;
       return (!!(comparelow>>31))&(compareup>>31);
}
/*
 * ezThreeSixteenths - multiplies by 3/16 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*3/16),
 *   including overflow behavior.
 *   Examples: ezThreeSixteenths(77) = 28
 *             ezThreeSixteenths(-22) = -8
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeSixteenths(int x) {
      int multThree = x+x+x;
      int addNum = 15 & (multThree >> 31);
      int divSixteen = (multThree+addNum)>>4;  
      return divSixteen;
}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
   int neg = x >> 31;
   int sign = neg<<31;
   int a = (x^neg);
   int b = (a|sign)+!!sign;
   return b;
}
/* binarySize - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: binarySize(12) = 5
 *            binarySize(298) = 10
 *            binarySize(-5) = 4
 *            binarySize(0)  = 1
 *            binarySize(-1) = 1
 *            binarySize(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int binarySize(int x) {
    int n=0;
    int first16;
    int first24;
    int first28;
    int first30;
    int last2;
    int value;
    int sign=x>>31;
    x=(sign&x)|(~(sign|x));
    first16 =((!(~(x>>16)))<<4);
    n=n+first16;
    x=x<<first16;
    first24 =((!(~(x>>24)))<<3);
    n=n+first24;
    x=x<<first24;
    first28 =((!(~(x>>28)))<<2);
    n=n+first28;
    x=x<<first28;
    first30 =((!(~(x>>30)))<<1);
    n=n+first30;
    x=(x<<first30);
    last2=(x>>30)&0x3;
    value=(x>>31)&(last2+(~0));
    n=~(n+value)+34;
    return n;
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
	int sign = 0x7fffffff;    	
	return sign&uf;
}
/* 
 * float_exp - Return the exponent value for f.  If x is inifinity or NaN, return Tmax
 *   f is to be interpreted as the bit-level representations of
 *   single-precision floating point values.  You need to remove the appropriate value for the bias.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 8
 *   Rating: 2
 */
int float_exp(unsigned uf) {
	int exp = (uf>>23)&0x000000ff;
	int retVal = exp-127;
	if(!exp){
		retVal = 0xffffff82;
	}
	if(!(exp^0x000000ff)){
		retVal = 0x7fffffff;
	}
	return retVal; 
}
/* 
 * float_half_denorm - If the input number is denormalized, return
 *   bit-level equivalent of expression 0.5*f for floating point
 *   argument f.  Both the argument and result are passed as unsigned
 *   int's, but they are to be interpreted as the bit-level
 *   representation of single-precision floating point values.  When
 *   argument is not denormalized, return it as is 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while 
 *   Max ops: 15 
 *   Rating: 3
 */
unsigned float_half_denorm(unsigned uf) { 
    int sign = uf&0x80000000;
    if(uf&0x7f800000){}
    else{
    	uf = ((uf&0x7fffffff)>>1)+((uf&3)==3);
    }
    return sign|uf;
}
