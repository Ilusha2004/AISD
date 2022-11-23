#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main(){
    ofstream out("output.txt");
    ifstream in("input.txt");

    int n;

    in >> n;

    map<int,int> kanon;

    int value;

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            in >> value;
            if(value == 1){
                kanon[k + 1] = i + 1;
            }
        }
    }
    
    int prev = 0;

    for(auto id : kanon){
        if((prev + 2 == id.first)){
            out << 0 << " ";
        }
        out << id.second << " ";
        prev = id.first;
    }

    if(prev == kanon.size()){
        out << 0 << " ";
    }
}