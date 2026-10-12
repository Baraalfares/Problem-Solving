class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0;
        int down = matrix.size() - 1;
        int idx = 0;
        while(up <= down){
            int mid = up + (down - up) / 2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] <= target && matrix[mid].back() >= target){
                idx = mid;
                break;
            }
            else if(matrix[mid][0] > target){
                down = mid - 1;
            }
            else
                up = mid + 1;
        }
        int left = 0;
        int right = matrix[idx].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(matrix[idx][mid] == target)
                return true;
            if(matrix[idx][mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};
