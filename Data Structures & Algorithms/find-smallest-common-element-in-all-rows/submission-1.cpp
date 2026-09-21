class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        for(int val : mat[0]){
            bool found = true;
            for(int i = 1 ; i < mat.size() ; i++){
                int left = 0;
                int right = mat[i].size() - 1;
                bool exst = false;
                while(left <= right){
                    int mid = left + (right - left) / 2;
                    if(mat[i][mid] == val){
                        exst = true;
                        break;
                    }
                    else if(mat[i][mid] < val) left = mid + 1;
                    else right = mid - 1;
                }
                if(!exst){
                    found = false;
                    break;
                }
            }
            if(found)
                return val;
        }
        return -1;
    }
};
