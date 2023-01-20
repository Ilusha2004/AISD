#include <iostream>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int main(){
    ofstream out("output.txt");
    ifstream in("input.txt");

    int n;

    in >> n;

    map<int,int> kanon;
    set<int> ver;
    int v_0, v_1;
    int index_null = 0;
    
    for(int i = 1; i < n; i++){
        in >> v_0 >> v_1;
        ver.insert(v_0);
        kanon[v_1] = v_0;
    }

    for(auto id : kanon){
        cout << id.first << " " << id.second << endl;
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