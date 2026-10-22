class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0, j = 0;
        string res = "";
        int write = 0;
        while(j < n){
            while(j < n && chars[i] == chars[j]){
                j++;
            }
            if(j - i == 1){
                chars[write] = chars[i];
                write++;
            }
            else{
                
                chars[write] = chars[i];
                write++;

                string digit = to_string(j - i);
                for(int k = 0 ; k < digit.size() ; k++){
                    chars[write] = digit[k];
                    write++;
                }
            }
            i = j;
        }
        return write;
    }
};