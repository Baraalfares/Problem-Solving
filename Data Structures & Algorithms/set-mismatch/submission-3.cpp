class Solution {
   public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        int dup = 0;
        for (auto num : nums) {
            if (st.count(num))
                dup = num;
            else
                st.insert(num);
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (st.find(i) == st.end()) {
                return {dup, i};
            }
        }
        return {-1, -1};
    }
};