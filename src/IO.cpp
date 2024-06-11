#include "header/IO.hpp"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int IO::getN(){
    return N_input;
}

int IO::getM(){
    return M_input;
}

int IO::getR(){
    return R_input;
}

int IO::setDuration(int _duration){
    duration = _duration;
}

IO::IO(){
    system("cls");
    title();
    askInputs();
}

IO::~IO(){

}

void IO::title(){
    cout << R"(
        | ___ \       (_)         | (_)      /  __ \               | |   (_)           | | (_)             /  ___|                
        | |_/ /__ _ __ _  ___   __| |_  ___  | /  \/ ___  _ __ ___ | |__  _ _ __   __ _| |_ _  ___  _ __   \ `--. _   _ _ __ ___  
        |  __/ _ \ '__| |/ _ \ / _` | |/ __| | |    / _ \| '_ ` _ \| '_ \| | '_ \ / _` | __| |/ _ \| '_ \   `--. \ | | | '_ ` _ \ 
        | | |  __/ |  | | (_) | (_| | | (__  | \__/\ (_) | | | | | | |_) | | | | | (_| | |_| | (_) | | | | /\__/ / |_| | | | | | |
        \_|  \___|_|  |_|\___/ \__,_|_|\___|  \____/\___/|_| |_| |_|_.__/|_|_| |_|\__,_|\__|_|\___/|_| |_| \____/ \__,_|_| |_| |_|
        )" << endl;
    cout << R"(_.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._.~"~._)";
    cout << endl;
    cout << ">>> Written by Farhan Nafis Rayhan for his Strategy & Algorithms paper" << endl;
    cout << endl;
    cout << ">>> This program Calculates The sum" << endl;
    cout << endl;
    cout << "           nCr + nC_(m+r) + nC_(2m+r) + ... " << endl;
    cout << endl;
    cout << ">>> By utilizing Number Theoritic Transform & Binary Exponentiation" << endl;
    cout << endl;
}

void IO::askInputs(){
    cout << ">>> Let N be the number of objects for all combination, and the amount of chosen are all R modulo M" << endl;
    cout << endl;
    cout << ">>> Note that as the solution might be very large, this program will display it modulo " << MOD << endl;
    cout << endl;
    cout << ">>> Please input N M R you want to calculate, separated by spaces" << endl;
    cout << endl;
    cout << "??? ";
    cin >> this->N_input >> this->M_input >> this->R_input;
    cout << endl;
    cout << ">>> Great! that means you want to calculate the following" << endl;
    cout << "           " << N_input << "C" << R_input << " + " << N_input << "C" << M_input + R_input << " + " << N_input << "C" << 2*M_input + R_input << " + ... " << endl;
    cout << endl;
    cout << ">>> Please wait as the algorithm crunching the numbers" << endl;
    cout << endl;
}

void IO::showAnswer(int answer, bool error){
    cout << ">>> Answer Found!" << endl;
    cout << endl;
    if (error){
        cout << ">>> The answer is most possibly " << answer * -1 << endl;
        cout << endl;
        cout << ">>> There might be an error in this answer since the program not so sure about it" << endl;
        cout << endl;
    } else {
        cout << ">>> The answer must be " << answer << endl;
        cout << endl;
        cout << ">>> The program is certain with the accuracy of this answer" << endl;
        cout << endl;
    }
        cout << ">>> Please remember that the solution is calculated in modulo " << MOD << endl;
        cout << endl;
        cout << ">>> The Algorithm took " << duration << " milliseconds for this calculation" << endl;
        cout << endl;
}

bool IO::askRestart(){
    string input;
    cout << ">>> Go you want to do another calculation? (yes/no)" << endl;
    cout << endl;
    cout << "??? ";
    cin >> input;
    return (input=="yes");
}