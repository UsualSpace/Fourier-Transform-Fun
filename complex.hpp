//Filename: complex.hpp
//Programmer: Abdurrahman Alyajouri
//Date: 6/25/2025
//Purpose: To define the complex struct, representing complex numbers. Only intended to be used with primitive numeric types

#pragma once

#include <iostream>

using std::ostream;

template<typename TYPE>
struct complex {
    //Default and overloaded ctors.
    complex() = default;
    complex(TYPE the_real); //Construct a complex from a real number.
    complex(TYPE the_real, TYPE the_imaginary);

    complex<TYPE> operator+(TYPE rhs);
    complex<TYPE> operator-(TYPE rhs);
    complex<TYPE> operator*(TYPE rhs);
    complex<TYPE> operator/(TYPE rhs);

    complex<TYPE> operator+(complex<TYPE> rhs);
    complex<TYPE> operator-(complex<TYPE> rhs);
    complex<TYPE> operator*(complex<TYPE> rhs);
    complex<TYPE> operator/(complex<TYPE> rhs);

    complex<TYPE>& operator+=(complex<TYPE> rhs);
    complex<TYPE>& operator-=(complex<TYPE> rhs);
    complex<TYPE>& operator*=(complex<TYPE> rhs);
    complex<TYPE>& operator/=(complex<TYPE> rhs);

    complex<TYPE> conjugate(void);

    TYPE real;        //The real component of the complex number.
    TYPE imaginary;   //The imaginary component of the complex number.
};

//Overloaded insertion operator (output).
template<typename TYPE>
ostream& operator<<(ostream& out, complex<TYPE> rhs);

template<typename TYPE>
complex<TYPE> operator+(TYPE lhs, complex<TYPE> rhs);

template<typename TYPE>
complex<TYPE> operator-(TYPE lhs, complex<TYPE> rhs);

template<typename TYPE>
complex<TYPE> operator*(TYPE lhs, complex<TYPE> rhs);

template<typename TYPE>
complex<TYPE> operator/(TYPE lhs, complex<TYPE> rhs);

#include "complex.tpp"
