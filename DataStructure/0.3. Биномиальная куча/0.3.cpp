#include <iostream>
#include <fstream>
#include <vector>

int main(){
    std::vector<int> heap;

    long long mult = 1;
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    long long N;
    in >> N;

    int iter = 0;

    while(mult <= N){
        mult *= 2;
        iter += 1;
    }

    while(N > 0){
        if(mult > N){
            mult /= 2;
            iter--;
        }
        else if(N >= mult){
            std::cout << iter << std::endl;
            heap.push_back(iter);
            N -= mult;
        }
        else if(iter <= 0){
            break;
        }

    }

    for(int i = heap.size() - 1; i >= 0; i--){
        out << heap[i] << std::endl;
    }

}