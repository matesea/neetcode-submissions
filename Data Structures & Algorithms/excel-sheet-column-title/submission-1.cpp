class Solution {
public:
    string convertToTitle(int columnNumber) {
       string res; 
       while (columnNumber > 0) {
        res += ('A' + ((columnNumber - 1) % 26));
        columnNumber = (columnNumber-1) / 26;
       }
       reverse(res.begin(), res.end());
       return res;
    }
};