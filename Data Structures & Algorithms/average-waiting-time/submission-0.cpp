class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long curr = 0;
        long long total = 0;
        for(auto &customer : customers){
            curr = max(curr, (long long)customer[0]) + customer[1];
            total += curr - customer[0];
        }
        return (double)total / customers.size();
    }
};