class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>pow(n , 1);
        int MOD = 1000000007;

        for(int i = 1 ; i < n ; i++){
            pow[i] = (2LL * pow[i - 1]) % MOD;
        }
        int l = 0;
        int r = n - 1;
        long long count = 0;
        while(l <= r){
            int sum = nums[l] + nums[r];
            if(sum > target)
                r--;
            else{
                count = (count + pow[r - l]);
                l++;
            }
        }
        return count % MOD;
    }
};