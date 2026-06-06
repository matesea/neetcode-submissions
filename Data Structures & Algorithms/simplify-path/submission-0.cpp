class Solution {
    string join(vector<string>& s, string delimiter) {
        string res;
        for (auto& ss: s) {
            res += delimiter + ss;
        }
        return res.size() > 0 ? res : "/";
    }
public:
    string simplifyPath(string path) {
        stringstream s(path);
        string val;
        vector<string> ss;
        while (getline(s, val, '/')) {
            if (val == "" || val == "/" || val == ".") {
                continue;
            } else if (val == "..") {
                if (ss.size() > 0) ss.pop_back();
             } else 
                ss.push_back(val);
        }
        return join(ss, "/");
    }
};