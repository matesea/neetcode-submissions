class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n = position.size(); 
       vector<pair<int,int>> v;
       for (int i = 0; i < n; ++i) {
        v.push_back({position[i],speed[i]});
       }
       sort(v.rbegin(), v.rend());
       vector<double> s;
       for (auto& p: v) {
        s.push_back((double)(target - p.first) / p.second);
        if (s.size() > 1 && s.back() <= s[s.size() - 2]) {
            s.pop_back();
        }
       }
       return s.size();
    }
};
