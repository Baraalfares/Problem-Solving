class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int>lefth(n), righth(n);

        lefth[0] = height[0];
        for(int i = 1 ; i < n ; i++){
            lefth[i] = max(lefth[i - 1], height[i]);
        }
        righth[n - 1] = height[n - 1];
        for(int i = n - 2 ; i >= 0 ; i--){
            righth[i] = max(righth[i + 1], height[i]);
        }
        
        for(int i = 0 ; i < n ; i++){
            ans += min(righth[i], lefth[i]) - height[i];
        }
        return ans;
    }
};
