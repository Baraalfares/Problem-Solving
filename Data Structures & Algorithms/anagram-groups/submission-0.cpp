class Solution {
   public:
    string key(const string& s) {
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        string key = "";
        for (int i = 0; i < 26; i++) {
            key += to_string(count[i]) + "#";
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            mp[key(strs[i])].push_back(strs[i]);
        }
        for (auto& it : mp) {
            res.push_back(move(it.second));
        }
        return res;
    }
};