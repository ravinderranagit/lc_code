// find occurance of element in an array

#include<iostream>
#include<unordered_set>
#include<algorithm>

using  namespace std;

int duplicate(int arr[], int size){
    unordered_set<int> dup;
    for(int i = 0; i < size; i++){
        if(dup.count(arr[i])){
            return arr[i];
        }
        dup.insert(arr[i]);
    }
}

int main(){
    int arr[] = {1,22,5,6,33,8,22,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "First duplicate : " << duplicate(arr, size) << endl;
}
