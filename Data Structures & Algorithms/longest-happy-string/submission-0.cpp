class Solution {
    string help(int a, char aa, int b, char bb, int c, char cc) {
        if (a < b)
            return help(b, bb, a, aa, c, cc);
        if (b < c)
            return help(a, aa, c, cc, b, bb);
        if (!b)
            return string(min(2, a), aa);
        int usea = min(2, a);
        int useb = (a - usea >= b) ? 1 : 0;
        string res = string(usea, aa) + string(useb, bb);
        return res + help(a - usea, aa, b - useb, bb, c, cc);
    }
public:
    string longestDiverseString(int a, int b, int c) {
        return help(a, 'a', b, 'b', c, 'c');
    }
};