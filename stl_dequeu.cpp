#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;


void showUsingIndex(deque<int> l){
    for(int i=0; i<l.size(); i++){
        cout << l[i] << " ";
    }
    cout<<endl;
}


void showUsingIterator(deque<int> l){
    for(auto it = l.begin(); it != l.end(); ++it){
        cout << *it << " ";
    }
    cout<<endl;
}


void showUsingFor(deque<int> l){
    for(auto i : l){
        cout << i << " ";
    }
    cout<<endl;
}



int main(){
    deque<int> l = {1,2,3,4,5};
    // using index
    showUsingIndex(l);
    
    // Using Iterator
    showUsingIterator(l);

    // Using For loop
    showUsingFor(l);

    // insert value in list
    l.push_back(6);
    showUsingFor(l);

    // insert in front
    l.push_front(7);
    showUsingFor(l);
   
    // emplace back
    l.emplace_back(8);
    showUsingFor(l);

    //pop front
    l.pop_front();
    showUsingFor(l);
    
    // pop back
    l.pop_back();
    showUsingFor(l);

    //sort descending
    sort(l.begin(), l.end(), greater<int>());
    showUsingFor(l);

    //sort
    sort(l.begin(), l.end());
    showUsingFor(l);

    // count
    cout << count(l.begin(), l.end(), 5) << endl;

    //max/min
    cout << "Max value : " << *max_element(l.begin(),l.end()) << endl;
    cout << "Min value : " << *min_element(l.begin(),l.end()) << endl;

    // reverse
    reverse(l.begin(), l.end());
    showUsingFor(l);
}
   
