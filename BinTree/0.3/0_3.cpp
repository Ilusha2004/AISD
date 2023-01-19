#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node{
    long long amount;
    long long max;
    long long min;

    Node(long long _amount, long long _max, long long _min) : amount(_amount), max(_max), min(_min) {};
};

int main() {
    ifstream in("bst.in");
    ofstream out("bst.out");

    int n, root, amount, prev;
    string side;

    in >> n >> root;

    vector<Node> BFT(n + 1, Node(0, LLONG_MAX, LLONG_MIN));
 
    long long max = LLONG_MAX, min = LLONG_MIN;

    BFT[0] = Node(root, max, min);

    for(int i = 1; i <= n; i++) {
        in >> amount >> prev >> side;

        if(side == "L" && amount < BFT[prev].max){

            if (BFT[prev].amount == LLONG_MIN){
                out << "NO";
                return 0;
            }

            BFT[i].amount = amount;
            BFT[i].max = BFT[prev].amount - 1;
            BFT[i].min = BFT[prev].min;
        }

        else if(side == "R"  && amount >= BFT[prev].min) {
            BFT[i].amount = amount;
            BFT[i].min = BFT[prev].amount;
            BFT[i].max = BFT[prev].max;
        }
        
        else {
            out << "NO";
            return 0;
        }

    }

    out << "YES";
}