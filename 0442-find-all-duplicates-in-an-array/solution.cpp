class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        for(int i = 0 ; i < nums.size() ; i++){
            int val = abs(nums[i]);
            int idx = val - 1;
            if(nums[idx] > 0){
                nums[idx] *= -1;
            }
            else{
                res.push_back(val);
            }
        }
        return res;
    }
};