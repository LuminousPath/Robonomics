#include "Real.h"

int LCD(int i1, int i2)
{
    int temp, smaller, larger, remainder;
    if(i1 - i2 > 0)
    {
          smaller = i2;
          larger = i1;
    } else {
           smaller = i1;
           larger = i2;
    }
    
    if(larger % smaller == 0){
              temp = larger;
    } else {
           remainder = larger % smaller;
           while(remainder != 0)
           {
                           larger = smaller;
                           smaller = remainder;
                           remainder = larger % smaller;
           }
           temp = (i1 * i2) / smaller;
    }
    return temp;
}

Real::operator double()
{
       double temp;
       temp = (double)numerator/(double)denominator;
       return temp;
}

Real::operator int()
{
    int temp;
    temp = numerator/denominator;
    return temp;
}

Real Real::operator= (Real param)
{
     Real temp;
     temp.numerator = param.numerator;
     temp.denominator = param.denominator;
     return temp;
}

Real Real::operator= (int param)
{
     Real temp;
     temp.numerator = param;
     temp.denominator = 1;
     return temp;
}

Real Real::operator+ (Real param)
{
     Real temp;
     int reduced1, reduced2;
     int lcd = LCD(denominator, param.denominator);
     reduced1 = (lcd * numerator)/denominator;
     reduced2 = (lcd * param.numerator)/param.denominator;
     temp.denominator = lcd;
     temp.numerator = reduced1 + reduced2;     
     
     return temp;
}

Real Real::operator- (Real param)
{
     Real temp;
     int reduced1, reduced2;
     int lcd = LCD(denominator, param.denominator);
     reduced1 = (lcd * numerator)/denominator;
     reduced2 = (lcd * param.numerator)/param.denominator;
     temp.denominator = lcd;
     temp.numerator = reduced1 - reduced2;
     return temp;
}

Real Real::operator* (Real param)
{
     Real temp;
     temp.numerator = numerator * param.numerator;
     temp.denominator = denominator * param.denominator;
     return temp;
}

Real Real::operator/ (Real param)
{
     Real temp;
     temp.numerator = numerator * param.denominator;
     temp.denominator = denominator * param.numerator;
     return temp;
}
