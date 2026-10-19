class Solution {
   public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string, int> mp;
        for (string res : responses) {
            unordered_set<string> st;
            stringstream ss(res);
            string word;
            while (ss >> word) {
                st.insert(word);
            }
            for (auto it : st) {
                mp[it]++;
            }
        }
        stable_sort(features.begin(), features.end(),
                    [&](const string& a, const string& b) { return mp[a] > mp[b]; });
        return features;
    }
};