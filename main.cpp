//Filename: main.cpp
//Programmer: Abdurrahman Alyajouri
//Date: 6/25/2025
//Purpose: To implement dft and fft algorithms.

#include <functional>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#include "complex.hpp"

#define PI 3.141592653589793238462643

typedef double demo_t;

demo_t my_signal(demo_t x);
void print_vector(vector<demo_t> v);
vector<demo_t> sample_function(function<demo_t(demo_t)> func, size_t num_samples, demo_t low, demo_t high);

int main(void) {

    complex<demo_t> a(2.0, 3.23);

    cout << a << endl << a.conjugate() << endl << a << endl;

    auto samples = sample_function(my_signal, 1, 0, 1);

    print_vector(samples);

    return 0;
}

demo_t my_signal(demo_t x) {
    demo_t frequency_1 = 1;
    demo_t frequency_2 = 2;
    return sin(2 * PI * x * frequency_1);
}

void print_vector(vector<demo_t> v) {
    for(auto x : v) cout << x << ' ';
    cout << endl;
}

vector<demo_t> sample_function(function<demo_t(demo_t)> func, size_t num_samples, demo_t low, demo_t high) {
    vector<demo_t> samples;

    if(num_samples == 0) return samples;

    demo_t dx = (high - low) / num_samples;
    demo_t x = low;
    while(x < high) {
        samples.push_back(func(x));
        x += dx;
    }

    return samples;
}