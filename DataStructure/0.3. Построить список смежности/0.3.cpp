#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main(){
    ofstream out("output.txt");
    ifstream in("input.txt");

    vector<vector<int> > duga;

    int n, m;

    in >> n >> m;

    duga.resize(n);

    int v_0, v_1;

    for(int i = 1; i < m + 1; i++){
        in >> v_0 >> v_1;
        duga[v_0 - 1].push_back(v_1);
        duga[v_1 - 1].push_back(v_0);
    }

    for(auto id : duga){
        out << id.size() << " ";
        for(auto& it : id){
            out << it << " ";
        }
        out << endl;
    }



}