#include <iostream>
#include <fstream>

using namespace std;

struct Frog{
public:
    int amount = 0; 
    int amountPlace = 0;
};

int main(){

    ifstream in("input.txt");
    ofstream out("output.txt");

    int N = 0;
    in >> N;
    Frog* frog = new Frog[N];

    for(int i = 0; i < N; i++){
        in >> frog[i].amountPlace;
    }

    if(N < 3 && N > 1){
        out << -1;
    }

    else{
        frog[0].amount = frog[0].amountPlace;

        for(int i = 2; i < N; i++){
            if(i == 2) frog[i].amount += frog[i - 2].amountPlace + frog[i].amountPlace;
            else frog[i].amount += max(frog[i - 2].amount, frog[i - 3].amount) + frog[i].amountPlace;
        }

        out << frog[N - 1].amount;
    }

}