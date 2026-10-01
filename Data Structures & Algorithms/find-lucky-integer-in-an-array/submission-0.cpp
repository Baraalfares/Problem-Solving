class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501] = {0};
        for(int num : arr){
            freq[num]++;
        }
        int maxi = -1;
        for(int num : arr){
            if(num == freq[num]){
                maxi = max(maxi, num);
            }
        }
        return maxi;
    }
};