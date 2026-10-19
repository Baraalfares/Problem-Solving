class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int equal = 0;
        vector<int>res;
        for(int num : nums){
            if(num < target)
                count++;
            else if(num == target)
                equal++;
        }
        while(equal--){
            res.push_back(count);
            count++;
        }
        return res;
    }
};