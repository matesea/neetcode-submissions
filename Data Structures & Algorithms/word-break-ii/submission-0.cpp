class Solution {
    vector<string> res;
    void backtrack(string& s, int i, vector<string>& dictionary, vector<string>& current) {
        if (i == s.size()) {
            string r;
            for (auto& c: current)
                r += c + " ";
            r.pop_back();
            res.push_back(r);
            return;
        }
        for (auto& w: dictionary) {
            if (i + w.size() > s.size())
                continue;
            if (s.substr(i, w.size()) == w) {
                current.push_back(w);
                backtrack(s, i + w.size(), dictionary, current);
                current.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       vector<string> current; 
       sort(wordDict.begin(), wordDict.end(), [](const string& a, const string& b) -> bool {
        return a.size() > b.size();
       });
       backtrack(s, 0, wordDict, current);
       return res;
    }
};