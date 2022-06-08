#include "fraction.h"
#include "sstream"

Fraction::Fraction(int Nom, int Den){
    this->Nom = Nom;
    this->Den = Den;
    simplify();
}

char *Fraction::show(){
    ostringstream stream;
    if(abs(Den) > eps && abs(Nom) > eps){
        if(Den == 1){
            stream << Nom;
        }
        else {
            stream << Nom << "/" << Den;
        }
    }
    else {
        if(abs(Nom) < eps){
            stream << Nom;
        }
        else {
            stream << "Inf";
        }
    }
    // вот тут как-то не очень. stream -> string -> const char* -> char* ??
    return strdup(stream.str().data());
}

Fraction Fraction::operator +(Fraction val){
    Fraction res = *this;
    res.add(val);
    return res;
}

Fraction Fraction::operator -(Fraction val){
    Fraction res = *this;
    res.dif(val);
    return res;
}

Fraction Fraction::operator *(Fraction val){
    Fraction res = *this;
    res.mul(val);
    return res;
}

Fraction Fraction::operator /(Fraction val){
    Fraction res = *this;
    res.div(val);
    return res;
}

int Fraction::getIntegerPart(){
    return (abs(Den) > eps) ? Nom / Den: 0;
}

void Fraction::simplify(){
    if (Den != 0 && Nom != 0){
        long v = gcd(abs(Nom), abs(Den));
        if(v){
            Nom /= v;
            Den /= v;
        }
    } else if(Nom == 0){
        Den = 0;
    }
}

long Fraction::gcd(long a, long b){
    while(a != b){
        if(a > b) swap(a, b);
        b = b - a;
    }
    return a;
}

void Fraction::add(Fraction val){
    int den = this->Den * val.Den;
    this->Nom = this->Nom * val.Den + this->Den * val.Nom;
    this->Den = den;
    simplify();
}

void Fraction::dif(Fraction val){
    int den = this->Den * val.Den;
    this->Nom = this->Nom * val.Den - this->Den * val.Nom;
    this->Den = den;
    simplify();
}

void Fraction::mul(Fraction val){
    this->Nom *= val.Nom;
    this->Den *= val.Den;
    simplify();
}

void Fraction::div(Fraction val){
    this->Nom *= val.Den;
    this->Den *= val.Nom;
    simplify();
}
