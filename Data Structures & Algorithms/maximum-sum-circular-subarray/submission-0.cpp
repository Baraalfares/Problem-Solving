class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int curmax = 0, maxsum = nums[0];
        int curmin = 0, minsum = nums[0];
        
        for(int num : nums){
            total += num;
            curmax = max(num, curmax + num);
            maxsum = max(maxsum, curmax);

            curmin = min(num, curmin + num);
            minsum = min(minsum, curmin);
        }
        if(maxsum < 0)
            return maxsum;
        return max(maxsum, total - minsum);
    }
};