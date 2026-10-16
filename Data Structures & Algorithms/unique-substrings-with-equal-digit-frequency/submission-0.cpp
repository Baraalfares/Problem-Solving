class Solution {
public:
    int equalDigitFrequency(string s) {
        unordered_set<string>valid;

        for(int i = 0 ; i < s.size() ; i++){
            string ss = "";
            unordered_map<char,int>freq;

            for(int j = i; j < s.size(); j++){
                ss += s[j];
                freq[s[j]]++;
                bool isvalid = true;
                int exp = freq.begin()->second;
                for(auto& it : freq){
                    if(it.second != exp){
                        isvalid = false;
                        break;
                    }
                }
                if(isvalid)
                    valid.insert(ss);
            }
        }
        return valid.size();
    }
};
