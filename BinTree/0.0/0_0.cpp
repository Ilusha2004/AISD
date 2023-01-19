#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main(){
    set<long long> tree;
    long long sum = 0;
    ifstream out("input.txt");
    ofstream in("output.txt");

    while(out){
        long long a;
        
        out >> a;
        cout << a << " ";
        tree.insert(a);
    }

    for(auto i: tree){
        sum += i;
    }

    in << sum;
    

}