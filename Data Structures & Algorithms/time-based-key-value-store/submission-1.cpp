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
        /*
        vector<pair<int,string>>::iterator it = upper_bound(m[key].begin(), m[key].end(), {timestamp, ""});
        --it;
        if (it->first > timestamp)
            return "";
        return it->second;
        */
    }
};
