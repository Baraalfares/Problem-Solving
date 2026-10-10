class Solution {
   public:
    int minSwaps(string s) {
        int balance = 0;
        int maxi = 0;
        for (char c : s) {
            if (c == '[') {
                balance++;
            } else
                balance--;
            if (balance < 0) maxi = max(maxi, -balance);
        }
        return (maxi + 1) / 2;
    }
};