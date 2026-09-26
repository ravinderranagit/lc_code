#include <unordered_map>
#include <set>
#include <stdexcept>

class LRUCache {
private:
    int capacity;
    long long clock = 0;
    std::unordered_map<int, std::pair<int, long long>> cache;  // key -> {value, timestamp}
    std::set<std::pair<long long, int>> order;                 // {timestamp, key}

public:
    LRUCache(int capacity) : capacity(capacity) {
        if (capacity <= 0) throw std::invalid_argument("capacity must be positive");
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;

        order.erase({it->second.second, key});   // erase old {timestamp, key}
        it->second.second = ++clock;              // update timestamp
        order.insert({it->second.second, key});   // insert new {timestamp, key}

        return it->second.first;                  // value
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            order.erase({it->second.second, key});
            it->second = {value, ++clock};
            order.insert({it->second.second, key});
            return;
        }

        if (static_cast<int>(cache.size()) >= capacity) {
            auto lru = *order.begin();
            order.erase(order.begin());
            cache.erase(lru.second);
        }

        cache[key] = {value, ++clock};
        order.insert({clock, key});
    }
};
