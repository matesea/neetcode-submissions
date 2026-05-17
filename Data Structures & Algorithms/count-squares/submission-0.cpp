class CountSquares {
    unordered_map<int,unordered_map<int,int>> mp;
    unordered_set<int> mx, my;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
        mx.insert(point[0]);
        my.insert(point[1]);
    }
    
    int count(vector<int> point) {
       int x = point[0], y = point[1];
       int res = 0;
       if (mx.find(x) == mx.end() || my.find(y) == my.end()) return 0;
       for (auto& px: mx) {
        if (px == x) continue;
        if (mp[px].find(y) == mp[px].end()) continue;
        int d = abs(px - x);
        res += mp[px][y] * (mp[px][y-d] * mp[x][y-d] + mp[px][y+d] * mp[x][y+d]);
       }
       return res;
    }
};
