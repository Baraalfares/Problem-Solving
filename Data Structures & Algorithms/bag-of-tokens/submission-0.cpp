class Solution {
   public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int l = 0, r = n - 1;
        int score = 0, maxscore = 0;
        if(tokens.empty() || power < tokens[l])
            return 0;
        while(l <= r){
            if(power < tokens[l] && score > 0){
                power += tokens[r];
                r--;
                score--;
            }
            else if(power >= tokens[l]){
                power -= tokens[l];
                score++;
                l++;
            }
            maxscore = max(score, maxscore);
        }
        return maxscore;
    }
};