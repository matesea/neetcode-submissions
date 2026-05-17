class Solution {
public:
    string multiply(string n1, string n2) {
       if (n1 == "0" || n2 == "0") return "0";
       reverse(n1.begin(), n1.end());
       reverse(n2.begin(), n2.end());
       vector<int> res(n1.size() + n2.size(), 0);
       for (int i1 = 0; i1 < n1.size(); i1++) {
        for (int i2 = 0; i2 < n2.size(); ++i2) {
            res[i1+i2] += (n1[i1] - '0') * (n2[i2] - '0');
            res[i1+i2+1] += res[i1+i2] / 10;
            res[i1+i2] %= 10;
        }
       }
       int i = res.size() - 1;
       string s;
       while (i >= 0 && res[i] == 0) --i;
       while (i >= 0) {
        s += ('0' + res[i--]);
       }
       return s;
    }
};
