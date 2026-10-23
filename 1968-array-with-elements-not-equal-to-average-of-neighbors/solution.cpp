class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(i % 2 == 0 && nums[i - 1] < nums[i]
            || i % 2 == 1 && nums[i - 1] > nums[i]){
                swap(nums[i - 1], nums[i]);
            }
        }
        return nums;
    }
};