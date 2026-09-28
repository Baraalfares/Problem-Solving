class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 1 -> 8 -> 11 -> 17 -> 22 -> 28
        int right = 0;
        int left = 0;
        int total = 0;
        for(int num : nums){
            total += num;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            right = total - left - nums[i];
            if(right == left)
                return i;
            left += nums[i];
        }
        return -1;
    }
};