#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

enum Znaki{ EQUAL = true, NOT_EQUAL = false };

// struct Ravenstva{
    
// public:
//     Ravenstva() : value_0(""), znak(true) , value_1("") {}
//     explicit Ravenstva(string _value_0, Znaki _znak, string _value_1): value_0(_value_0), znak(_znak) , value_1(_value_1){}

// private:
//     string value_0;
//     string value_1;
//     bool znak;
// };

class Ravenstva{
    
public:
    Ravenstva() : value_0(""), znak(EQUAL) , value_1("") {}
    explicit Ravenstva(string _value_0, Znaki _znak, string _value_1): value_0(_value_0), znak(_znak) , value_1(_value_1){}

    string getValue_0(){
        return value_0;
    }

    string getValue_1(){
        return value_1;
    }

    bool is_equal(){
        return znak;
    }

    friend ostream& operator<< (ostream& os, const Ravenstva& rav){
        os << rav.value_0 << " " <<  rav.znak << " " << rav.value_1;
        return os;
    } 

private:
    string value_0;
    string value_1;
    Znaki znak;

};

int32_t main(){
    ofstream out("equal-not-equal.out");
    ifstream in("equal-not-equal.in");

    int n, m;
    in >> n >> m;
    vector<Ravenstva> rav(n);

    string val_0, val_1;
    string znak;

    getline(in, val_0, '\n');

    for(int i = 0; i < m; i++){
        getline(in, val_0, ' ');
        getline(in, znak, ' ');
        getline(in, val_1, '\n');
        if(znak == "=="){
            rav[i] = Ravenstva(val_0, EQUAL, val_1);
        }
        else if(znak == "!="){
            rav[i] = Ravenstva(val_0, NOT_EQUAL, val_1);
        }
        cout << rav[i] << endl;
    }

    

}