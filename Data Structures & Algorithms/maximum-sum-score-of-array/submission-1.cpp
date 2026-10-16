class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefix(n, 0);
        long long total = 0;
        long long maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            total += nums[i];
            prefix[i] = total;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            long long sum1 = prefix[i];
            long long sum2 = LLONG_MIN;
            if(i != 0)
                sum2 = prefix[n - 1] - prefix[i - 1];
            if(i == 0)
                sum2 = prefix[n - 1];
            
            maxi = max(max(sum2, sum1), maxi);
        }
        return maxi;
    }
};
