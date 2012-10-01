class Real
{
      private:
              int numerator;
              int denominator;
      public:
             Real operator = (Real);
             Real operator = (int);
             Real operator + (Real);
             Real operator - (Real);
             Real operator * (Real);
             Real operator / (Real);
             operator double();
             operator int();
};
