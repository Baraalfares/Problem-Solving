class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        int l = 0;
        int r = num;
        long long mid;
        while(l < r){
            mid = l + (r - l) / 2;
            if(mid * mid == num){
                return true;
            }
            else if(mid * mid > num){
                r = mid;
            }
            else
                l = mid + 1;
        }
        return false;
    }
};