class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int,int>mp;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                mp[mat[i][j]]++;
            }
        }
        int mini = 10001;
        for(auto it : mp){
            if(it.second == mat.size()){
                mini = min(mini, it.first);
            }
        }
        return mini == 10001 ? -1 : mini;   
    }
};
