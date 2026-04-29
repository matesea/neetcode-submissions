class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> count(256, 0);
        int zeros = 256;
        for (auto& c: s1){
            if (!count[c]++)
                zeros--;
        }
        int len = s1.size();
        for (int i = 0; i < s2.size(); ++i) {
            int c = s2[i];
            --count[c];
            zeros += count[c] == 0? 1 : count[c] == -1 ? -1 : 0;
            if (i - len >= 0) {
                int d = s2[i - len];
                ++count[d];
                zeros += count[d] == 0 ? 1 : count[d] == 1 ? -1 : 0;
            }
            if (zeros == 256)
                return true;
        }
        return false;
    }
};
