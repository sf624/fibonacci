#include <iostream>
#include <string>
#include <utility>
#include <limits>
#include <boost/multiprecision/gmp.hpp>

using mp_int = boost::multiprecision::mpz_int; // Multi precision int
using fp_int = long long; // Fixed precision int

template<typename T>
constexpr T bit_length() {
    return sizeof(T) * CHAR_BIT;
}

inline mp_int fib(const fp_int n) {
    mp_int a = 0;
    mp_int b = 1;
    for (fp_int i = bit_length<fp_int>() - 1; i >= 0; i--) {
        const mp_int d = a * (b * 2 - a);
        const mp_int e = a * a + b * b;
        a = d;
        b = e;
        if (((n >> i) & 1) != 0) {
            const mp_int c = a + b;
            a = b;
            b = c;
        }
    }
    return a;
}

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cerr << "Pass an integer to calculate fibonacci." << std::endl;
        return 1;
    }
    const std::string s = argv[1];
    try {
        size_t end;
        const fp_int n = std::stoll(s, &end);
        if (end < s.length()) {
            std::cerr << "Non integer input detected." << std::endl;
            return 1;
        }
        if (n < 0) {
            std::cerr << "Integer should be non-negative." << std::endl;
            return 1;
        }
        std::cout << fib(n) << std::endl;
        return 0;
    } catch (const std::invalid_argument &) {
        std::cerr << "Non integer input detected." << std::endl;
        return 1;
    } catch (std::out_of_range &) {
        std::cerr << "Integer is out of range. It should be non negative and equal or smaller than " << std::numeric_limits<fp_int>::max() << "." << std::endl;
        return 1;
    }
    return 0;
}