class Solution {
   public:
    bool isvowel(string s) {
        int n = s.size() - 1;
        if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'u' || s[0] == 'o') &&
            (s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'u' || s[n] == 'o')) {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> res;
        int count = 0;
        vector<int> vec(n, 0);
        for (int i = 0; i < words.size(); i++) {
            if (isvowel(words[i])) {
                count++;
            }
            vec[i] = count;
        }

        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 0) {
                res.push_back(vec[queries[i][1]]);
            } else {
                int num = vec[queries[i][1]] - vec[queries[i][0] - 1];
                res.push_back(num);
            }
        }
        return res;
    }
};