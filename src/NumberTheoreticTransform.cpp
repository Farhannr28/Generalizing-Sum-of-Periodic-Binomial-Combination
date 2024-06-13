#include "header/NumberTheoreticTransform.hpp"
#include "header/Exponentiation.hpp"
#include "header/Polynomial.hpp"

#include <vector>
#include <complex>


#include<iostream>

using namespace std;

void NumberTheoreticTransform::setM(int _m){
    NumberTheoreticTransform::getInstance().m = _m;
}

NumberTheoreticTransform& NumberTheoreticTransform::getInstance(){
    static NumberTheoreticTransform instance;
    return instance;
}

void NumberTheoreticTransform::ntt(vector<int>& a, int n, int root) {
    if (n == 1) return;
    vector<int> even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    NumberTheoreticTransform::ntt(even, n / 2, root);
    NumberTheoreticTransform::ntt(odd, n / 2, root);

    int wlen = Exponentiation<int>::getInstance().BinaryExponentiation(root, (MOD - 1) / n, MOD);
    int w = 1;

    for (int i = 0; i < n / 2; ++i) {
        a[i] = (even[i] + 1LL * w * odd[i] % MOD) % MOD;
        a[i + n / 2] = (even[i] - 1LL * w * odd[i] % MOD + MOD) % MOD;
        w = 1LL * w * wlen % MOD;
    }
    return;
}

void NumberTheoreticTransform::ntt_inverse(vector<int>& a, int n) {
    ntt(a, n, Exponentiation<int>::getInstance().BinaryExponentiation(ROOT, MOD - 2, MOD));
    int inv_n = Exponentiation<int>::getInstance().BinaryExponentiation(n, MOD - 2, MOD);
    for (int i = 0; i < n; ++i) {
        a[i] = 1LL * a[i] * inv_n % MOD;
    }
    return;
}

Polynomial NumberTheoreticTransform::multiply(Polynomial a, Polynomial b) {
    int n = 1;
    while (n < a.getDegree() + b.getDegree() + 1) {
        n <<= 1;
    }

    // cout << "N: " << n << "\n";

    a.getCoefficients().resize(n);
    b.getCoefficients().resize(n);
    NumberTheoreticTransform::ntt(a.getCoefficients(), n, ROOT);
    NumberTheoreticTransform::ntt(b.getCoefficients(), n, ROOT);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = 1LL * a.getCoefficients()[i] * b.getCoefficients()[i] % MOD;
    }
    NumberTheoreticTransform::ntt_inverse(c, n);
    Polynomial res(n-1);
    res.setCoefficients(c);

    // cout << "MULTIPLICATION RESULT: \n";
    // res.printCoefficients();
    // cout << "\n";
    // cout << res.getDegree() << "\n";
    // cout << "\n";

    res.reduceDegree(m);


    // res.printCoefficients();
    // cout << "\n";


    res.reducePolynom(m);


    // res.printCoefficients();
    // cout << "\n";


    return res;
}