#include <iostream>
#include <vector>

namespace bsl {

    bool binary_search(std::vector<int>::iterator begin, std::vector<int>::iterator end, const int& x){
        std::vector<int>::iterator iter = begin;
        int left = 0; int right = end - begin;
        int middle = 0;
        
        while(left < right){
            middle = (right + left) / 2;
            if(*(begin + middle) == x){
                return true;
            }
            else if(*(begin + middle) > x){
                right = middle;
            }
            else if(*(begin + middle) < x){
                left = middle + 1;
            }
        }
        return false;
    }

    int upper_bound(std::vector<int>::iterator begin, std::vector<int>::iterator end, const int& x){
        std::vector<int>::iterator iter = begin;
        int left = 0; int right = end - begin;
        int middle = 0;
        
        while(left < right){
            middle = (right + left) / 2;
            if(*(begin + middle) > x){
                right = middle;
            }
            else if(*(begin + middle) <= x){
                left = middle + 1;
            }
        }
        return left;
    }

    int lower_bound(std::vector<int>::iterator begin, std::vector<int>::iterator end, const int& x){
        std::vector<int>::iterator iter = begin;
        int left = 0; int right = end - begin;
        int middle = 0;
        
        while(left < right){
            middle = (right + left) / 2;
            if(*(begin + middle) >= x){
                right = middle;
            }
            else if(*(begin + middle) < x){
                left = middle + 1;
            }
        }
        return left;
    }

    void comparing(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::vector<int>::iterator x){
        std::cout << binary_search(begin, end, *x) << " " << lower_bound(begin, end, *x) << " " 
        << upper_bound(begin, end, *x) << std::endl; 
    }

}

using namespace std;

int main(){

    int n = 0, k = 0;
    cin >> n;

    auto print = [](const int& n) { cout << n << " "; };

    vector<int> first_arr(n);
    std::vector<int>::iterator it = first_arr.begin();

    std::for_each(first_arr.begin(), first_arr.end(), [&it](int p){
        cin >> p; *it = p; it++;
    });

    std::sort(first_arr.begin(), first_arr.end(), [](int a, int b){
        return a < b;
    });

    cin >> k;

    vector<int> second_arr(k);
    std::vector<int>::iterator iter = second_arr.begin();

    std::for_each(second_arr.begin(), second_arr.end(), [&iter](int p){
        cin >> p; *iter = p; iter++;
    });

    iter = second_arr.begin();

    while(iter != second_arr.end()){
        bsl::comparing(first_arr.begin(), first_arr.end(), iter);
        iter++;
    }

    return 0;
}