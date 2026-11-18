class Solution {
public:
    bool isvalid(int prev, int curr, int next){
        return (curr > prev && curr > next) || (curr < prev && curr < next);
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int maxlen = 1, currlen = 1;
        int n = arr.size();
        for(int i = 1 ; i < n ; i++){
            if(i > 1 && isvalid(arr[i - 2], arr[i - 1], arr[i])){
                currlen++;
            }
            else if(arr[i] != arr[i - 1])
                currlen = 2;
            else
                currlen = 1;
            maxlen = max(currlen, maxlen);
        }
        return maxlen;
    }
};