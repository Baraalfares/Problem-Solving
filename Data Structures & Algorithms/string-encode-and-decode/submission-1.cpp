#include <string>
class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (string s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> vec;
        int i = 0;
        while(i < s.size()) {
            string sz = "";
            string word = "";
            while (i < s.size() && s[i] != '#') {
                sz += s[i];
                i++;
            }
            int len = 0;
            for (char c : sz) {
                len = len * 10 + (c - '0');
            }
            i++;
            for (int j = 0; j < len; j++) {
                word += s[i++];
            }
            vec.push_back(word);
        }
        return vec;
    }
};
