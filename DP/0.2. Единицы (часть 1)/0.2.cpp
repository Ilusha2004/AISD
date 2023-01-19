#define module (unsigned long long)1000000007
#include <iostream>

using namespace std;

unsigned long long Fact(int N){
    unsigned long long NFact = 1;
    for(long long i = 1; i <= N; ++i){
        NFact = (NFact * i) % module;
    }
    return NFact;
}

unsigned long long NKfact(int N, int K){
    unsigned long long NFact = 1;
    for(long long i = N - K + 1; i <= N; ++i){
        NFact = (NFact * i) % module;
    }
    return NFact;
}

unsigned long long BinaryStep(unsigned long long val){
    unsigned long long result = 1;
    unsigned long long mod = module - 2;

    while(mod > 0){
        if(mod % 2 == 1){
            result = (result * val) % module;
        }
        val = (val * val) % module;
        mod = mod >> 1;
    }
    return result;
}

int main(){
    int N, K;
    cin >> N >> K;
    unsigned long long NFact = Fact(N);
    unsigned long long KFact = Fact(K);
    unsigned long long NKFact = NKfact(N, K);
    cout << (NKFact * BinaryStep(KFact)) % module;
}