class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        int maxFreq = 0, maxIdx = 0;
        for (auto& c: s) {
            count[c - 'a']++;
            if (count[c-'a'] > maxFreq) {
                maxFreq = count[c-'a'];
                maxIdx = c - 'a';
            }
        }
        if (maxFreq > (s.size() + 1) >> 1)
            return "";
        string res(s.size(), ' ');
        int idx = 0;
        while (count[maxIdx] > 0) {
            res[idx] = 'a'+maxIdx;
            idx += 2;
            count[maxIdx]--;
        }
        for (int i = 0; i < 26; ++i) {
            while (count[i] > 0) {
                if (idx >= s.size())
                    idx = 1;
                res[idx] = 'a'+i;
                idx += 2;
                count[i]--;
            }
        }
        return res;
    }
};