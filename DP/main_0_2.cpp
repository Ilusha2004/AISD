#define CNK num_of_com4

#include <iostream>
#include <limits>

using namespace std;

double num_of_com4(uint n, uint m){
    uint k = n - m;
    if (m > k)
        m = k;
    if (!m)
        return 1;
    uint akk = k = n - m + 1;
    k++;
    for (uint i = 2; i <= m; i++, k++)
        akk = akk / i * k + akk % i * k / i;
    return akk;
}

int main(){
    cout << std::numeric_limits<double>::max() << endl;
    cout << CNK(6, 4);
}