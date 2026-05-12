class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = {i, i};
            }
            m[s[i]].second = i;
        }
        int start = 0, end = m[s[0]].second;
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]].second > end)
                end = m[s[i]].second;
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
