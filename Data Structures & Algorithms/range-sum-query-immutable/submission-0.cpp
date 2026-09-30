class NumArray {
public:
    vector<int>vec;
    NumArray(vector<int>& nums) {
        vec = vector(nums.size() + 1, 0);
        vec[1] = nums[0];
        for(int i = 0 ; i < nums.size(); i++){
            vec[i + 1] = vec[i] + nums[i];
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