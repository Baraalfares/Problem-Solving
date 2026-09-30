class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int>freqs;
        for(int i = 0 ; i < arr.size() ; i++){
            freqs[arr[i]]++;
        }
        for(auto &s : arr){
            if(freqs[s] == 1)
                k--;
            if(k == 0)
                return s;
        }
        return "";
    }
};