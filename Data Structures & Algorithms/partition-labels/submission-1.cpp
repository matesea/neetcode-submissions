class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
        }
        int start = 0, end = m[s[0]];
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] > end)
                end = m[s[i]];
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};
