class Solution {
   public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<int>first(26, -1), last(26, -1);
        for(int i = 0 ; i < s.size() ; i++){
            int c = s[i] - 'a';
            if(first[c] == -1)
                first[c] = i;
            last[c] = i;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(first[i] != -1 && first[i] < last[i]){
                unordered_set<char>st;
                for(int j = first[i] + 1 ; j < last[i] ; j++){
                    st.insert(s[j]);
                }
                ans += st.size();
            }
        }
        return ans;
    }
};