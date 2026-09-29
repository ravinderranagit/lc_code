#include<iostream>
#include<thread>
#include<atomic>

using namespace std;

atomic<int> ready(false);
int value;

void producer(){
    value = 10;
    cout<<"produced : " << value << endl;
    ready.store(true, memory_order_release);
}

void consumer(){
    while(!ready.load(memory_order_acquire)){
        cout << "nothing to consume" << endl;
    }
    cout << "consumed: " << value << endl;
}

int main(){
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}
