class MyHashMap {
    const int prime = 10007;
    vector<list<pair<int,int>>> cache;
    int hash(int key) {return key % prime;}
    list<pair<int,int>>::iterator search(int key) {
        int h = hash(key);
        auto it = cache[h].begin();
        while (it != cache[h].end())
            if (it->first == key)
                break;
        return it;
    }
public:
    MyHashMap() {
       cache.resize(prime);
    }
    
    void put(int key, int value) {
        auto it = search(key);
        int h = hash(key);
        if (it == cache[h].end()) {
            cache[h].push_back({key, value});
            return;
        }
        it->second = value;
    }
    
    int get(int key) {
        auto it = search(key);
        int h = hash(key);
        if (it == cache[h].end())
            return -1;
        return it->second;
    }
    
    void remove(int key) {
        auto it = search(key);
        int h = hash(key);
        if (it == cache[h].end()) return;
        cache[h].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */