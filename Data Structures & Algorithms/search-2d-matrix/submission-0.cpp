class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix.front().size();
        int l = 0, r = m*n-1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid/n][mid%n] < target)
                l = mid+1;
            else r = mid;
        }
        return matrix[l/n][l%n] == target;
    }
};
