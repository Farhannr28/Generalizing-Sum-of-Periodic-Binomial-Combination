/**
 * @file Polynomial.hpp
 * @brief Class representing Polynomial
 */

#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>

using namespace std;

class NumberTheoreticTransform;

class Polynomial {
    private:
        vector<int> coefficients;
        int degree;
        const int MOD = 998244353;
    public:
        Polynomial(int d);
        Polynomial(initializer_list<int> list);
        ~Polynomial();

        vector<int>& getCoefficients();
        int getDegree();
        void setCoefficients(vector<int> b);
        void setDegree(int _degree);

        /// @brief reduce polynomial by using w^m = 1
        /// @param m Such m-th root of unity
        void reduceDegree(int m);

        /// @brief reduce polynomial by using 1+w+w^2+...+w^{m-1} = 0
        /// @param m Such m-th root of unity
        void reducePolynom(int m);

        void printCoefficients();

        Polynomial& operator=(const Polynomial& other);

        Polynomial& operator*=(const Polynomial& other);
};

#endif