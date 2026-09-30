class NumArray {
public:
    vector<int>vec;
    NumArray(vector<int>& nums) {
        vec.push_back(0);
        vec.push_back(nums[0]);
        int curr = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            curr += nums[i];
            vec.push_back(curr);
        }
    }
    
    int sumRange(int left, int right) {
        return vec[right + 1] - vec[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */