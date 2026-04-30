class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n = position.size(); 
       vector<pair<int,int>> v;
       for (int i = 0; i < n; ++i) {
        v.push_back({position[i],speed[i]});
       }
       sort(v.rbegin(), v.rend());
       int fleets = 1;
       double prevTime = (double)(target - v[0].first) / v[0].second;
       for (int i = 1; i < n; ++i) {
        double currTime = (double)(target - v[i].first) / v[i].second;
        if (currTime > prevTime) {
            fleets++;
            prevTime = currTime;
        }
       }
       return fleets;
    }
};
