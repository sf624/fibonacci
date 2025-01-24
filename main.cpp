#include <iostream>
#include <string>
#include <Eigen/Dense>
#include <boost/multiprecision/gmp.hpp>

using mp_int = boost::multiprecision::mpz_int;
using Matrix = Eigen::Matrix<mp_int, 2, 2>;

Matrix power(const Matrix & mat, const int n) {
    if (n < 2) return mat;
    Matrix ret = power(mat, n / 2);
    ret *= ret;
    if (n % 2 != 0) ret *= mat;
    return ret;
}

mp_int fib(const int n) {
    if (n < 2) return n;
    Matrix transition_matrix;
    transition_matrix <<
        1, 1,
        1, 0;
    const Matrix trainsition_matrix_powered = power(transition_matrix, n - 1);
    return trainsition_matrix_powered(0, 0);
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