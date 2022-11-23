#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    long long N;
    in >> N;
    long long* kucha = new long long(N);
    for(long long i = 0; i < N; i++){ in >> kucha[i]; }
    in.close();
        
    bool is_bin = true;

    for(long long i = 0; i < N; i++){
        if((2 * (i + 1) - 1 < N)&&(kucha[i] > kucha[2 * (i + 1) - 1])){ is_bin = false; break; }
        if((2 * (i + 1) < N)&&(kucha[i] > kucha[2 * (i + 1)])){ is_bin = false; break; }
    }

    out << (is_bin == true ? "Yes" : "No") << endl;
    out.close();
}

