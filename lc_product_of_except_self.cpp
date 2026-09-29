#include<iostream>
#include<vector>

using namespace std;

void leftProd(vector<int> nums, vector<int>& answer){
    int leftProdVal=1;
    for(int i=0; i<nums.size(); i++){
        leftProdVal=1;
        for(int j=0; j<i; j++){
            leftProdVal = leftProdVal*nums[j];
        }
        answer.push_back(leftProdVal);
    }
}

void rightProd(vector<int> nums, vector<int>& answer){
    int rightProdVal=1;
    for(int i=nums.size()-1; i>=0; i--){
        rightProdVal=1;
        for(int j=nums.size()-1; j>i; j--){
            rightProdVal = rightProdVal * nums[j];
        }
        answer[i] = answer[i] * rightProdVal;
    }
}

int main(){
    vector<int> nums = {1,2,3,4};
    vector<int> answer;
    leftProd(nums,answer);
    rightProd(nums,answer);
    for(auto num : answer){
        cout << num << " ";
    }
    cout<<endl;
    return 0;
}
