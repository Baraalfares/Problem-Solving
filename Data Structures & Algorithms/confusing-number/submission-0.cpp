class Solution {
public:
    bool confusingNumber(int n) {
        vector<int>mp(10, -1);
        mp[0] = 0;
        mp[1] = 1;
        mp[6] = 9;
        mp[8] = 8;
        mp[9] = 6;
        long long rotated = 0;
        int original = n;
        while(original > 0){
            int digit = original % 10;
            if(mp[digit] == -1){
                return false;
            }
            rotated = rotated * 10 + mp[digit];
            original /= 10;
        }
        return rotated != n;
    }
};
