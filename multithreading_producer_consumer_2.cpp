#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<queue>
using namespace std;

mutex mtx;
condition_variable not_full;
condition_variable not_empty;
queue<int> q;
const int CAPACITY = 5;

void producer(){
    for(int i=0; i<10; i++){
        {
            unique_lock<mutex> lock(mtx);
            not_full.wait(lock, []{ return q.size() < CAPACITY; });
            q.push(i);
            cout << "produced: " << i << " (queue size=" << q.size() << ")" << endl;
        }
        not_empty.notify_all();
    }
}

void consumer(){
    for(int i=0; i<10; i++){
        int item;
        {
            unique_lock<mutex> lock(mtx);
            not_empty.wait(lock, []{ return !q.empty(); });
            item = q.front();
            q.pop();
            cout << "consumed: " << item << " (queue size=" << q.size() << ")" << endl;
        }
        not_full.notify_all();
    }
}

int main(){
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
