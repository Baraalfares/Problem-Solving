class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        vector<vector<int>> res;
        while (i < n - 2) {
            while (i < n - 2 && i > 0 && nums[i] == nums[i - 1]) {
                i++;
            }
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == 0) {
                    res.push_back({nums[left], nums[right], nums[i]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;

                } else if (sum > 0)
                    right--;
                else
                    left++;
            }
            i++;
        }
        return res;
    }
};
