//Filename: main.cpp
//Programmer: Abdurrahman Alyajouri
//Date: 6/25/2025
//Purpose: To implement dft and fft algorithms.

#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

#include "complex.hpp"

#define PI 3.141592653589793238462643
#define TWOPI (2 * PI)

typedef double demo_t;

demo_t my_signal(demo_t x);
void print_vector(const vector<complex<demo_t>>& v);
vector<complex<demo_t>> to_complex(const vector<demo_t>& v);
vector<demo_t> sample_function(function<demo_t(demo_t)> func, size_t num_samples, demo_t low, demo_t high);

vector<complex<demo_t>> dft(const vector<complex<demo_t>>& signal);
vector<complex<demo_t>> fft(const vector<complex<demo_t>>& signal);
vector<complex<demo_t>> idft(const vector<complex<demo_t>>& spectrum);
vector<complex<demo_t>> ifft(const vector<complex<demo_t>>& spectrum);

int main(void) {

    auto samples = to_complex(sample_function(my_signal, 20, 0, 1));
    auto spectrum = dft(samples);

    print_vector(samples);

    for(size_t f = 0; f < spectrum.size(); ++f) {
        cout << "Frequency " << f << ": " << spectrum.at(f).magnitude() << endl;
    }

    auto idft_spectrum = idft(spectrum);

    print_vector(idft_spectrum);

    return 0;
}

demo_t my_signal(demo_t x) {
    demo_t frequency_1 = 5;
    return 100 * sin(TWOPI * x * frequency_1) + cos(TWOPI * x * 2);
}

void print_vector(const vector<complex<demo_t>>& v) {
    for(auto x : v) cout << x << ", ";
    cout << endl;
}

vector<complex<demo_t>> to_complex(const vector<demo_t>& v) {
    vector<complex<demo_t>> result;
    for(auto x : v) result.push_back(complex<demo_t>(x));
    return result;
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

vector<complex<demo_t>> dft(const vector<complex<demo_t>>& signal) {
    size_t N = signal.size();

    vector<complex<demo_t>> frequency_bins(N, 0);
    for(size_t frequency = 0; frequency < N; ++frequency) {
        for(size_t n = 0; n < N; ++n) {
            demo_t angle = (-TWOPI * frequency * n) / N;
            frequency_bins.at(frequency) += signal.at(n) * complex<demo_t>(cos(angle), sin(angle));
        }
    }

    return frequency_bins;
}

vector<complex<demo_t>> idft(const vector<complex<demo_t>>& spectrum) {
    auto l_spectrum = spectrum;
    for(auto& c : l_spectrum) c = c.conjugate();
    auto idft = dft(l_spectrum);
    for(auto& c : idft) c = c.conjugate() / (demo_t) spectrum.size();
    return idft;
}