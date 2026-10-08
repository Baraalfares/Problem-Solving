class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = -1;
        int rem = 0;
        for(int i = 0 ; i < nums.size(); i++){
            rem = (rem + nums[i]) % k;
            if(mp.count(rem)){
                if(i - mp[rem] >= 2)
                    return true;
            }
            else{
                mp[rem] = i;
            }
        }
        return false;
    }
};