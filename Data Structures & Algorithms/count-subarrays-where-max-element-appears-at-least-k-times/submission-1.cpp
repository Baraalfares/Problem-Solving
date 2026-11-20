class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxcnt = 0;
        int i = 0, j = 0, n = nums.size();
        long res = 0;
        int maxelement = *max_element(nums.begin(), nums.end());
        while(j < n){
            if(maxelement == nums[j])
                maxcnt++;
            while(i <= j && maxcnt >= k){
                if(nums[i] == maxelement)
                    maxcnt--;
                i++;
            }
            res += i;
            j++;
        }
        return res;
    }
};
