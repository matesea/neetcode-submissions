class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        string res;
        while (i < s.size()) {
            if ('a' <= s[i] && s[i] <= 'z') {
                res += s[i];
                ++i;
            } else if (isdigit(s[i])) {
                int val = 0;
                int j = i;
                while (j < s.size() && isdigit(s[j])) ++j;
                val = stoi(s.substr(i, j - i));

                i = j+1; j = i;
                int count = 1;
                while (j < s.size() && count) {
                    if (s[j] == '[')
                        count++;
                    else if (s[j] == ']')
                        count--;
                    ++j;
                }
                string sub = decodeString(s.substr(i, j - i - 1));
                while (val-- > 0) res += sub;
                i = j;
            }
        }
        return res;
    }
};