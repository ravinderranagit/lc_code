#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


void showUsingIndex(vector<int> v){
    for(int i=0; i< v.size(); i++){
        cout<<v[i]<< " " ;
    }
    cout<<endl;
}

void showUsingIterator(vector<int> v){
    for( auto it = v.begin(); it < v.end(); ++it){
        cout<< *it << " ";
    }
    cout<<endl;
}

void showUsingFor(vector<int> v){
    for(auto i: v){
        cout << i << " ";
    }
    cout<<endl;
}

int main(){
    
    vector<int> v = {1,2,3,4,5};
    // using index
    showUsingIndex(v);
    
    // using iterator
    showUsingIterator(v);
    
    // using for loop
    showUsingFor(v);
    
    v.push_back(7);
    showUsingIterator(v);

    //size of vector
    cout << "size of vector v : " << v.size() << endl;

    // capacity of vector v
    cout << "capacity of vector v : " << v.capacity() << endl;
    
    // push_back creates a temporary object to push
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    // emplace_back will create object at vector itself. No temp object required
    v.emplace_back(11);
    v.emplace_back(12);

    showUsingIterator(v);
    
    //size of vector
    cout << "size of vector v : " << v.size() << endl;

    // capacity of vector v
    cout << "capacity of vector v : " << v.capacity() << endl;

    // pop_back
    v.pop_back();
    showUsingIterator(v);
    
    // sort
    sort(v.begin(), v.end(), greater<int>());
    showUsingIterator(v);

    // reverse
    reverse(v.begin(), v.end());
    showUsingIterator(v);

    // count
    cout << count(v.begin(), v.end(), 5) << endl;
    v.push_back(5);
    cout << count(v.begin(), v.end(), 5) << endl;

    // min/max
    cout<< "Minimum element : " << *min_element(v.begin(), v.end()) << endl;
    cout<< "Maximum element : " << *max_element(v.begin(), v.end()) << endl;

}
