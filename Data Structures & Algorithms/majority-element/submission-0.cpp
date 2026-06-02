class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count = 0;
       int element; 
       for (auto& x: nums) {
        if (count == 0) {
            element = x;
            count++;
        } else {
            count += (element == x ? 1 : -1);
        }
       }
       return element;
    }
};