class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = 0;
        int left = 1;
        for (int pile : piles) {
            right = max(right, pile);
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;
            for(int pile : piles){
                hours += (pile / mid);
                if(pile % mid != 0)
                    hours++;
            }
            if(hours <= h){
                right = mid;
            }
            else
                left = mid + 1;
        }
        return right;
    }
};
