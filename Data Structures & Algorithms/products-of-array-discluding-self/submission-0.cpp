class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix;
        vector<int> suffix(n , 0);
        int prod = 1;
        for (int num : nums) {
            prefix.push_back(prod);
            prod *= num;
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = prod;
            prod *= nums[i];
        }
        for (int i = 0; i < n; i++) {
            prefix[i] *= suffix[i];
        }
        return prefix;
    }
};
