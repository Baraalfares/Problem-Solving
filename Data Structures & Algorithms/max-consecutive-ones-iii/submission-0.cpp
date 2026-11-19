class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int ones = 0, zeros = 0, n = nums.size();
        int ans = 0;
        while(j < n){
            if(nums[j] == 0)
                zeros++;
            while(i <= j && zeros > k){
                if(nums[i] == 0)
                    zeros--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};