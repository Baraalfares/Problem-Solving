class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum = nums[0];
        int maxi = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            if(cursum < 0)
                cursum = nums[i];
            else
                cursum += nums[i];
            maxi = max(maxi, cursum);
        }
        return maxi;
    }
};
