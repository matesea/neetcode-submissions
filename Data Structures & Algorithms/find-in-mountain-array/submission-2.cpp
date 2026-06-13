/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    vector<int> cached;
    int get(int x, MountainArray &m) {
        if (x < cached.size() && cached[x] != -1)
            return cached[x];
        return cached[x] = m.get(x);
    }
public:
    int findInMountainArray(int target, MountainArray &m) {
        int n = m.length();
        cached.resize(n, -1);
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            int val = get(mid, m);
            int val1 = get(mid+1, m);
            if (val < val1)
                l = mid;
            else r = mid - 1;
        }
        int peak = l + 1;
        l = 0, r = peak;
        // cout << "peak=" << peak << endl;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = get(mid, m);
            if (val == target)
                return mid;
            else if (val < target)
                l = mid + 1;
            else r = mid - 1;
        }
        l = peak, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = get(mid, m);
            if (val == target)
                return mid;
            else if (val > target)
                l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};