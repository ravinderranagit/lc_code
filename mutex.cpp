#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex mtx;
int val = 0;

void increment(){
    mtx.lock();
    for(int i=0; i<1000; i++){
        ++val;
    }
    mtx.unlock();
}

int main(){
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();
    cout<<val<<endl;
}
