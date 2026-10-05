#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void showUsingIndex(list<int> l){
    cout << "List has no index Access because it is not continous. List is doubly linked list which has scatterd memory" << endl;
}


void showUsingIterator(list<int> l){
    for(auto it = l.begin(); it != l.end(); ++it){
        cout << *it << " ";
    }
    cout<<endl;
}


void showUsingFor(list<int> l){
    for(auto i : l){
        cout << i << " ";
    }
    cout<<endl;
}

int main(){
    list<int> l = {1,2,3,4,5};
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
    l.sort(greater<int>());
    showUsingFor(l);

    //sort
    l.sort();
    showUsingFor(l);

    // count
    cout << count(l.begin(), l.end(), 5) << endl;

    //max/min
    cout << "Max value : " << *max_element(l.begin(),l.end()) << endl;
    cout << "Min value : " << *min_element(l.begin(),l.end()) << endl;

    // reverse
    l.reverse();
    showUsingFor(l);
    
    //insert at any position
    auto it = l.begin();
    l.insert(it,4);
    showUsingFor(l);

    //erase
    it = l.begin();
    l.erase(it);
    showUsingFor(l);


    // erase multiple
    auto first = l.begin();
    auto last = l.end();
    advance(first,1);
    advance(last, 4);

    l.erase(first,last);
    showUsingFor(l);

    return 0;
}


