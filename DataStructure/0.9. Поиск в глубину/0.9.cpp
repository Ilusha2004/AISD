#include <iostream> 
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#define LLong long long

using namespace std;

void dfs(LLong start, vector<vector<LLong>>& graph, vector<bool>& is_visited, vector<LLong>& metka, LLong& distance) {
    metka[start] = distance;
    is_visited[start] = true;

    distance++;
    
    for(LLong i = 0; i < is_visited.size(); i++) {
        if(is_visited[i] == false && graph[start][i] == 1) {
            dfs(i, graph, is_visited, metka, distance);
        }
    }
}
 

int main() {
    ofstream out("output.txt");
    ifstream in("input.txt");

    LLong n;
    in >> n;

    vector<vector<LLong>> graph(n);
    LLong value;

    for(LLong i = 0; i < n; i++) {
        graph[i].resize(n);
        for(LLong k = 0; k < n; k++) {
            in >> value;
            graph[i][k] = value;
        }   
    }

    vector<LLong> pred(n);
    queue<LLong> que;
    vector<bool>is_visited(n, false);
    vector<LLong> metka(n);

    LLong distance = 0;

    for(LLong i = 0; i < n; i++) {
        if(is_visited[i] == false) {
            dfs(i, graph, is_visited, metka, distance);
        }
    }

    for(auto& id : metka) {
        out << id + 1 << " ";
    }

}