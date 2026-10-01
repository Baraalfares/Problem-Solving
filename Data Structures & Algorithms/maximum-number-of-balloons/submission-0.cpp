class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ballon[26] = {0};
        for(char &c : text){
            ballon[c - 'a']++;
        }
        ballon['o' - 'a'] /= 2;
        ballon['l' - 'a'] /= 2;

        return min(ballon['b' - 'a'], min(ballon['a' - 'a'], min(ballon['l' - 'a'], min(ballon['o' - 'a'], ballon['n' - 'a']))));
    }
};