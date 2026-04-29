class Solution {
    bool check(vector<int>& count, int k) {
        int mx = 0, total = 0;
        for (auto& c: count) {
            mx = max(mx, c);
            total += c;
        }
        return total - mx <= k;
    }
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        vector<int> count(26, 0);
        int res = 0;
        for (int j = 0; j < s.size(); ++j) {
            count[s[j] - 'A']++;
            while (!check(count, k)) {
                count[s[i] - 'A']--;
                ++i;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
