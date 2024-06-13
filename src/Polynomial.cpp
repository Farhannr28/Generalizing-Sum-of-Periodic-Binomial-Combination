#include "header/Polynomial.hpp"
#include "header/NumberTheoreticTransform.hpp"

#include <iostream>

using namespace std;

Polynomial::Polynomial(int d){
    this->degree = d;
    this->coefficients = vector<int>(d+1);
}

Polynomial::Polynomial(initializer_list<int> list) : coefficients(list){
    this->degree = list.size()-1;
}

Polynomial::~Polynomial(){}

vector<int>& Polynomial::getCoefficients(){
    return this->coefficients;
}

int Polynomial::getDegree(){
    return this->degree;
}

void Polynomial::setCoefficients(vector<int> b){
    this->coefficients = b;
    return;
}

void Polynomial::setDegree(int _degree){
    this->degree = _degree;
    return;
}

void Polynomial::reduceDegree(int m){
    for (int i=m; i<=this->getDegree(); i++){
        this->coefficients[i%m] = this->coefficients[i%m] + this->coefficients[i] % MOD;
    }
    this->coefficients.resize(m);
    this->degree = m-1;
    return;
}

void Polynomial::reducePolynom(int m){
    int minimal = __INT32_MAX__;
    for (int i=0; i<m; i++){
        minimal = min(minimal, this->coefficients[i]);
    }
    for (int i=0; i<m; i++){
        this->coefficients[i] -= minimal;
    }
    return;
}

void Polynomial::printCoefficients(){
    for (uint16_t i=0; i<coefficients.size(); i++){
        cout << "X" << i << " : " << this->getCoefficients()[i] << "\n";
    }
    return;
}

Polynomial& Polynomial::operator=(const Polynomial& other){
    this->degree = other.degree;
    this->coefficients = other.coefficients;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other){
    Polynomial res = NumberTheoreticTransform::getInstance().multiply(*this, other);
    *this = res;
    return *this;
}