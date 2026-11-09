class Solution {
   public:
    int maxVowels(string s, int k) {
        unordered_map<char, int> mp;
        int curr = 0;
        int maxv = 0;
        mp['a'] = 0;
        mp['e'] = 0;
        mp['u'] = 0;
        mp['i'] = 0;
        mp['o'] = 0;

        int i = 0;
        int j = 0;
        while (j < s.size()) {
            if (mp.count(s[j])) {
                curr++;
            }
            if (j - i + 1 > k) {
                if (mp.count(s[i])) curr--;
                i++;
            }
            maxv = max(maxv, curr);
            j++;
        }
        return maxv;
    }
};
