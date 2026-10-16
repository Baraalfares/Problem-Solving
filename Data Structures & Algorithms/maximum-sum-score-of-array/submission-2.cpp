class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefix(n + 1, 0);
        long long total = 0;
        long long maxi = INT_MIN;
        for(int i = 0; i < nums.size() ; i++){
            prefix[i + 1] = nums[i] + prefix[i];
        }
        for(int i = 1 ; i < n + 1; i++){
            long long sum1 = prefix[i];
            long long sum2 = LLONG_MIN;
            sum2 = prefix[n] - prefix[i - 1];
            maxi = max(max(sum2, sum1), maxi);
        }
        return maxi;
    }
};