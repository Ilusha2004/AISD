#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    long long N, len = 0;
    long long element = 0;
    vector< vector<long long> > razrposl;
    in >> N;
    razrposl.resize(2);

    for(int i = 0; i < 2; i++){
        razrposl[i].resize(N);
        for(int k = 0; k < N; k++){
            razrposl[i][k] = LLONG_MAX;
        }
    }
    int range = 0;
    int lenMax = 0;

    for(int i = 0; i < N; i++){
        in >> element;
        for(int k = 1; k >= 0; k--){
            int range = distance(razrposl[k].begin(), lower_bound(razrposl[k].begin(), razrposl[k].end(), element));
            razrposl[k][range] = element;
            if(k != 0){
                int NewRange = range + 1;
                while (razrposl[0][NewRange - 1] != LLONG_MAX){
                    razrposl[1][NewRange] = element; NewRange++;
                } 
                if(lenMax < NewRange){
                    lenMax = NewRange;
                }
            }
        }
    }
    out << lenMax;
}