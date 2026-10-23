class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxi = 0;
        while(left < right){
            int prod = min(heights[left], heights[right]) * (right - left);
            maxi = max(prod, maxi);
            if(heights[left] < heights[right]){
                left++;
            }
            else
                right--;
        }
        return maxi;
    }
};
