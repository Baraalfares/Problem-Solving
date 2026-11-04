class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        vector<int>mp(2, 0); // we only have to values 0 and 1
        int maxi = 0;
        for(int one : data){
            if(one == 1)
                ones++;
        }
        if(ones <= 1)
            return 0;
        int i = 0;
        int j = 0;
        while(j < data.size()){
            mp[data[j]]++;
            if(j - i + 1 == ones){
                maxi = max(maxi, mp[1]);
                mp[data[i]]--;
                i++;
            }
            j++;
        }
        return ones - maxi;
    }
};
