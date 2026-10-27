class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto split = [](const string& sentence){
            vector<string> words;
            stringstream s(sentence);
            string word;
            while(s >> word){
                words.push_back(word);
            }
            return words;
        };
        vector<string> a = split(sentence1);
        vector<string> b = split(sentence2);

        int suffix = 0;
        int prefix = 0;

        int shorter = min(a.size(), b.size());
        int asiz = a.size();
        int bsiz = b.size();
        while(prefix < shorter && a[prefix] == b[prefix]) prefix++;
        while(suffix < shorter - prefix && a[asiz - suffix - 1] == b[bsiz - suffix - 1]) suffix++;

        return suffix + prefix == shorter;
    }
};