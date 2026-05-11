class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<int>> adj(n, vector<int>(n, -1)); 
       for (auto& flight: flights) {
        auto &src = flight[0], &dsc = flight[1], &price = flight[2];
        adj[src][dsc] = price;
       }
       auto cmp = [](const array<int,3>& c1, const array<int,3>& c2) {
        return c1[0] > c1[0];
       };
       priority_queue<array<int, 3>,vector<array<int,3>>,decltype(cmp)> pq(cmp);
       pq.push({0, src, 0});
       vector<int> prices(n, INT_MAX);
       vector<int> steps(n, INT_MAX);
       prices[src] = 0;
       steps[src] = 0;

       while (pq.size() > 0) {
        auto p = pq.top();
        pq.pop();
        int &price = p[0], &city = p[1], &step = p[2];
        // cout << "city: " << city << ", price: " << price << ", step: " << step << endl;
        for (int i = 0; i < n; ++i) {
            if (adj[city][i] < 0)
                continue;
            if (step > k)
                continue;
            if (price + adj[city][i] < prices[i] || price + adj[city][i] == prices[i] && steps[i] > step + 1) {
                prices[i] = price + adj[city][i];
                steps[i] = step + 1;
                pq.push({prices[i], i, steps[i]});
            }
        }
       }
       return (prices[dst] != INT_MAX && steps[dst] <= k+1) ? prices[dst] : -1;
    }
};
