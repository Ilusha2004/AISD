#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#define INF LLONG_MAX
#define llong long long

using namespace std;

class Tree{

public:
    llong FindShortesLine(){
        q.insert(make_pair(0, 0));
        while(!q.empty()) {
            llong iter = q.begin()->second;
		    q.erase(q.begin());
            for(llong k = 0ll; k < graph[iter].size(); k++){ 
                llong p_0 = graph[iter][k].first;
                 llong lenght = graph[iter][k].second;
                  if(lenght + temp[iter] < temp[p_0]){ q.erase(make_pair(temp[p_0], p_0));
                   temp[p_0] = lenght + temp[iter];
                    q.insert(make_pair(temp[p_0], p_0));} }
        }
        return temp[n - 1];
    }

    void Initialize(){
        ifstream in("input.txt");
        in >> n >> m;
        graph.resize(n);
        for(llong i = 0; i < m; i++){ llong u, v, w; in >> u >> v >> w; graph[u - 1].push_back(make_pair(v - 1, w)); graph[v - 1].push_back(make_pair(u - 1, w)); }
        temp.assign(n, INF); is_pos.resize(n); temp[0ll] = 0ll;
        in.close();
    }

private:
    vector<vector<pair<llong,llong>>> graph;
    vector<llong> temp;
    vector<bool> is_pos;
    set < pair<long long, long long> > q;
    llong n, m;

};

int main() {
    ofstream out("output.txt");
    Tree Main;
    Main.Initialize();
    out << Main.FindShortesLine();
    out.close();

}