#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main(){
    ofstream out("output.txt");
    ifstream in("input.txt");

    vector<pair<int, int>> duga;

    int n, m;

    in >> n >> m;

    int v_0, v_1;

    for(int i = 0; i < m; i++){
        in >> v_0 >> v_1;
        duga.push_back(pair(v_1, v_0));
        
    }

    for(int i = 1; i <= n; i++){
        int lenght = 0;
        vector<int> temp;
        for(auto idd : duga){
            if(i == idd.first){
                temp.push_back(idd.second);
                lenght++;
            }
            else if(i == idd.second){
                temp.push_back(idd.first);
                lenght++;
            }
        }
        out << lenght << " ";
        for(const auto& id : temp){
            out << id << " ";
        }
        out << endl;
    }


}