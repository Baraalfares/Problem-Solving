class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int maxi = 0;
        unordered_map<long long,int>edges;
        for(auto &bricks : wall){
            long long position = 0;
            for(int j = 0; j < bricks.size() - 1 ; j++){
                position += bricks[j];
                edges[position]++;
                maxi = max(maxi, edges[position]);
            }
        }
        return wall.size() - maxi;
    }
};