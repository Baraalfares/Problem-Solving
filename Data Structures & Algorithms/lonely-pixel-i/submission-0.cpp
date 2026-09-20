class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int count = 0;
        int n = picture.size();
        int m = picture[0].size();
        vector<int>row(n, 0), col(m , 0);
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if(picture[i][j] == 'B'){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(row[i] == 1){
                for(int j = 0 ; j < m ; j++){
                    if(picture[i][j] == 'B'){
                        if(col[j] == 1) count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};
