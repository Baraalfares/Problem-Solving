class Solution {
public:
    int maxDifference(string s) {
        vector<int>vec(26, 0);
        int maxodd = 0;
        int mineven = 101;
        for(int i = 0 ; i < s.size() ; i++){
            vec[s[i] - 'a']++;
        }
        for(int freq : vec){
            if(freq % 2 == 0 && freq < mineven && freq != 0)
                mineven = freq;
            else if (freq % 2!= 0 && freq > maxodd)
                maxodd = freq;
        }
        return maxodd - mineven;
    }
};