class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = -1;
        int max2 = -1;
        int min1 = 100001;
        int min2 = 100001;
        for(int num : nums){
            if(max1 < num){
                max2 = max1;
                max1 = num;
            }
            else if(num > max2)
                max2 = num;
                
            if(num < min1){
                min2 = min1;
                min1 = num;
            }
            else if(num < min2)
                min2 = num;
        }
        return (max1 * max2) - (min1 * min2);
    }
};