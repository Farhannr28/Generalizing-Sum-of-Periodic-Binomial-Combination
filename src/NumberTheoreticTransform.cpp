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
    a.getCoefficients().resize(n);
    b.getCoefficients().resize(n);
    NumberTheoreticTransform::ntt(a.getCoefficients(), n, ROOT);
    NumberTheoreticTransform::ntt(b.getCoefficients(), n, ROOT);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = 1LL * a.getCoefficients()[i] * b.getCoefficients()[i] % MOD;
    }
    NumberTheoreticTransform::ntt_inverse(c, n);
    Polynomial res(n-2);
    res.setCoefficients(c);
    res.reduceDegree(m);
    res.reducePolynom(m);
    return res;
}

// int main() {
//     // Polynomial a({1,1});
//     // Polynomial res({1,1});
//     // for (int i=0; i<3; i++){
//     //     res = NumberTheoreticTransform::getInstance().multiply(res, a);
//     // }
//     // res.printCoefficients();
//     // cout << "\n";
//     // Polynomial a1({1,0,1});
//     // Polynomial res1({1,0,1});
//     // for (int i=0; i<3; i++){
//     //     res1 = NumberTheoreticTransform::getInstance().multiply(res1, a1);
//     // }
//     // res1.printCoefficients();
//     // cout << "\n";

//     Polynomial a({1,1});
//     Polynomial res = Exponentiation<Polynomial>::getInstance().BinaryExponentiation(a, 5, 998244353);
//     Polynomial a2({1,0,1});
//     Polynomial res2 = Exponentiation<Polynomial>::getInstance().BinaryExponentiation(a2, 5, 998244353);
//     res.printCoefficients();
//     res2.printCoefficients();
//     return 0;
// }