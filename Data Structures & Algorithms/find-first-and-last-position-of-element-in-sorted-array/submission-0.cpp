class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int first = -1;
        int second = -1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                first = second = mid;
                break;
            }
            else if(nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }

        if(first == -1)
            return {first, second};

        while(l < first){
            int mid = l + (first - l) / 2;
            if(nums[mid] == target){
                first = mid;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
        }

        while(second + 1 < r){
            int mid = second + (r - second) / 2;
            if(nums[mid] == target){
                second = mid;
            }
            else if(nums[mid] > target){
                r = mid;
            }
        }
        return {first, second};
    }
};