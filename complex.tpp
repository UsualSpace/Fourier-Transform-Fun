//Filename: complex.tpp
//Programmer: Abdurrahman Alyajouri
//Date: 6/25/2025
//Purpose: To implement the complex struct defined in complex.hpp

#include "complex.hpp"

template<typename TYPE>
complex<TYPE>::complex(TYPE the_real) : real(the_real) {}

template<typename TYPE>
complex<TYPE>::complex(TYPE the_real, TYPE the_imaginary) : real(the_real), imaginary(the_imaginary) {}

template<typename TYPE>
complex<TYPE> complex<TYPE>::operator+(complex<TYPE> rhs) {
    return complex(this->real + rhs.real, this->imaginary + rhs.imaginary);
}

template<typename TYPE>
complex<TYPE> complex<TYPE>::operator-(complex<TYPE> rhs) {
    return complex(this->real - rhs.real, this->imaginary - rhs.imaginary);
}

template<typename TYPE>
complex<TYPE> complex<TYPE>::operator*(complex<TYPE> rhs) {

}

template<typename TYPE>
complex<TYPE> complex<TYPE>::operator/(complex<TYPE> rhs) {

}

template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator+=(complex<TYPE> rhs) {
    this->real += rhs.real;
    this->imaginary += rhs.imaginary;
    return this;
}

template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator-=(complex<TYPE> rhs) {
    this->real -= rhs.real;
    this->imaginary -= rhs.imaginary;
    return this;
}

template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator*=(complex<TYPE> rhs) {

}

template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator/=(complex<TYPE> rhs) {

}

template<typename TYPE>
complex<TYPE> complex<TYPE>::conjugate(void) {
    return complex(this->real, -this->imaginary);
}

template<typename TYPE>
ostream& operator<<(ostream& out, complex<TYPE> rhs) {
    out << rhs.real << ' ';
    if(rhs.imaginary < TYPE(0)) out << "- " << abs(rhs.imaginary) << 'i';
    else out << "+ " << rhs.imaginary << 'i';
    
    return out;
}