class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int i = 0, j = 0;
        int res = 0;
        int odds = 0;
        while(j < nums.size()){
            odds += nums[j] % 2;
            while(odds > k){
                odds -= nums[i] % 2;
                i++;
            }
            res += j - i + 1;
            j++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};