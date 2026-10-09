class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        int count = 0;
        for(auto it : mp){
            if(it.second == 1)
                return -1;
            if(it.second % 3 == 0){
                count += it.second / 3;
            }
            else {
                count += (it.second / 3) + 1;
            }
        }
        return count;
    }
};