#include <iostream> 
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#define LLong long long

using namespace std;


int main() {
    ofstream out("output.txt");
    ifstream in("input.txt");

    int n;

    in >> n;

    vector<vector<LLong>> graph(n);
    vector<LLong> pred(n);
    queue<LLong> que;

    LLong value;

    for(LLong i = 0; i < n; i++) {
        graph[i].resize(n);
        for(LLong k = 0; k < n; k++) {
            in >> value;
            graph[i][k] = value;
        }   
    }

    vector<bool>is_visited(n, false);

    LLong distance = 0;

    for(LLong k = 0; k < n; k++) {

        if(is_visited[k] == true) {
            continue;
        }

        distance++;

        is_visited[k] = true;
        que.push(k);
        pred[k] = distance;

        while(que.size() != 0) {
            LLong ver = que.front();
            que.pop();

            for(LLong i = 0; i < n; i++) {
                if(graph[ver][i] && !is_visited[i]) {
                    que.push(i);
                    is_visited[i] = true;
                    distance++;
                    pred[i] = distance; 
                }
            }

        }

    }

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            cout << graph[i][k] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(auto& id : pred) {
        out << id << " ";
    }
}