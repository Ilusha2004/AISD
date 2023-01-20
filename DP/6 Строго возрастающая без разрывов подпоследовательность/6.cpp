#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    long long N, len = 0;
    in >> N;
    vector<long long> posl;
    posl.resize(N);
    vector<long long>::iterator it = posl.begin();
    for_each(posl.begin(), posl.begin() + N, [&in, &posl, &it](long long x){ in >> x; cout << x << endl; *it = x; it++;});
    vector<long long> newposl(N + 1, LLONG_MAX);
    newposl[0] = LLONG_MIN;
    for_each(posl.begin(), posl.end(), [&newposl, &len, &posl](long long x){
        long long j = distance(newposl.begin(), upper_bound(newposl.begin(), newposl.end(), x));
        if(newposl[j - 1] < x && x < newposl[j]){ newposl[j] = x; len = max(j, len); }});
    out << len;
}
