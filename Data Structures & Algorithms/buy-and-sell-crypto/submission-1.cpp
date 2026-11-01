class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, i = 0;
        int maxi = 0;
        while(i < prices.size()){
            while(i < prices.size() && prices[i] >= prices[l]){
                maxi = max(maxi, prices[i] - prices[l]);
                i++;
            }
            l = i;
            i++;
        }
        return maxi;
    }
};
