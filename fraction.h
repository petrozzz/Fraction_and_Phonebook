#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction
{
private:
    int Nom;
    int Den;

    const float eps = 1.0e-6f;

public:
    Fraction(int Nom = 0, int Den = 0);
    char *show();
    Fraction operator + (Fraction val);
    Fraction operator - (Fraction val);
    Fraction operator * (Fraction val);
    Fraction operator / (Fraction val);
    int getIntegerPart();

protected:
    void simplify();
    long gcd(long a, long b);
    void add(Fraction val);
    void dif(Fraction val);
    void mul(Fraction val);
    void div(Fraction val);
};

#endif // FRACTION_H
