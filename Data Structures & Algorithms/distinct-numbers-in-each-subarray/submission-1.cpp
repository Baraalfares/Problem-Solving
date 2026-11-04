class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        unordered_map<int,int>mp;
        vector<int>res;
        while(j < nums.size()){
            mp[nums[j]]++;

            if(j - i + 1 == k){
                res.push_back(mp.size());
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};
