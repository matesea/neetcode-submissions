class MyHashSet {
    int prime;
    vector<list<int>> cache;
    int hash(int x) {return x % prime;}
    list<int>::iterator search(int key) {
        int h = hash(key);
        return find(cache[h].begin(), cache[h].end(), key);
    }
public:
    MyHashSet() {
       prime = 10007; 
       cache.resize(prime);
    }
    
    void add(int key) {
       if (contains(key)) return;
       cache[hash(key)].push_back(key);
    }
    
    void remove(int key) {
       if (!contains(key)) return; 
       int h = hash(key);
       cache[h].erase(search(key));
    }
    
    bool contains(int key) {
        int h = hash(key);
        return search(key) != cache[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */