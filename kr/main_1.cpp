#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 0;
    cin >> N;

    vector <long long> array(N);
    for (size_t i = 0; i < array.size(); i++){
        cin >> array[i];
        if (array[i] < 0) {
            array[i] *= -1;
        }
    }
    vector <long long> newarray(N);

    for (size_t i = 0; i < array.size(); i++){
        for (int j = 0; j < i; j++) {
            if (array[j] != 0) {
                continue;
            }
            if (array[i] % array[j] != 0) {
                newarray[i] = max(newarray[j], newarray[i]);
            }
        }
        newarray[i]++;
    } 

    sort(newarray.begin(), newarray.end());
    cout << N - newarray[N - 1];
}