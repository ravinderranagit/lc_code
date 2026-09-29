#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>

using namespace std;

queue<int> q;
mutex m;
condition_variable cv;

void producer(){
    {
        unique_lock<mutex> lock(m);
        q.push(10);
        cout<<"Produced : " << q.front() << endl;
    }
    cv.notify_one();
}

void consumer(){
    unique_lock<mutex> lock(m);
    cv.wait(lock, []{return !q.empty();});
    cout<<"Consumed : " << q.front() << endl;
    q.pop();
}

int main(){
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
