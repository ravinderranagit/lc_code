#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;

    // {key, value}
    list<pair<int, int>> cache;

    // key -> iterator pointing to the key's position in list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return -1;

        // Get iterator to the node
        auto it = mp[key];

        int value = it->second;

        // Move this key to front (most recently used)
        cache.splice(cache.begin(), cache, it);

        return value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            auto it = mp[key];

            // Update value
            it->second = value;

            // Move to front
            cache.splice(cache.begin(), cache, it);

            return;
        }

        // If cache is full, remove LRU item
        if (cache.size() == capacity) {

            auto lru = cache.back();

            mp.erase(lru.first);
            cache.pop_back();
        }

        // Insert new item at front
        cache.push_front({key, value});

        // Store iterator in map
        mp[key] = cache.begin();
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl;  // 10

    cache.put(3, 30);              // Removes key 2

    cout << cache.get(2) << endl;  // -1
    cout << cache.get(3) << endl;  // 30

    cache.put(4, 40);              // Removes key 1

    cout << cache.get(1) << endl;  // -1
    cout << cache.get(3) << endl;  // 30
    cout << cache.get(4) << endl;  // 40

    return 0;
}
