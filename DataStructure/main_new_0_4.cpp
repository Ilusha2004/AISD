#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ofstream out("output.txt");
    ifstream in("input.txt");

    int n, m;
    in >> n >> m;

    vector<vector<int>>table;
    table.resize(n);

    for(int i = 0; i < n; i++){
        table[i].resize(n);
        for(int k = 0; k < n; k++){
            table[i][k] = 0;
        }
    }

    int v_0, v_1;

    for(int i = 0; i < m; i++){
        in >> v_0 >> v_1;
        table[v_0 - 1][v_1 - 1] = 1;
        table[v_1 - 1][v_0 - 1] = 1;
    }

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            out << table[i][k] << " ";
        }
        out << endl;
    }
}