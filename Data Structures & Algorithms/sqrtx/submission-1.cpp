class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)
            return 1;
        int l = 0;
        int r = x;
        long long mid;
        int ans = 0;
        while(l < r){
            mid = l + (r - l) / 2;
            if(mid * mid == x)
                return mid;
            else if(mid * mid > x)
                r = mid;
            else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};