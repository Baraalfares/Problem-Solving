class Solution {
public:
    bool ispalindrome(string& word){
        int i = 0;
        int j = word.size() - 1;
        while(i <= j){
            if(word[i] != word[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int first = words.size() - 1;
        for(int i = 0 ; i < words.size() ; i++){
            if(ispalindrome(words[i]))
                first = min(first, i);
        }
        return ispalindrome(words[first]) ? words[first] : "";
    }
};