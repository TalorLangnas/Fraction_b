#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

namespace ariel{

class Fraction
{
    int nom;
    int den;  

    public:
// Constructors:

// default:
    Fraction();
// reciving to doubles:
    Fraction(double,double);
// copy:
    Fraction(const Fraction&);
// Move constructor (for tidy):
    Fraction(Fraction&&) noexcept;     
// recive one double
    Fraction(double);
// Destructor:
    ~Fraction() = default;

// Getters:
    int getNumerator();
    int getDenominator();

//All operators should work on both sides on fractions and doubles type variables.
//on a double var you need use up to 3 digits beyond the desimal point for acuracy.

// operator =:
    Fraction& operator=(const Fraction&);
    Fraction& operator=(double);
// Move assignment operator (for tidy):
    Fraction& operator=(Fraction&& other)noexcept;

//The + operator to add two fractions and return their sum as another fraction in reduced form.
    
    Fraction operator+(const Fraction& other) const;
    Fraction operator+(double other) const;
    Fraction operator+(int other) const;
    Fraction operator+(float other) const;
    friend Fraction operator+(double val1, const Fraction& fraction2)
    {
        return fraction2+(val1);
    };
    friend Fraction operator+(int val1, const Fraction& fraction2)
    {
        return fraction2+(double(val1));
    };
    friend Fraction operator+(float val1, const Fraction& fraction2)
    {
        return fraction2+(double(val1));
    };    

//The - operator to subtract two fractions and return their 
//difference as another fraction in reduced form.
    
    Fraction operator-(const Fraction& other) const;
    Fraction operator-(double other) const;
    Fraction operator-(int) const;
    Fraction operator-(float) const;

    friend Fraction operator-(double val1, const Fraction& fraction2)
    {
        Fraction val_fraction = Fraction(val1);
        return val_fraction-fraction2;
    };
    friend Fraction operator-(int val1, const Fraction& fraction2)
    {
        double sub = double(val1) - fraction2;
        return Fraction(sub);
    };
    friend Fraction operator-(float val1, const Fraction& fraction2)
    {
        return double(val1) - fraction2;
    };                   

//The * operator to multiply 
//two fractions and return their product as another fraction in reduced form.
    
    Fraction operator*(const Fraction&) const;
    Fraction operator*(double) const;
    Fraction operator*(int) const;
    Fraction operator*(float) const;
    friend Fraction operator*(double val1, const Fraction& fraction2)
    {   
       return fraction2*val1;
    };
    friend Fraction operator*(int val1, const Fraction& fraction2)
    {
         return fraction2*val1;
    };
    friend Fraction operator*(float val1, const Fraction& fraction2)
    {
         return fraction2*val1;
    };                


//The / operator to divide 
//two fractions and return their quotient as another fraction in reduced form.
    
    Fraction operator/(const Fraction& other) const;
    Fraction operator/(double other) const;
    Fraction operator/(int other) const;
    Fraction operator/(float) const;
    friend Fraction operator/(double other, const Fraction& fraction2)
    {
        return Fraction(other)/fraction2;
    }; 
    friend Fraction operator/(int other, const Fraction& fraction2)
    {
        return Fraction(other)/fraction2;
    };  
    friend Fraction operator/(float other, const Fraction& fraction2)
    {
        return Fraction(other)/fraction2;
    };       


//The == operator to compare two fractions for equality and return true or false.

    bool operator==(const Fraction& other) const;
    bool operator==(double other) const;
    friend bool operator==(double other, const Fraction& fraction2)
    {   
        return fraction2==other;
    };

// != operator
    bool operator!=(const Fraction&) const;
    bool operator!=(double) const;
    friend bool operator!=(double value, const Fraction& fraction)
    {
        Fraction d_fraction = Fraction(value);
        return !(d_fraction == fraction);
    }; 


//All comparison operations (>,<,>=,<=)

// > :
    bool operator>(const Fraction& other) const;
    bool operator>(double other) const;
    bool operator>(int) const;
    friend bool operator>(double other, const Fraction& fraction2)
    {
         return (other > double(fraction2));
    };
    friend bool operator>(int other, const Fraction& fraction2)
    {
         return (other > double(fraction2));
    };

// < :
    bool operator<(const Fraction& other) const;
    bool operator<(double other) const;
    bool operator<(int) const;
    friend bool operator<(double other, const Fraction& fraction2)
    {
        return (other < double(fraction2));
    };
    friend bool operator<(int other, const Fraction& fraction2)
    {
        return (other < double(fraction2));
    };

// >= :
    bool operator>=(const Fraction& other) const;
    bool operator>=(double other) const;
    bool operator>=(int other) const;
    friend bool operator>=(double other, const Fraction& fraction2)
    {
        return (other >= double(fraction2));
    };
    friend bool operator>=(int other, const Fraction& fraction2)
    {
        return (other >= double(fraction2));
    };
   

// <= :
    bool operator<=(const Fraction& other) const;
    bool operator<=(double other) const;
    bool operator<=(int) const;
    friend bool operator<=(double other, const Fraction& fraction2)
    {
        return (other <= double(fraction2));
    };
    friend bool operator<=(int other, const Fraction& fraction2)
    {
        return (other <= double(fraction2));
    };



//The ++ and -- operator
//that adds (or substracts) 1 to the fraction. implement both pre and post fix.

// prefix: ++n:
    Fraction& operator++();

// postfix: n++:
    const Fraction operator++(int);

// // prefix: --n:
    Fraction& operator--();

// postfix: n--:
    const Fraction operator--(int);



//The << operator to print a fraction to an output stream in the format “numerator/denominator”.
    friend std::ostream& operator<< (std::ostream& output, const Fraction& fraction)
    {
        output << string(fraction);
        return output;
    };

//The >> operator to read a fraction from an input stream by taking two integers as input.
    friend std::istream& operator>> (std::istream& input , Fraction& fraction)
    {
        if(input.peek() == EOF)
        {
            throw std::runtime_error("End of file");
        }
        int numerator = 1;
        input >> numerator;
        if(input.peek() == EOF)
        {
            throw std::runtime_error("End of file");
        }
        int denumerator = 1;
        input >> denumerator;
        if(denumerator == 0)
        {
            throw std::runtime_error("Denumerator is zero");
        }
        fraction = Fraction(numerator,denumerator);
        return input;
    };

// Convert Fraction to double:
    operator double() const;

// to string 
    operator string() const;
    string to_string() const;

};
}

#endif