//Filename: complex.tpp
//Programmer: Abdurrahman Alyajouri
//Date: 6/25/2025
//Purpose: To implement the complex struct defined in complex.hpp

#include <cmath>
#include "complex.hpp"

template<typename TYPE>
complex<TYPE>::complex(TYPE the_real) : real(the_real) {}

template<typename TYPE>
complex<TYPE>::complex(TYPE the_real, TYPE the_imaginary) : real(the_real), imaginary(the_imaginary) {}

template<typename TYPE>
TYPE complex<TYPE>::magnitude(void) {
    return sqrt(this->real * this->real + this->imaginary * this->imaginary); //sqrt takes in a double but should be fine with other primitive arithmetic types.
}

template<typename TYPE>
complex<TYPE> complex<TYPE>::conjugate(void) {
    return complex(this->real, -this->imaginary);
}

//Compound assignment complex to real operator overloads.
template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator+=(TYPE rhs) {
    this->real += rhs;
    return *this;
}

template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator-=(TYPE rhs) {
    this->real -= rhs;
    return *this;
}

template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator*=(TYPE rhs) {
    this->real *= rhs;
    this->imaginary *= rhs;
    return *this;
}

// template<typename TYPE>
// complex<TYPE>& complex<TYPE>::operator/=(TYPE rhs) {

// }

//Compound assignment complex to complex operator overloads.
template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator+=(complex<TYPE> rhs) {
    this->real += rhs.real;
    this->imaginary += rhs.imaginary;
    return *this;
}

template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator-=(complex<TYPE> rhs) {
    this->real -= rhs.real;
    this->imaginary -= rhs.imaginary;
    return *this;
}

template<typename TYPE>
complex<TYPE>& complex<TYPE>::operator*=(complex<TYPE> rhs) {
    this->real = this->real * rhs.real - this->imaginary * rhs.imaginary;
    this->imaginary = this->imaginary * rhs.real + this->real * rhs.imaginary;
    return *this;
}

// template<typename TYPE>
// complex<TYPE>& complex<TYPE>::operator/=(complex<TYPE> rhs) {

// }

//overloaded insertion operator.
template<typename TYPE>
ostream& operator<<(ostream& out, complex<TYPE> rhs) {
    out << rhs.real << ' ';
    if(rhs.imaginary < TYPE(0)) out << "- " << abs(rhs.imaginary) << 'i';
    else out << "+ " << rhs.imaginary << 'i';
    
    return out;
}

//Binary complex to complex operator overloads.
template<typename TYPE>
complex<TYPE> operator+(complex<TYPE> lhs, complex<TYPE> rhs) {
    lhs += rhs;
    return lhs;
}

template<typename TYPE>
complex<TYPE> operator-(complex<TYPE> lhs, complex<TYPE> rhs) {
    lhs -= rhs;
    return lhs;
}

template<typename TYPE>
complex<TYPE> operator*(complex<TYPE> lhs, complex<TYPE> rhs) {
    lhs *= rhs;
    return lhs;
}

// template<typename TYPE>
// complex<TYPE> operator/(complex<TYPE> lhs, complex<TYPE> rhs) {

// }

//Binary real to complex operator overloads.
template<typename TYPE>
complex<TYPE> operator+(TYPE lhs, complex<TYPE> rhs) {
    rhs += lhs; //reusing code.
    return rhs;
}

template<typename TYPE>
complex<TYPE> operator-(TYPE lhs, complex<TYPE> rhs) {
    return complex<TYPE>(lhs - rhs.real, rhs.imaginary);
}

template<typename TYPE>
complex<TYPE> operator*(TYPE lhs, complex<TYPE> rhs) {
    rhs *= lhs; //reusing code.
    return rhs;
}

// template<typename TYPE>
// complex<TYPE> operator/(TYPE lhs, complex<TYPE> rhs);

//Binary complex to real operator overloads.
template<typename TYPE>
complex<TYPE> operator+(complex<TYPE> lhs, TYPE rhs) {
    lhs += rhs;
    return lhs;
}

template<typename TYPE>
complex<TYPE> operator-(complex<TYPE> lhs, TYPE rhs) {
    lhs -= rhs;
    return lhs;
}

template<typename TYPE>
complex<TYPE> operator*(complex<TYPE> lhs, TYPE rhs) {
    lhs *= rhs;
    return lhs;
}

// template<typename TYPE>
// complex<TYPE> operator/(complex<TYPE> lhs, TYPE rhs) {
    
// }