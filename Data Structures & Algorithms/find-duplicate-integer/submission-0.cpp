class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        for(int num : nums){
            int val = abs(num);
            int idx = val - 1;
            if(nums[idx] > 0)
                nums[idx] *= -1;
            else
                return val;
        }
        return -1;
    }
};
