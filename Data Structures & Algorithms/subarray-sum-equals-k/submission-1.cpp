class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int curr = 0;
        int count = 0;
        for(int num : nums){
            curr += num;
            if(mp.find(curr - k) != mp.end())
                count += mp[curr - k]; 
            mp[curr]++;
        }
        return count;
    }
};