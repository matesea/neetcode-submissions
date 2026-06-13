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
public:
    int findInMountainArray(int target, MountainArray &m) {
        int l = 0, r = m.length() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            int val = m.get(mid);
            int val1 = m.get(mid+1);
            if (val < val1)
                l = mid;
            else r = mid - 1;
        }
        int peak = l + 1;
        l = 0, r = peak;
        // cout << "peak=" << peak << endl;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = m.get(mid);
            if (val == target)
                return mid;
            else if (val < target)
                l = mid + 1;
            else r = mid - 1;
        }
        l = peak, r = m.length() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = m.get(mid);
            if (val == target)
                return mid;
            else if (val > target)
                l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};