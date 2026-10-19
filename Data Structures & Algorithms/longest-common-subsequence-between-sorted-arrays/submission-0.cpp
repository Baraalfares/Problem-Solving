class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int n = arrays.size();
        unordered_map<int,int>mp;
        vector<int>res;
        for(vector<int>nums : arrays){
            for(int num : nums){
                mp[num]++;
                if(mp[num] == n)
                    res.push_back(num);
            }
        }
        return res;
    }
};
