class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int j = 0;
        unordered_map<int,int>mp;
        while(j < nums.size()){
            if(mp.count(nums[j])){
                if(j - mp[nums[j]] <= k)
                    return true;
            }
            mp[nums[j]] = j;
            j++;
        }
        return false;
    }
};