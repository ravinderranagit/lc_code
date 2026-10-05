#include<iostream>
using namespace std;

bool isPalindrome(string str){
    for(int i=0, j = str.length()-1; i<str.length()/2; i++){
        if(str[i] != str[j]){
            return false;
        }
        j--;
    }
    return true;
}

int main(){
    string str = "radar";
    if(isPalindrome(str)){
        cout << "YES!" << endl;
    } else {
        cout << "NO!" << endl;
    }
}