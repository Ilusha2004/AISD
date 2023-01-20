#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Sum{

private:
    std::vector<long long> sum_array;
    long long size;
    long long c_requests;

public:

    Sum() : size(0ll),
            c_requests(0ll),
            sum_array() {}

    explicit Sum(long long __size, long long __c_requests, std::vector<long long> __sum_array) :
        size(__size),
        c_requests(__c_requests),
        sum_array(__sum_array) {}

    inline long long FindSum(long long __start, long long __stop);
    inline void Add(long long __loc, const long long& __value);
    inline long long get_size();
    inline long long get_requests();
    std::vector<long long> get_arr();
    
    friend std::istream& operator>> (std::istream& __is, Sum& __sum){
        __is >> __sum.size;
        __sum.sum_array.resize(__sum.size);
        for(size_t __iter = 0; __iter < __sum.size; __iter++){  __is >> __sum.sum_array[__iter]; }
        __is >> __sum.c_requests;
        return __is;
    }

    friend std::ostream& operator<< (std::ostream& __os, Sum& __sum){
        __os << "Size: " << __sum.size << std::endl
             << "Array: ";
        std::for_each(__sum.sum_array.begin(), __sum.sum_array.end(), [&__os](auto __id){
        __os << __id << " "; });
        __os << std::endl << "Requests: " << __sum.c_requests;
        return __os;
    }

    void init (long long __nn) {
        size = __nn;
        sum_array.assign(size, 0ll);
    }

    long long sum(long long __right) {
        long long result = 0;
        for (; __right >= 0; __right = (__right & (__right + 1)) - 1)
            result += sum_array[__right];
        return result;
    }

    void inc(long long __i, long long __delta) {
        for (; __i < size; __i = (__i | (__i + 1)))
            sum_array[__i] += __delta;
    }

    inline long long FindSum(long long __left, int __rigth) {
        return sum(__rigth) - sum(__left - 1);
    }

    void initial() {
        std::vector<long long> __temp = sum_array;
        init((int) __temp.size());
        for (long long i = 0; i < __temp.size(); i++)
            inc(i, __temp[i]);
    }

};

long long Sum::get_size(){
    return size;
}

inline long long Sum::get_requests(){
    return c_requests;
}

inline std::vector<long long> Sum::get_arr(){
    return sum_array;
}

int main(){
    std::ofstream out("output.txt", std::ios::out);
    std::ifstream in("input.txt", std::ios::in);

    Sum summing = Sum();
    std::string command;
    std::string start, stop;

    std::cin >> summing;

    summing.initial();

    std::getline(std::cin, command, '\n');

    for(size_t it = 0; it < summing.get_requests(); it++){
        std::getline(std::cin, command, ' ');
        std::getline(std::cin, start, ' ');
        std::getline(std::cin, stop, '\n');

        if(command == "FindSum"){
            std::cout << summing.FindSum(stoi(start), stoi(stop) - 1) << std::endl;
        }
        else if(command == "Add"){
            summing.inc(stoi(start), stoi(stop));
        }
    }
}