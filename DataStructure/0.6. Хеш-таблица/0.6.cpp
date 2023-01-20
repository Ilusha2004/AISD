#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int m, c, n;

    in >> m >> c >> n;

    vector<int> temp_hash(n);

    for(int i = 0; i < n; i++){
        in >> temp_hash[i];
    }

    vector<int> hash(m);

    for(int i = 0; i < m; i++){
        hash[i] = -1;
    }

    set<int> dn;

    for(int i = 0; i < n; i++){
        int size = dn.size();
        dn.insert(temp_hash[i]);
        if(size == dn.size()){
            continue;
        }
        int l = 0;
        int p;
        while(true){
            p = ((temp_hash[i] % m) + c * l) % m;
            if(hash[p] == -1){
                hash[p] = temp_hash[i];
                break;
            }
            l++;
        }
    }


     for(auto& id : hash){
        out << id << " ";
    }


}