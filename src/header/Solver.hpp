#ifndef SOLVER_HPP
#define SOLVER_HPP

class Solver{
    private:
        const int MOD = 998244353;
        const int ROOT = 3;
        int N;
        int M;
        int R;

    public:
        Solver();
        void Run();
        void setN(int _N);
        void setM(int _M);
        void setR(int _R);
        int Calculate(int N, int M, int R);
};

#endif