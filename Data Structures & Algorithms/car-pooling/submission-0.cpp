class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       map<int,int> m; 
       for (auto& v: trips) {
        m[v[1]] += v[0];
        m[v[2]] -= v[0];
       }
       int people = 0;
       for (auto it = m.begin(); it != m.end(); ++it) {
        people += it->second;
        if (people > capacity) return false;
       }
       return true;
    }
};