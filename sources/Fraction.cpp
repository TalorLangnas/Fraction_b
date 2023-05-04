#include "Fraction.hpp"
using namespace std;
using namespace ariel;

// Constructors:

// default:
    Fraction::Fraction(): nom(0), den(1)//, gcd(0)
    {

    };
// reciving to doubles:
    Fraction::Fraction(double nom_other,double den_other) 
    {   
        if(den_other == 0)
        {
            throw std::invalid_argument("illeagal value, denominator can not be qeual to zero");
        }
        else if (nom_other == 0)
        {   
            nom = 0;
            den = 1;
        }
        else
        {
        int gcd_val = __gcd(int(nom_other), int(den_other));
        long long numerator = static_cast<long long int>(nom_other)/
                                static_cast<long long int>(gcd_val);
        long long denumerator = static_cast<long long int>(den_other)/
                                static_cast<long long int>(gcd_val);
        if((numerator > INT_MAX) || (numerator < INT_MIN)
            || (denumerator < INT_MIN) || (denumerator > INT_MAX))
        {
            throw std::overflow_error("multiplication value is over Flow");
        }                            
        nom = nom_other/gcd_val;
        den = den_other/gcd_val;   
        }            
         
    };

// copy:
    Fraction::Fraction(const Fraction& other)
    {
        if(this == &other)
        {
            return;
        }
        nom = other.nom;
        den = other.den;      
    };
// Move constructor (for tidy):
    Fraction::Fraction(Fraction&& other)noexcept
    {
        if (this == &other)
        {
            return;
        }
        nom = other.nom;
        den = other.den;        
    };
// Move assignment operator (for tidy):
    Fraction& Fraction::operator=(Fraction&& other)noexcept
    {
        if (this == &other)
        {
            return (*this);
        }
        nom = other.nom;
        den = other.den;
        return (*this);
    };


//  assuming that double does not have more than 3 digits after decimal point 
    Fraction::Fraction(double other)
    {
        if (other == 0)
        {
            nom = 0;
            den = 1;
        }
        else
        {
        int presicion = 1000;
        int numerator = other*presicion;
        int denomerator = 1*presicion;
        int gcd = __gcd(numerator, denomerator);
        nom = numerator/gcd;
        den = denomerator/gcd;
        }
                  
    };

// Getters:
    int Fraction::getNumerator()
    {
        return nom;
    };
    int Fraction::getDenominator()
    {
        return den;
    };

// Convert Fraction to double:
    Fraction::operator double() const
    {   
        //double convert = double(nom)/double(den);
        return (double(nom)/double(den));
    };

// operator =:
    Fraction& Fraction::operator=(const Fraction& other)
    {
        if (this == &other)
        {
            return *this;
        }
        (*this).nom = other.nom;
        (*this).den = other.den;        
        return (*this);         
    };

    Fraction& Fraction::operator=(double other)
    {
        if (*this == other)
        {
            return *this;
        }
        //delete[] this;
        Fraction fraction = Fraction(other);

        return (*this = fraction);    
    };    

// operator (+):

    Fraction Fraction::operator+(const Fraction& other) const
    {   
        long long den_check = static_cast<long long int>(den) * static_cast<long long int>(other.den);
        long long nom_check = static_cast<long long int>(nom*(other.den)) + 
                                static_cast<long long int>((other.nom) * den);
        cout << "den_check = " << den_check << endl;
        cout << "nom_check = " << nom_check << endl;
        cout << "INT_MAX = " << INT_MAX << endl;
        cout << "INT_MIN = " << INT_MIN << endl;                       
        if(nom_check < INT_MIN || (nom_check > INT_MAX) ||
            (den_check < INT_MIN) || (den_check > INT_MAX))
        {   cout << "enter to long long "<<endl;
            throw std::overflow_error("multiplication value is over Flow");
        }

        int denominator = den * other.den; 
        int numerator = nom*(other.den) + (other.nom) * den;
        return Fraction(numerator, denominator);
    };

    Fraction Fraction::operator+(double other) const
    {
        return (*this)+(Fraction(other));
    };
    Fraction Fraction::operator+(int other) const // Check if this method is neccesery 
    {                                                 // i did this method beacuse the
        return (*this)+Fraction(other);
        
    };
     Fraction Fraction::operator+(float other) const
    {
        return (*this)+(Fraction(other));
    };
    
    
    
//The - operator to subtract two fractions and return their 
//difference as another fraction in reduced form.
    
    Fraction Fraction::operator-(const Fraction& other) const
    {   
        long long den_check = static_cast<long long int>(den) * static_cast<long long int>(other.den);
        long long nom_check = static_cast<long long int>(nom*(other.den)) - 
                                static_cast<long long int>((other.nom) * den);
        if(nom_check < INT_MIN || (nom_check > INT_MAX) ||
            (den_check < INT_MIN) || (den_check > INT_MAX))
        {   cout << "enter to long long "<<endl;
            throw std::overflow_error("multiplication value is over Flow");
        }
        int denominator = den * other.den;
        int numerator = nom*(other.den) - (other.nom) * den;
        return Fraction(numerator, denominator);
    };
    Fraction Fraction::operator-(double other) const
    {
        return (*this)-(Fraction(other));
    };
    Fraction Fraction::operator-(int other) const
    {
        return (*this)-(Fraction(other));
    };
    Fraction Fraction::operator-(float other) const
    {
        return (*this)-(Fraction(other));
    };

//The * operator to multiply 
//two fractions and return their product as another fraction in reduced form.
    
    Fraction Fraction::operator*(const Fraction& other) const
    {   
        long long den_check = static_cast<long long int>(den) * static_cast<long long int>(other.den);
        long long nom_check = static_cast<long long int>(nom) * 
                                static_cast<long long int>(other.nom);
        if(nom_check < INT_MIN || (nom_check > INT_MAX) ||
            (den_check < INT_MIN) || (den_check > INT_MAX))
        {   cout << "enter to long long "<<endl;
            throw std::overflow_error("multiplication value is over Flow");
        }
        //check_mul(den, other.den);
        int denominator = den * other.den;
        //check_mul(nom, other.nom);
        int numerator = nom*(other.nom);
        return Fraction(numerator, denominator);
    };

    Fraction Fraction::operator*(double other) const
    {   
        return (*this)*Fraction(other);
    };

    Fraction Fraction::operator*(int other) const
    {
        return (*this)*(Fraction(other));
    };
     Fraction Fraction::operator*(float other) const
    {
        return (*this)*(Fraction(other));
    };
   
//The / operator to divide 
//two fractions and return their quotient as another fraction in reduced form.
    
    Fraction Fraction::operator/(const Fraction& other) const
    {    

        Fraction fraction = other;
        if(fraction.getDenominator() >= INT_MAX || fraction.getNumerator() >= INT_MAX)
        {
            throw std::overflow_error("input is overFlow");
        }
        if (other.nom == 0)
        {
            throw std::runtime_error("can not divide in zero");
        }
        Fraction inverse = Fraction(other.den, other.nom);
        return (*this)*inverse; 
    };
    Fraction Fraction::operator/(double other) const
    {
        if (other == 0)
        {
            throw std::runtime_error("can not divide in zero");
        }
        Fraction o = Fraction(other);
        return (*this)/o;
    };
    Fraction Fraction::operator/(int other) const
    {
        return (*this)/double(other);
    };  
    Fraction Fraction::operator/(float other) const
    {
        return (*this)/double(other);
    };                          


//The == operator to compare two fractions for equality and return true or false.

    bool Fraction::operator==(const Fraction& other) const
    {   
        double this_frac = double(*this);
        double other_frac = double(other); 
        //return (this_frac == other_frac);
        return (*this)==other_frac;
    };
    bool Fraction::operator==(double other) const
    { 
        float TOLERANCE = 0.001;
        double frac = double(*this);
        bool ans = ((abs(frac - other) <= TOLERANCE));
        return ans;
    };

// != operator
    bool Fraction::operator!=(const Fraction& other) const
    {   
        return double(*this) != double(other); 
    };
    bool Fraction::operator!=(double other) const
    {
        return !((*this) == other); 
    };   

    // > :
    bool Fraction::operator>(const Fraction& other) const
    {
        return (double(*this) > double(other));
    };
    bool Fraction::operator>(double other) const
    { 
        double f = double(*this); 
        return (f > other);
    };
     bool Fraction::operator>(int other) const
    { 
        double f = double(*this); 
        return (f > other);
    };
    bool operator>(double other, const Fraction& c2)
    {
        return (other > double(c2));
    };

// < :
    bool Fraction::operator<(const Fraction& other) const
    {
        return (double(*this) < double(other));
    };
    bool Fraction::operator<(double other) const
    {
         return (double(*this) < other);
    };
    bool Fraction::operator<(int other) const
    {
         return (double(*this) < other);
    };

// >= :
    bool Fraction::operator>=(const Fraction& other) const
    {
        return (double(*this) >= double(other));
    };
    bool Fraction::operator>=(double other) const
    {
        return (double(*this) >= other);
    };
    bool Fraction::operator>=(int other) const
    {
        return (double(*this) >= other);
    };

// <= :
    bool Fraction::operator<=(const Fraction& other) const
    {
        return (double(*this) <= double(other));
    };
    bool Fraction::operator<=(double other) const
    {
         return (double(*this) <= other);
    };
    bool Fraction::operator<=(int other) const
    {
         return (double(*this) <= other);
    };

//The ++ and -- operator
//that adds (or substracts) 1 to the fraction. implement both pre and post fix.

// prefix: ++n:
    Fraction& Fraction::operator++()
    {
        (*this) = (*this) + 1;
        return (*this);
    };

// postfix: n++:
    const Fraction Fraction::operator++(int)
    {   
        Fraction copy = (*this);
        (*this) = (*this) + 1;
        return copy;
    };

// // prefix: --n:
    Fraction& Fraction::operator--()
    {   
        (*this) = (*this) - 1;
        return (*this);
    };

// postfix: n--:
    const Fraction Fraction::operator--(int)
    {  
        Fraction copy = (*this);
         (*this) = (*this) - 1;
        return copy;
    };

// to string
     Fraction::operator string() const       // conversion operator
    {             
		Fraction fraction; 
        if((*this) < 0)
        {
            fraction = (*this)*(-1);
            return std::to_string((-1)*fraction.getNumerator())+"/"
                                    +std::to_string(fraction.getDenominator());
        }
        return std::to_string(nom)+"/"+std::to_string(den);
	}
    
    string Fraction::to_string() const
    {  
        return string(*this);
    };

   



    
    
