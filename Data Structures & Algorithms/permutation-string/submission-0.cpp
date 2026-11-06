class Solution {
    bool counts(unordered_map<char, int>& mp) {
        for (auto it : mp) {
            if (it.second != 0) return false;
        }
        return true;
    }

   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for (char c : s1) {
            mp[c]++;
        }
        int i = 0;
        int j = 0;
        while (j < s2.size()) {
            mp[s2[j]]--;

            if (j - i + 1 == s1.size()){
                if(counts(mp)) return true;
                mp[s2[i]]++;
                i++;
            }
            j++;
        }
        return false;
    }
};
