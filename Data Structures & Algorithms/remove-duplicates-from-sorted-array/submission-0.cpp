class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            nums[k] = nums[i];
            while (i < n && nums[i] == nums[k]) {
                i++;
            }
            k++;
        }
        return k;
    }
};