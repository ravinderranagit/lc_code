/* 
    Reverse the subarray from the index provided by user
    Eg. array = {1,2,3,4,5,6,7} 
        k = 3
        array = {4,5,6,7,1,2,3}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void show(std::vector<int> vec){
    for(auto i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    std::vector<int> vec = {1,1,10,1,10,10,0,0,1,1,1};
    std::sort(vec.begin(), vec.end());
    show(vec);
    for(size_t i=0; i<vec.size();i++){
        for(size_t k=0; k < vec.size()-1; k++){
            if(vec[k] == vec[k+1]){
                for(size_t j=k; j<vec.size()-1;j++){
                    vec[j] = vec[j+1];
                }
                vec.pop_back();
            } 
        }
    }
    show(vec);
}