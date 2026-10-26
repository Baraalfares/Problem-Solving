class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        vector<vector<int>> res;
        while (i < n - 3) {
            while (i < n - 3 && i > 0 && nums[i] == nums[i - 1]) i++;
            int j = i + 1;
            while (j < n - 2) {
                while (j < n - 2 && j > i + 1 && nums[j] == nums[j - 1]) j++;

                int l = j + 1;
                int r = n - 1;

                while (l < r) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        r--;
                        l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                        while (l < r && nums[l] == nums[l - 1]) l++;
                    } else if (sum > target)
                        r--;
                    else
                        l++;
                }
                j++;
            }
            i++;
        }
        return res;
    }
};