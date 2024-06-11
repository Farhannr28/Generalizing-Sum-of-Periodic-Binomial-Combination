/**
 * @file NumberTheoreticTransform.hpp
 * @brief Singleton Class for Number Theoritic Transform Calculator
 */
#ifndef NUMBERTHEORITICTRANSFORM_HPP
#define NUMBERTHEORITICTRANSFORM_HPP

#include "Polynomial.hpp"

#include <vector>

using namespace std;

/// @brief Singleton Class for Number Theoritic Transform Calculator
class NumberTheoreticTransform{
    private:
        NumberTheoreticTransform(){}
        ~NumberTheoreticTransform(){}
        const int MOD = 998244353;
        const int ROOT = 3;
        int m;

    public:
        void setM(int _m);
        static NumberTheoreticTransform& getInstance();
        Polynomial multiply(Polynomial a, Polynomial b);
        void ntt_inverse(vector<int>& a, int n);
        void ntt(vector<int>& a, int n, int root);
};

#endif