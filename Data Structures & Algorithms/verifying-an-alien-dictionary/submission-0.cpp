class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> idx(26, 0);
        for (int i = 0; i < order.size(); ++i) {
            idx[order[i] - 'a'] = i;
        }

        for (int i = 0; i + 1 < words.size(); ++i) {
            int j = 0;
            while (j < words[i].size() && j < words[i+1].size() && words[i][j] == words[i+1][j])
                ++j;
            if (j >= words[i].size())
                return j < words[i+1].size();
            if (j >= words[i+1].size())
                return false;
            if (idx[words[i][j] - 'a'] > idx[words[i+1][j] - 'a'])
                return false;
        }
        return true;
    }
};