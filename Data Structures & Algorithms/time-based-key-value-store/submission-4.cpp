class TimeMap {
    unordered_map<string,vector<pair<int,string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end())
            return "";
        /* implement binary search on my own
        int l = 0, r = m[key].size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (m[key][mid].first == timestamp)
                return m[key][mid].second;
            else if (m[key][mid].first < timestamp)
                l = mid;
            else r = mid-1;
        }
        return m[key][l].first <= timestamp ? m[key][l].second : "";
        */
        
        auto cmp = [](const int& timestamp, const pair<int,string>& p) {
            return timestamp < p.first;
        };
        auto& v = m[key];
        auto it = upper_bound(v.begin(), v.end(), timestamp, cmp);
        // cout << "found " << it->first << "," << it->second << endl;
        if (it == v.begin())
            return "";
        --it;
        if (it->first > timestamp)
            return "";
        return it->second;
    }
};
