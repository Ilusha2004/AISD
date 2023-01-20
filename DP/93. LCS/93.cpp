#include <iostream>
#include <vector>

#pragma comment(linker, "/STACK:66777216")

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<vector<int>> match;
    vector<int> arr_0, arr_1;
    arr_0.resize(N); arr_1.resize(N);
    match.resize(N + 1);

    for(int i = 0; i < N; i++){ cin >> arr_0[i]; }
    for(int i = 0; i < N; i++){ cin >> arr_1[i]; }

    for(int i = 0; i <= N; i++){
        match[i].resize(N + 1);
        match[i][0] = 0;
        match[0][i] = 0;
    }

    for(int i = 1; i <= N; i++){
        for(int k = 1; k <= N; k++){
            if(arr_1[i - 1] == arr_0[k - 1])
                match[i][k] = match[i - 1][k - 1] + 1;
            else if(arr_1[i - 1] != arr_0[k - 1]){
                match[i][k] = max(match[i - 1][k], match[i][k - 1]);
            }
        }
    }

    int up = N;
    int left = N;

    vector<pair<int,int>> indexes;

    while(left > 0 && up > 0 && match[up][left]){
        if(arr_0[left - 1] == arr_1[up - 1]){ indexes.push_back(pair(left - 1, up - 1)); left--; up--; }
        else if(arr_0[left - 1] != arr_1[up - 1]){
            if(match[up - 1][left] > match[up][left - 1]) { up--; }
            else if(match[up - 1][left] <= match[up][left - 1]) { left--; }
        }
    }

    cout << indexes.size() << endl;

    for(int i = indexes.size() - 1; i >= 0; i--){
        cout << indexes[i].first << " ";
    }

    cout << endl;

    for(int i = indexes.size() - 1; i >= 0; i--){
        cout << indexes[i].second << " ";
    }
    
    return 0;
}