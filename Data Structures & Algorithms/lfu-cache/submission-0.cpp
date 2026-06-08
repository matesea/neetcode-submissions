class LFUCache {
    unordered_map<int,int> cache, freq, used;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    int capacity, timestamp;
public:
    LFUCache(int cap) : capacity(cap) {
       timestamp = 0; 
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        used[key] = timestamp++;
        freq[key]++;
        pq.push({freq[key], used[key], key});
        return cache[key];
    }
    
    void put(int key, int value) {
       // cout << "put " << key << endl;
       if (cache.find(key) == cache.end() && cache.size() == capacity) {
        while (cache.size() >= capacity && pq.size() > 0) {
         vector<int> t = pq.top(); pq.pop();
         int f = t[0], u = t[1], k = t[2];
         if (cache.find(k) != cache.end() && f == freq[k] && u == used[k]) {
             // cout << "erase " << k << endl;
             cache.erase(k);
         }
        }
       }
       cache[key] = value; 
       freq[key]++;
       used[key] = timestamp++;
       pq.push({freq[key], used[key], key});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */