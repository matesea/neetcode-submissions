class LRUCache {
    unordered_map<int,pair<int,list<int>::iterator>> cache;
    list<int> order;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = prev(order.end());
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
        } else if (cap == cache.size()) {
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, prev(order.end())};
    }
};
