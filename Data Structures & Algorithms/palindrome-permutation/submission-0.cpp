class Solution {
   public:
    bool canPermutePalindrome(string s) {
        vector<int> vec(26, 0);
        int odds = 0;
        for (int i = 0; i < s.size(); i++) {
            vec[s[i] - 'a']++;
        }
        for (int freq : vec) {
            if (freq % 2 != 0) odds++;
        }
        return (odds <= 1);
    }
};
