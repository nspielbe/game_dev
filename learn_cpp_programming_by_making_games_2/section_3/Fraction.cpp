#include <iostream>

class Fraction
{
public:
    // Constructors
    Fraction();
    Fraction(int numerator, int denominator);

    // Member function to display a fraction
    void display();

    // Member functions for arithmetic with fractions
    Fraction add(Fraction fraction);
    Fraction subtract(Fraction fraction);
    Fraction multiply(Fraction fraction);
    Fraction divide(Fraction fraction);

    // Getter functions for accessing private data members
    int getNumerator();
    int getDenominator();

    // Utility function for reducting a fraction to lowest common denominator
    void reduce();
    int getCommonDenominator(Fraction fraction);
    
private:
    int numerator;
    int denominator;
};

int Fraction::getDenominator(){
    return denominator;
}

int Fraction::getNumerator(){
    return numerator;
}

Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction::Fraction() : Fraction(0 ,1){}

void Fraction::display(){
    std::cout << "Numerator: " << numerator << " Denominator: " << denominator << std::endl;
}


Fraction Fraction::multiply(Fraction fraction){
    return {fraction.getNumerator() * numerator, fraction.getDenominator() * denominator};
}

Fraction Fraction::divide(Fraction fraction){
    return {fraction.getNumerator() * denominator, fraction.getDenominator() * numerator};
}


int main(){
    Fraction defaultFrac = Fraction();
    defaultFrac.display();
    
    Fraction myFrac = {1,2};
    myFrac.display();

    return 0;
}
