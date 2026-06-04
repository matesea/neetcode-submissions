class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int start = 0, count = 0, tmp;
        while (count < n) {
            int i = start;
            tmp = nums[start];
            do {
                int next = (i + k) % n;
                // tmp = nums[next];
                int tmp2 = nums[next];
                nums[next] = tmp;
                tmp = tmp2;
                i = next;
                ++count;
            } while (i != start);
            ++start;
        }
    }
};