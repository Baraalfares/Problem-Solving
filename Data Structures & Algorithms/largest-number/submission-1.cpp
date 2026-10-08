class Solution {
    static bool compare(const string &a, const string &b){
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string>vec;
        for(int num : nums){
            vec.push_back(to_string(num));
        }
        sort(vec.begin(), vec.end(), compare);

        if(vec[0] == "0")
            return "0";
        string res = "";
        for(string s : vec){
            res+=s;
        }
        return res;
    }
};