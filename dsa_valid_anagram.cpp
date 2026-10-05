// Valid anagram

#include<iostream>
#include<unordered_map>
#include<algorithm>

using  namespace std;

bool findAnagram(string str, string input){
    unordered_map<char, int> mp;
    for(auto i : str){
        mp[i]++;
    }
    for(auto k : input){
        mp[k]--;
    }
    for( auto [key, value] : mp){
        if(value != 0){
            return false;
        }
    }
    return true;
}

int main(){
    std::string str = "silent";
    std::string input;
    getline(cin, input);
    if(findAnagram(str, input)){
        cout << "Valid Anagram!!" << endl;
    } else {
        cout << "Invalid Anagram!!" << endl;
    }
}
