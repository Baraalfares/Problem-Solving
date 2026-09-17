class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>dups;
        for(int num : nums){
            if(!dups.insert(num).second)
                return true;
        }
        return false;
    }
};