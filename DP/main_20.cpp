#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string palindrome;
    in >> palindrome;

    int size = palindrome.size();

    vector<vector<int>> pal;
    pal.resize(size);

    for (int i = 0; i < size; i++) {
        pal[i].resize(size);
        for (int k = 0; k < size; k++) {
            pal[i][k] = 0;
        }
    }

    for (int i = 0; i < size; i++) {
        pal[i][i] = 1;
    }

    for (int k = 1; k < pal.size(); k++) {
        for (int i = 0; i < pal.size() - k; i++) {
            int j = i + k;
            if (palindrome[i] == palindrome[j]) {
                pal[i][j] = pal[i + 1][j - 1] + 2;
            }
            else if (palindrome[i] != palindrome[j]) {
                pal[i][j] = max(pal[i + 1][j], pal[i][j - 1]);
            }
        }
    }

    int left = 0;
    int right = size - 1;
    int PalRIg = pal[0][size - 1] - 1;
    vector<char> newpal;
    newpal.resize(PalRIg + 1);
    int PalLEf = 0;
    while (left <= right){
        if(left == right && pal[left][right] == 1){
            newpal[PalLEf] = palindrome[left];
            PalLEf++;
            left++;
        }
        else{
            if (palindrome[left] == palindrome[right]){
                newpal[PalLEf] = palindrome[left];
                PalLEf++;
                left++;
                newpal[PalRIg] = palindrome[right];
                PalRIg--;
                right--;
            }
            else{
                if (pal[left + 1][right] >= pal[left][right - 1])
                    left++;
                else
                    right--;
            }
        }
    }

    out << newpal.size() << endl;

    for(int i = 0; i < newpal.size(); i++){
        out << newpal[i];
    }
    
}
