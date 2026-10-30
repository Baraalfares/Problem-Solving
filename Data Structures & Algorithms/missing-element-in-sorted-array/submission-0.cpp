class Solution {
   public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int missing = nums[mid] - nums[0] - mid;
            if (missing < k)
                l = mid + 1;
            else
                r = mid;
        }
        return nums[0] + k + l - 1;
    }
};
