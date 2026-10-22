class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int i = 0, left = 0, j = n - 1, right = n - 1;
        vector<int>result(n , pivot);

        while(i < n && j >= 0){
            if(nums[i] < pivot)
                result[left++] = nums[i];
            if(nums[j] > pivot)
                result[right--] = nums[j];
            i++;
            j--;
        }
        return result;
    }
};
