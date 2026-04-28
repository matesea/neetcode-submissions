class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (auto& s: strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> res;
        while (i < s.size()) {
            int j = i;
            while (j < s.size() && s[j] != '#')
                ++j;
            int length = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j+1, length));
            i = j + length + 1;
        }
        return res;
    }
};
