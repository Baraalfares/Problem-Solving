class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num * 9)
            return "";
        int remain = sum;
        string res = "";
        while(num--){
            int digit = min(9, remain);

            res += to_string(digit);
            remain -= digit;
        }
        return res;
    }
};