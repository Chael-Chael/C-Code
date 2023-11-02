#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT   20

typedef struct {
    int integer;        // positive integer
    int numerator;      // positive numerator
    int denominator;    // positive denominator
    int sign;           // stands for the sign for whole Fraction
                        // 1 for positive and -1 for negative
} Fraction;

//
// Generate a random Fraction
Fraction generateFraction( void );
//
// Simplify the Fraction, return the resulted Fraction
// Example1: input +(2+10/4), return +(4+1/2)
// Example1: input +(2+10/2), return +(7)
Fraction simplifyFraction( Fraction frac );
//
// Display the Fraction in the format of "+(i+n/d)" or "-(i+n/d)"
void displayFraction( Fraction frac );
//
// Return the greatest common divisor of integer x and y,
// which is called by simplifyFraction()
int gcd(int x, int y);
//
// Sum two Fraction numbers, return the resulted Fraction
Fraction getSumOfTwoFractions(  Fraction frac1,  Fraction frac2 );
//
// Sum two Fraction numbers, return the resulted Fraction
Fraction getDiffOfTwoFractions(  Fraction frac1,  Fraction frac2 );

int main()
{
    int SEED;
    scanf("%d",&SEED);
    srand(SEED);

    Fraction f1 = generateFraction();
    Fraction f2 = generateFraction();

    displayFraction( f1 );
    printf("+");
    displayFraction( f2 );
    printf("=");
    displayFraction( simplifyFraction( f1 ) );
    printf("+");
    displayFraction( simplifyFraction( f2 ) );
    printf("=");
    displayFraction( getSumOfTwoFractions( f1, f2 ) );
    printf("\n");

    displayFraction( f1 );
    printf("-");
    displayFraction( f2 );
    printf("=");
    displayFraction( simplifyFraction( f1 ) );
    printf("-");
    displayFraction( simplifyFraction( f2 ) );
    printf("=");
    displayFraction( getDiffOfTwoFractions( f1, f2 ) );
    printf("\n");
    return 0;
}

Fraction generateFraction( void )
{
    Fraction f;
    f.sign = rand() % 2;
    f.sign = ( f.sign == 0 ) ? -1 : 1;
    f.integer = 1 + rand() % MAX_INT;
    f.numerator = 1 + rand() % MAX_INT;
    f.denominator = 1 + rand() % MAX_INT;

    return f;
}

void displayFraction( Fraction f )
{
    if ( f.sign == 1 )
    {
        printf("%s", "(+(" );
    }
    else if ( f.sign == -1 )
    {
        printf("%s", "(-(" );
    }
    else
    {
        printf("Error! undefined sign\n");
        exit ( -2 );
    }
    if ( f.numerator == 0)
    {
        printf("%d", f.integer );
    }
    else if ( f.integer == 0)
    {
        printf("%d/%d", f.numerator, f.denominator);
    }
    else
    {
        printf("%d+%d/%d", f.integer, f.numerator, f.denominator);
    }
    printf("%s", "))" );
    //return;
}

// **********************************************
// << Your source code starts here >>
//

Fraction simplifyFraction( Fraction f )
{
   f.numerator = f.numerator + f.integer * f.denominator;
   f.integer = 0;
   
   int gcd1 = gcd(f.numerator, f.denominator);
   f.numerator = f.numerator / gcd1;
   f.denominator = f.denominator / gcd1;

   f.integer = f.numerator / f.denominator;
   f.numerator = f.numerator % f.denominator;

   return f;
}


int gcd(int x, int y)
{
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}


Fraction getSumOfTwoFractions( Fraction f1, Fraction f2 )
{
    Fraction result;
    result.integer = 0;
    
    f1.numerator = f1.numerator + f1.integer * f1.denominator;
    f1.integer = 0;

    f2.numerator = f2.numerator + f2.integer * f2.denominator;
    f2.integer = 0;
    //带分数转换成假分数

    int lcm = f1.denominator * f2.denominator / gcd(f1.denominator, f2.denominator);

    f1.numerator = f1.numerator * lcm / f1.denominator;
    f2.numerator = f2.numerator * lcm / f2.denominator;
    //通分

    result.numerator = (f1.sign*f1.numerator + f2.sign*f2.numerator);
    result.denominator = lcm;

    if (result.numerator < 0) {
        result.sign = -1;
        result.numerator = -result.numerator;
    } 
    else {
        result.sign = 1;
    }
    int gcd1 = gcd(result.numerator, result.denominator);
    result.numerator = result.numerator / gcd1;
    result.denominator = result.denominator / gcd1;
    result.integer = result.numerator / result.denominator;
    result.numerator = result.numerator % result.denominator;

    return result;
}


Fraction getDiffOfTwoFractions( Fraction f1, Fraction f2 )
{
    Fraction result;
    result.integer = 0;

    f1.numerator = f1.numerator + f1.integer * f1.denominator;
    f1.integer = 0;

    f2.numerator = f2.numerator + f2.integer * f2.denominator;
    f2.integer = 0;

    int lcm = f1.denominator * f2.denominator / gcd(f1.denominator, f2.denominator);

    f1.numerator = f1.numerator * lcm / f1.denominator;
    f2.numerator = f2.numerator * lcm / f2.denominator;

    result.numerator = (f1.sign*f1.numerator - f2.sign*f2.numerator);
    result.denominator = lcm;

    if (result.numerator < 0) {
        result.sign = -1;
        result.numerator = -result.numerator;
    } 
    else {
        result.sign = 1;
    }

    int gcd1 = gcd(result.numerator, result.denominator);
    result.numerator = result.numerator / gcd1;
    result.denominator = result.denominator / gcd1;
    result.integer = result.numerator / result.denominator;
    result.numerator = result.numerator % result.denominator;

    return result;
}

//
// << Your source code stops here >>
// **********************************************