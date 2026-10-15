class Solution {
   public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp;
        int n = nums.size();
        mp[0] = -1;
        long long total = 0;
        int cursum = 0;
        int mini = 100001;
        for(int &num : nums){
            total += num;
        }
        int remove = total % p; // we need to remove subarray with this reminder so we get 0;
        if(remove == 0)
            return 0;
        for(int i = 0; i < n; i++){
            cursum = (cursum + nums[i]) % p;
            int need = (cursum - remove + p) % p;
            if(mp.count(need))
                mini = min(mini, i - mp[need]);
            mp[cursum] = i;
        }
        return mini >= nums.size() ? -1 : mini;
    }
};