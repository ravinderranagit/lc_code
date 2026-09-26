#include <iostream>
#include<chrono>
#include<unordered_map>
#include<queue>
#include<mutex>

using namespace std;

class RateLimiter {
    private:
        mutex mtx;
        int maxRequests;
        int windowSeconds;
        unordered_map<string, queue<time_t>> clientRequests;
        // do you need a mutex here? think about it — will this be called from multiple threads?
    public:
        RateLimiter(int maxRequests, int windowSeconds) : maxRequests(maxRequests), windowSeconds(windowSeconds) {}
        
        bool allowRequest(string clientId) {
            lock_guard<mutex> lock(mtx);
            time_t currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());

            if(clientRequests.find(clientId) != clientRequests.end()){
                auto& clientIdQueue = clientRequests[clientId];
                // FIX 1: loop condition now checks front() is expired BEFORE popping
                while(!clientIdQueue.empty() && (currentTime - clientIdQueue.front() > windowSeconds)){
                    clientIdQueue.pop();
                }
                if(clientIdQueue.size() < maxRequests){
                    clientIdQueue.push(currentTime);
                    return true;
                }
                return false;
            } else {
                // FIX 2: new client -> create queue, push timestamp, return true
                queue<time_t> tempQueue;
                tempQueue.push(currentTime);
                clientRequests[clientId] = tempQueue;
                return true;
            }
        }

        void showQueueData(){
            lock_guard<mutex> lock(mtx);
            for(auto i : clientRequests){
                cout<<"Client ID : " << i.first;
                auto queueData = i.second;
                if(!queueData.empty()){
                    cout<<" Queue : " << i.first;
                    while(!queueData.empty()){
                        cout<<queueData.front()<< " ";
                        queueData.pop();
                    }
                    cout<<endl;
                }
                
            }
        }
};

int main(){
    RateLimiter ob(5,5);
    ob.allowRequest("1");
    ob.showQueueData();
    
    RateLimiter ob1(5,5);
    ob1.allowRequest("2");
    ob1.showQueueData();
    
}
