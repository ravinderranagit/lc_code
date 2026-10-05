// Sume of three consecutive values and return max sum
#include<iostream>
using namespace std;

int threeConsecutiveValSum(int arr[], int window, int size){
    int maxSum = 0;
    int sum = 0;
    for(int i = 0; i < window; i++){
        sum += arr[i];
    }
    maxSum = sum;
    for(int k = window; k < size; k++){
        sum += arr[k];
        sum -= arr[k - window];    
    }
    
    return (maxSum = max(maxSum, sum));
}

int main(){
    int arr[] = {10,8,15,5,6,1};
    int window = 3;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << threeConsecutiveValSum(arr, window, size);
}