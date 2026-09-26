class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        vector<int> flower(flowerbed.size() + 2, 0);
        for(int i = 0 ; i < m ; i++){
            flower[i+1] = flowerbed[i];
        }
        for(int i = 1 ; i < flower.size() - 1 ; i++){
            if(flower[i - 1] == 0 && flower[i] == 0 && flower[i + 1] == 0){
                flower[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};