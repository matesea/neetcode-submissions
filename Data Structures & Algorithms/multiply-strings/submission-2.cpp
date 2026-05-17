class Solution {
   string add(const string& a, const string& b) {
    int carry = 0;
    string res;
    int m = a.size(), n = b.size();
    int i = 0;
    while (i < m || i < n || carry) {
        int digit = (i < m ? a[i] - '0' : 0) + (i < n ? b[i] - '0' : 0) + carry;
        carry = digit / 10;
        digit %= 10;
        res.push_back('0' + digit);
        ++i;
    }
    return res;
   }
   string _multiply(const string& a, char c) {
    int carry = 0;
    string res;
    int i = 0;
    c -= '0';

    while (i < a.size() || carry) {
        int digit = (i < a.size() ? (a[i] - '0') * c : 0) + carry;
        res.push_back('0' + (digit % 10));
        carry = digit / 10;
        ++i;
    }
    return res;
   }
public:
    string multiply(string a, string b) {
        string res;
        if (a.size() > b.size()) swap(a, b);
        if (a == "0" || b == "0") return "0";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < a.size(); ++i) {
            char c = a[i];
            string tmp = string(i, '0') + _multiply(b, c);
            res = add(res, tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
