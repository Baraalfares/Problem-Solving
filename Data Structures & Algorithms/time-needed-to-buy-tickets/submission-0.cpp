class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count = 0;
        int target = tickets[k];
        for(int i = 0 ; i < tickets.size() ; i++){
            if(i <= k){
                count += min(tickets[i], target);
            }
            else
                count += min(tickets[i], target - 1);
        }
        return count;
    }
};