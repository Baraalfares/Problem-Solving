class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int j = 1;
        int res = 0;
        for(int i = 1 ; i < colors.size() ; i++){
            if(colors[i] == colors[i - 1]){
                if(neededTime[j] > neededTime[j - 1]){
                    res += neededTime[j - 1];
                }
                else{
                    res += neededTime[j];
                    colors[i] = colors[i - 1];
                    neededTime[j] = neededTime[j - 1];
                }
            }
            j++;
        }
        return res;
    }
};
