class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long count = 0;
        vector<int>diff;
        for(int i = 0 ; i < n ; i++){
            diff.push_back(nums1[i] - nums2[i]);
        }
        sort(diff.begin(), diff.end());
        int left = 0;
        int right = n - 1;
        while(left < right){
            if(diff[left] + diff[right] > 0){
                count += right - left;
                right--;
            }
            else
                left++;
        }
        return count;
    }
};