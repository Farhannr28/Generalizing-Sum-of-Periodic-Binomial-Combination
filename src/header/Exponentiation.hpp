/**
 * @file Exponentiation.hpp
 * @brief Singleton Generic Class for Exponentiation Calculator
 */

#ifndef EXPONENTIATION_HPP
#define EXPONENTIATION_HPP

#include<iostream>

using namespace std; 

/// @brief Implementation for Binary Exponentitation
/// @tparam T 
/// @param a 
/// @param exp 
/// @param mod 
/// @return 
template<class T>
T BinaryExponentiationImplementation(T a, int exp){
    exp--;
    T res = a;
    while (exp > 0) {

        // cout << exp << "\n";
        // cout << "RES: " << "\n";
        // res.printCoefficients();
        // cout << "A: " << "\n";
        // a.printCoefficients();
        // cout << "\n";

        if (exp & 1){
            res *= a;

            // cout << "ODD\n";

        }
        a *= a;
        exp = exp >> 1;
    }
    return res;
}


/// @brief Singleton Generic Class for Exponentiation Calculator
/// @tparam T Class
template<class T>
class Exponentiation{
    private:
        /// @brief Constructor for Exponentiation Class.
        Exponentiation(){}
        /// @brief Destructor for Exponentiation Class.
        ~Exponentiation(){}
    public:
        /// @brief Get Singleton Instance
        /// @return Singleton Instance
        static Exponentiation& getInstance(){
            static Exponentiation instance;
            return instance;
        }
        /// @brief Binary Exponentiation for a^exp
        /// @param a 
        /// @param exp 
        /// @return T
        T BinaryExponentiation(T a, int exp){
            return BinaryExponentiationImplementation(a, exp);
        }
};

template<>
/**
 * @class Integer Exponentiation
 * @brief Singleton Specialized Integer Class for Exponentiation Calculator
 *
 */
class Exponentiation<int>{
    private:
        /// @brief Constructor for Exponentiation Class.
        Exponentiation(){}
        /// @brief Destructor for Exponentiation Class.
        ~Exponentiation(){}
    public:
        /// @brief Get Singleton Instance
        /// @return Singleton Instance
        static Exponentiation& getInstance(){
            static Exponentiation instance;
            return instance;
        }
        /// @brief Binary Exponentiation for a^exp
        /// @param a 
        /// @param exp 
        /// @param mod 
        /// @return int
        int BinaryExponentiation(int a, int exp, int mod){
            a %= mod;
            exp--;
            int res = a;
            while (exp > 0) {
                if (exp & 1)
                    res = (1LL * res * a) % mod;
                a = (1LL * a * a) % mod;
                exp = exp >> 1;
            }
            return res;
        }
        /// @brief Calculating Inverse of num modulo mod, returns num^(mod-2)
        /// @param num 
        /// @param mod 
        /// @return int
        int inverse(int num, int mod){
            return Exponentiation<int>::getInstance().BinaryExponentiation(num, mod-2, mod);
        }
};

#endif