class Solution {
   public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int i = 0;
        int j = 0, n = nums.size();
        vector<int> ans;
        int count = 1;
        while (j < n) {
            if (j > 0 && nums[j] == nums[j - 1] + 1)
                count++;
            else if (j > 0 && nums[j] != nums[j - 1] + 1)
                count = 1;

            if (j - i + 1 == k) {
                if (count >= k)
                    ans.push_back(nums[j]);
                else
                    ans.push_back(-1);
                i++;
            }
            j++;
        }
        return ans;
    }
};
