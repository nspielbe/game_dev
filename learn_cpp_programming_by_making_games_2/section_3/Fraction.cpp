#include <iostream>

namespace{

/// @brief Use Euclid's Algorithm for recursively computing the GCD
/// @param a 
/// @param b 
/// @return an int representing the GCD
int greatestCommonDenominator(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return greatestCommonDenominator(b, a % b);
    }
}

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


private:
    // Getter functions for accessing private data members
    int getNumerator();
    int getDenominator();

    // Utility function for reducting a fraction to lowest common denominator
    int getCommonDenominator(Fraction fraction);
    void reduce();

    int numerator;
    int denominator;
};

void Fraction::reduce(){
    int gcd = greatestCommonDenominator(numerator, denominator);
    if (gcd > 0){
        numerator = numerator / gcd;
        denominator = denominator / gcd; 
    }
}

int Fraction::getCommonDenominator(Fraction fraction){
    return fraction.getDenominator() * denominator;
}

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
    Fraction result = {fraction.getNumerator() * numerator, fraction.getDenominator() * denominator};
    result.reduce();
    return result;
}

Fraction Fraction::divide(Fraction fraction){
    Fraction result = {fraction.getNumerator() * denominator, fraction.getDenominator() * numerator};
    result.reduce();
    return result;
}

Fraction Fraction::add(Fraction fraction){
    // get the common denominator
    int commonDenom = getCommonDenominator(fraction);

    int newNumerator = (commonDenom/fraction.getDenominator()) * fraction.getNumerator()
                     + (commonDenom/denominator) * numerator;

    Fraction result = {newNumerator, commonDenom};
    result.reduce();
    return result;   
}

Fraction Fraction::subtract(Fraction fraction){
    // get the common denominator
    int commonDenom = getCommonDenominator(fraction);

    int newNumerator = (commonDenom/denominator) * numerator
                        -(commonDenom/fraction.getDenominator()) * fraction.getNumerator();

    Fraction result = {newNumerator, commonDenom};
    result.reduce();
    return result;  
}

} // end anon namespace

int main(){
    Fraction defaultFrac = Fraction();
    defaultFrac.display();
    
    Fraction myFrac{1,2};
    Fraction myFrac2{2,5};

    Fraction result = myFrac2.add(myFrac);
    Fraction result2 = myFrac2.subtract(myFrac);
    Fraction result3 = myFrac2.multiply(myFrac);
    Fraction result4 = myFrac2.divide(myFrac);

    result.display();
    result2.display();
    result3.display();
    result4.display();

    return 0;
}
