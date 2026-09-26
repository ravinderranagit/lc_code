#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> findSumOfTarget(vector<int>& vec, int target){
    unordered_map<int,int> seen;
    for(int i=0; i<vec.size(); i++){
        int checkVal = target - vec[i];
        if(seen.find(checkVal) != seen.end()){
            return {i, }
        }
    }
}

int main(){


}
