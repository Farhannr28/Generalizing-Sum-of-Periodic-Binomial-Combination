#include "header/Solver.hpp"
#include "header/NumberTheoreticTransform.hpp"
#include "header/Exponentiation.hpp"
#include "header/Polynomial.hpp"
#include "header/IO.hpp"

#include <chrono>

using namespace std;

Solver::Solver(){
    this->Run();
}

void Solver::Run(){
    bool restart = true;
    while (restart){
        IO io;
        setN(io.getN());
        setM(io.getM());
        setR(io.getR());
        auto start = std::chrono::steady_clock::now();
        int ans = Calculate(N,M,R);
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        io.setDuration(duration);
        io.showAnswer(ans, ans < 0);
        restart = io.askRestart();
    }
}

void Solver::setN(int _N){
    N = _N;
}

void Solver::setM(int _M){
    M = _M;
}

void Solver::setR(int _R){
    R = _R;
}

int Solver::Calculate(int N, int M, int R){
    if (R==0){
        R = M;
    }
    NumberTheoreticTransform::getInstance().setM(M);
    int C = Exponentiation<int>::getInstance().BinaryExponentiation(2, N, MOD);
    Polynomial result(M-1);
    Polynomial temp(1);
    Polynomial expo(M-1);
    temp.getCoefficients()[0] = 1;
    temp.getCoefficients()[1] = 1;
    expo = Exponentiation<Polynomial>::getInstance().BinaryExponentiation(temp, N);

    // temp.printCoefficients();
    // cout << "\n";
    // expo.printCoefficients();
    // cout << "\n";

    for (int j=0; j<M; j++){
        result.getCoefficients()[(j + M - R) % M] += expo.getCoefficients()[j];
    }
    for (int i=2; i<M; i++){
        temp.getCoefficients().push_back(1);
        temp.getCoefficients()[i-1] = 0;
        temp.setDegree(temp.getDegree()+1);
        expo = Exponentiation<Polynomial>::getInstance().BinaryExponentiation(temp, N);

        // temp.printCoefficients();
        // cout << "\n";
        // expo.printCoefficients();
        // cout << "\n";

        for (int j=0; j<M; j++){
            result.getCoefficients()[(j + (i * (M-R))) % M] += expo.getCoefficients()[j];
        }
    }
    result.getCoefficients()[0] = (C + result.getCoefficients()[0]) % MOD;


    // result.printCoefficients();


    result.reducePolynom(M);

    // Theoritically only X_0 persits, if so Divide by M, otherwise report possible error

    int k = 1;
    while (k < M && result.getCoefficients()[k] == 0){
        k++;
    }

    int answer = result.getCoefficients()[0];

    answer = ((1LL) * answer * Exponentiation<int>::getInstance().inverse(M, MOD)) % MOD;
    if (k == M){
        // Show Answer, as a positive
        return answer;
    } else {
        // Report, as a negative
        return answer * -1;
    }
}