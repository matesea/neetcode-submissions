class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        vector<int> count(256, 0);
        int matched_chars = 0;
        for (auto& c: t) {
            count[c]--;
            if (count[c] == -1)
                matched_chars--;
        }
        int i = 0, j = 0;
        string res = "";
        for (j = 0; j < s.size(); ++j) {
            char& c = s[j];
            count[c]++;
            if (count[c] == 0)
                matched_chars++;
            while (matched_chars == 0) {
                if (res.size() == 0 || (j - i + 1 < res.size()))
                    res = s.substr(i, j - i + 1);
                count[s[i]]--;
                if (count[s[i]] == -1)
                    matched_chars--;
                i++;
            }
        }
        return res;
    }
};
