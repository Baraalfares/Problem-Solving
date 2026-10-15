class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        mp[0] = 1;
        int count = 0;
        int sum = 0;

        for(int num : nums){
            sum += num;
            int rem = (sum % k + k) % k;
            if(mp.count(rem))
                count += mp[rem];
            mp[rem]++;
        }
        return count;
    }
};