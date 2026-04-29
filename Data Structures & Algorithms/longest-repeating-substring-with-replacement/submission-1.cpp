class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        vector<int> count(26, 0);
        int res = 0;
        int maxF = 0;
        for (int j = 0; j < s.size(); ++j) {
            count[s[j] - 'A']++;
            maxF = max(maxF, count[s[j] - 'A']);
            while ((j - i + 1 - maxF) > k) {
                count[s[i] - 'A']--;
                ++i;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
