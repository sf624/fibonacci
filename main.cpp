#include <iostream>
#include <string>
#include <utility>
#include <boost/multiprecision/gmp.hpp>

using mp_int = boost::multiprecision::mpz_int;

std::pair<mp_int, mp_int> fib_core(const int n) {
    if (n == 0) return {0 , 1};
    const auto [a, b] = fib_core(n / 2);
    const mp_int c = a * (b * 2 - a);
    const mp_int d = a * a + b * b;
    if (n % 2 == 0) return {c, d};
    else return {d, c + d};
}

inline mp_int fib(const int n) {
    return fib_core(n).first;
}

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cerr << "Pass an integer to calculate fibonacci." << std::endl;
        return 1;
    }
    const std::string s = argv[1];
    try {
        size_t end;
        const int n = std::stoi(s, &end);
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
        std::cerr << "Integer too large. Should be smaller than " << INT_MAX << "." << std::endl;
        return 1;
    }
    return 0;
}