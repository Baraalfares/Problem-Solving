class Solution {
   public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        int i = 0, j = 0, n = nums.size();
        long long sum = 0;
        long long ans = 0;
        while (j < n) {
            counts[nums[j]]++;
            sum += nums[j];
            if (j - i + 1 == k) {
                if(counts.size() == k)
                    ans = max(ans, sum);
                sum -= nums[i];
                counts[nums[i]]--;
                if(counts[nums[i]] == 0)
                    counts.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
