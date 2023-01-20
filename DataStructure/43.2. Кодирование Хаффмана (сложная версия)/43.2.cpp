#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
int main(){std::ifstream in("huffman.in");std::ofstream out("huffman.out");long long N;long amount;in >> N;auto cmp = [](long long left, long long right) { return (left) > (right); };std::priority_queue<long long, std::vector<long long>, decltype(cmp)> Haffman(cmp);for(long long i = 0; i < N; i++){in >> amount;Haffman.push(amount);}in.close();long long sum = 0ll;for(long long i = 0ll; i < N - 1; i++){long long temp_sum = 0ll;temp_sum += Haffman.top(); Haffman.pop();temp_sum += Haffman.top();Haffman.pop();Haffman.emplace(temp_sum);sum += temp_sum;}out << sum;}