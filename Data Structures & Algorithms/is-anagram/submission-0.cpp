class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int> count(256, 0); 
       for (auto& c: s)
        count[c]++;
        for (auto& c: t)
            count[c]--;
        for (auto& c: count)
            if (c > 0 || c < 0)
                return false;
        return true;
    }
};
