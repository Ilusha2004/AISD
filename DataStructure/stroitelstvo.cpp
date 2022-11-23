#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, q;

    in >> n >> q;

    unordered_map<long long, long long> roads;

    for(int i = 1; i <= q; i++){
        roads[i] = i;
    }


    long long val_0, val_1;

    for(int i = 0; i < q; i++){
        in >> val_0 >> val_1;

        long long temp_0, temp_1;

        temp_0 = roads[val_0];
        temp_1 = roads[val_1];

        if(temp_0 != temp_1){
            if(temp_0 >= temp_1){
                roads[val_0] = temp_1;
            }
            else{
                roads[val_1] = temp_0;
            }
        }

        long long iter_temp = 0;

        for_each(roads.begin(), roads.end(), [&iter_temp](auto& id){
            if(id.first == id.second){
                iter_temp++;
            }
            cout << id.first << " " << id.second << endl;
        });

        out << iter_temp << endl;

        cout << endl;
    }

}