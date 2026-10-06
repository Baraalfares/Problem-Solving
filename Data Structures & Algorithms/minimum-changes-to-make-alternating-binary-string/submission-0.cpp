class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        int n = s.size();
        for(int i = 0 ; i < s.size(); i++){
            if(i % 2 == 0){
                if(s[i] != '0')
                    count++;
                
            }
            else{
                if(s[i] != '1')
                    count++;
            }
        }
        return min(count, n - count);
    }
};