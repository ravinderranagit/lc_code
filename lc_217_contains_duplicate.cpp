#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution
{
    public:
        bool finDup(vector<int>& vec)
        {
            unordered_set<int> seen;
            for(auto num : vec){
                if(seen.find(num) != seen.end()){
                    return true;
                } else{
                    seen.insert(num);
                }
            }
            return false;
        }
};

int main()
{
    vector<int> vec = {1,2,3,4,5,1};
    Solution A;
    if(A.finDup(vec))
    {
        cout << "true" << endl;
    } 
    else 
    {
        cout<<"false"<<endl;
    }
}
