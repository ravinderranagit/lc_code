#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    // O(1);
    cout << "O(1) : ";
    cout<< arr[0] << endl;

    // O(n)
    cout << "O(n) : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;

    // O(logn);
    cout << "O(logn) : ";
    for(int i=0; i< n/2; i++){
        cout << arr[i];
    }
    cout<<endl;

    // O(n logn)
    cout << "O(n logn) :";
    // O(n)
    for(int i = 0; i < n; i++){
        // O(log n)
        for(int j = n-1; j > 1; j /=2 ){
            cout << arr[j] << " ";
        }
    }
    cout<<endl;

    // O(n^2)
    cout << "O(n^2) :";
    // O(n)
    for(int i=0; i<n; i++){
        // O(n)
        for(int j = i; j < n; j++){
            cout << arr[j] << " ";
        }
        // O(n*n) =  O(n^2)
        cout<<endl;
    }

}