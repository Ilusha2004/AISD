#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

#pragma warning(disable : 4996)

#define LLong long long

using namespace std;

class DSU {

public:
    DSU(LLong n) {
        N = n;
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for (LLong i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    LLong FindSet(LLong v) {
        if (parent[v] == v)
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

    vector<LLong> getParent() {
        return parent;
    }

private:
    vector<LLong> size;
    vector<LLong> parent;
    LLong N;

};

int32_t main() {

    ofstream out("equal-not-equal.out", ios_base::out);
    FILE* file;
   
    fopen_s(&file, "equal-not-equal.in", "r");

    vector<pair<LLong, LLong> > NeRavno;
    char temp = ' ';

    int n, m;

    fscanf(file, "%d", &n);
    fscanf(file, "%*c%d", &m);

    bool correct = true;

    DSU Main = DSU(n);

    for (size_t i = 0; i < m; i++) {

        string val_0, val_1;

        int value_0 = 0;
        int value_1 = 0;

        char znak = ' ';

        fscanf(file, "\n", temp);
        fscanf(file, "%*c %d", &value_0);
        fscanf(file, "%c", &temp);
        fscanf(file, "%c ", &znak);
        fscanf(file, "%c", &temp);
        fscanf(file, "%c", &temp);
        fscanf(file, "%c", &temp);
        fscanf(file, "%d", &value_1);

        if (znak == '=') {
            Main.Union(value_0, value_1);
        }

        else if (znak != '=') {
            NeRavno.push_back(make_pair(value_0, value_1));
        }

    }

    for (auto id : NeRavno) {
        if (Main.FindSet(id.first) == Main.FindSet(id.second)) {
            out << "No";
            correct = false;
            break;
        }
    }

    if (correct == true) {
        out << "Yes";
    }

}