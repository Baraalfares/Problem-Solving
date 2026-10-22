class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0, write = 0, n = chars.size();
        while(j < n){
            while(j < n && chars[i] == chars[j]){
                j++;
            }
            chars[write++] = chars[i];
            if(j - i > 1){
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