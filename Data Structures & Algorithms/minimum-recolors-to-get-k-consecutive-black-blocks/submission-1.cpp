class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        unordered_map<char,int>mp;
        int i = 0;
        int j = 0;
        int mini = INT_MAX;
        while(j < blocks.size()){
            mp[blocks[j]]++;
            if(j - i + 1 == k){
                mini = min(mini, mp['W']);
                mp[blocks[i]]--;
                i++;
            }
            j++;
        }
        return mini;
    }
};