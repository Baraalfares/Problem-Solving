class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1;
        int r = n;
        long long mid = 0, coins = 0;
        while(l <= r){
            mid = l + (r - l) / 2;
            coins = (mid * (mid + 1)) / 2;
            if(coins == n)
                return mid;
            if(coins > n)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return r;
    }
};