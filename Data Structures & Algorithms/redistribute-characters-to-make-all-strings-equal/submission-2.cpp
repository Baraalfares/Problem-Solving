class Solution {
   public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> mp;
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                mp[c - 'a']++;
            }
        }
        for (auto it : mp) {
            if (it.second % words.size() != 0) return false;
        }
        return true;
    }
};