#ifndef IO_HPP
#define IO_HPP

class IO{
    private:
        const int MOD = 998244353;
        int N_input;
        int M_input;
        int R_input;
        int duration;

    public:
        IO();
        ~IO();
        int getN();
        int getM();
        int getR();
        int setDuration(int _duration);
        void title();
        void askInputs();
        void showAnswer(int answer, bool error);
        bool askRestart();
};

#endif