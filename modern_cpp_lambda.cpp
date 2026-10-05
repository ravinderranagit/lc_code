// lamda

#include<iostream>
using namespace std;

// bool isEven(int val){
//     if(!val%2)
//         return true;
//     else
//         return false;
//}

int main(){
    int val = 3;
    //cin >> val;

    // normal function
    // if(isEven(val)){
    //     cout << "EVEN!";
    // } else {
    //     cout << "ODD!";
    // }

    // lambda function
    auto isEvenCheck = [](int val){
        return (val%2 == 0);
    };

    if(isEvenCheck(val))
        cout <<"EVEN!";
    else
        cout <<"ODD!";
}