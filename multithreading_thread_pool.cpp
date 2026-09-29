u#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>

using namespace std;

queue<int> q;
mutex m;
condition_variable cv;

// void producer(){
//     {
//         unique_lock<mutex> lock(m);
//         q.push(10);
//         cout<<"Produced : " << q.front() << endl;
//     }
//     cv.notify_one();
// }

void consumer(){
    unique_lock<mutex> lock(m);
    cv.wait(lock, []{return !q.empty();});
    cout<<"Consumed : " << q.front() << endl;
    q.pop();
}

int main(){
    thread t1(consumer);
    thread t2(consumer);
    thread t3(consumer);
    thread t4(consumer);
    {
        unique_lock<mutex> lock(m);
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
    }
    cv.notify_all();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
