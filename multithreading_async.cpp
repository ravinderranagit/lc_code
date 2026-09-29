#include<iostream>
#include<thread>
#include<future>
using namespace std;

int square(int a){
    return a*a;
}

int main(){
    future<int> f = async(&square,2);
    int result = f.get();
    cout<< "result : " << result << endl;
    return 0;
}
