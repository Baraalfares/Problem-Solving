class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        vector<int>vec(1001, 0);
        int mx = -1;
        for(int num : nums){
            vec[num]++;
        }
        for(int i = vec.size() - 1; i >= 0 ; i--){
            if(vec[i] == 1)
                return i;
        }
        return -1;
    }
};
