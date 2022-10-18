#include <iostream>
#include <vector>
#include <fstream>
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "RUSSIAN");

    ifstream in("in.txt");
    ofstream out("out.txt");

    int R, D, I;

    in >> D >> I >> R;

    string str_0, str_1;

    in >> str_0 >> str_1;

    vector<vector<int>> preobr;
    preobr.resize(str_0.size() + 1);

    for(int i = 0; i <= str_0.size(); i++){preobr[i].resize(str_1.size() + 1); preobr[i][0] = i * D; }
    for(int i = 0; i <= str_1.size(); i++){ preobr[0][i] = i * I; }

    for(int i = 1; i <= str_0.size(); i++){
        for(int k = 1; k <= str_1.size(); k++){
            if(str_0[i - 1] == str_1[k - 1]){
                preobr[i][k] = preobr[i - 1][k - 1];
                continue;
            }
            preobr[i][k] = min(min(preobr[i - 1][k] + D, preobr[i][k - 1] + I), preobr[i - 1][k - 1] + R);
        }
    }

    for(auto i : preobr){
        for(auto& id : i){
            cout << id << " ";
        }
        cout << endl;
    }

    cout << preobr[str_0.size()][str_1.size()] << endl;

}