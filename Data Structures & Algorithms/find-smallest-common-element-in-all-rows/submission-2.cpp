class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        for(int val : mat[0]){
            bool found = true;
            for(int i = 1 ; i < mat.size() ; i++){
                if(!binary_search(mat[i].begin(), mat[i].end(), val)){
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
