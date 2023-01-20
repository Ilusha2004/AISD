#include <iostream>
#include <vector>
#include <fstream>
#define LLong long long

using namespace std;

class DSU{

public:
    DSU(LLong n) {
        N = n;
        parent.resize(n + 1);
        size.assign(n + 1, 1);
    
        for(LLong i = 0; i <= n; i++){
            parent[i] = i;
        }
    } 

    LLong FindSet(LLong v) {
        if(parent[v] == v)
            return v;
        return parent[v] = FindSet(parent[v]);
    }

    LLong Union(LLong x, LLong y) {
        
        x = FindSet(x);
        y = FindSet(y);
        if (x != y) {
            N--;
            if (size[x] < size[y]) {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
        }

        return N;

    }

    void Print(){
        for(auto& id : parent) {
            cout << id << " ";
        }
        cout << endl;

        for(auto& id : size) {
            cout << id << " ";
        }
        cout << endl << endl;
    }

private:
    vector<LLong> size;
    vector<LLong> parent;
    LLong N;

};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    LLong n, m;
    in >> n >> m;
    DSU Main = DSU(n);

    for(LLong i = 0; i < m; i++){
        LLong u, v;
        in >> u >> v;
        out << Main.Union(u, v) << endl;
    }

}