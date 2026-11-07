class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;
        int i = 0, j = 0;
        int ans = 0;
        while(j < nums.size()){
            total += nums[j];

            while((long long) nums[j] * (j - i + 1) - total > k){
                total -= nums[i];
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};