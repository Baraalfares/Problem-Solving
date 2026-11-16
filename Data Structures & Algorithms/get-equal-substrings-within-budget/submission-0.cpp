class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0;
        int n = s.size();
        int cost = 0;
        int res = 0;
        while(j < n){
            cost += (abs(s[j] - t[j]));
            while(cost > maxCost){
                cost -= (abs(s[i] - t[i]));
                i++;
            }
            res = max(j - i + 1, res);
            j++;
        }
        return res;
    }
};
