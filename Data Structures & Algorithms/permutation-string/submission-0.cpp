class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> count(256, 0);
        for (auto& c: s1)
            count[c]++;
        int len = s1.size();
        for (int i = 0; i < s2.size(); ++i) {
            int c = s2[i];
            count[c]--;
            if (i - len >= 0)
                count[s2[i - len]]++;
            int j;
            for (j = 0; j < 256 && count[j] == 0; ++j);
            if (j == 256) return true;
        }
        return false;
    }
};
