// find occurance of element in an array

#include<iostream>
#include<unordered_map>
#include<algorithm>

using  namespace std;

// traditional way
void findOccurance(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int occurance = 1;
        int temp = arr[i];
        while(arr[i] == arr[i+1]){
            ++occurance;
            ++i;
        }
        cout << temp << "'s occurrance count is : " << occurance << endl;

    }
}

// using hash (unordered_map) 
void findOccuranceUsingMap(int arr[], int size){
    unordered_map<int, int> mp;
    for(int i=0; i<size; i++){
        ++mp[arr[i]];
    }
    for(auto [key, value] : mp){
        cout << "Element "<< key << " is occurred : " << value << " times" << endl;
    }  
} 

int main(){
    int arr[] = {1,22,5,6,33,8,22,5};
    int size = sizeof(arr)/ sizeof(arr[0]);
    sort(begin(arr), end(arr));
    for( auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    findOccurance(arr, size);
    findOccuranceUsingMap(arr, size);
}
