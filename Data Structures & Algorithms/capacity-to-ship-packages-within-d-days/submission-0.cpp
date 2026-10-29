class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());

        while(low < high){
            int mid = low + (high - low) / 2;
            int total = 0, currdays = 1;
            for(int weight : weights){
                total += weight;
                if(total > mid){
                    total = weight;
                    currdays++;
                }
            }
            if(currdays <= days)
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
};