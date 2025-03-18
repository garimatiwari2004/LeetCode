class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       string newstr;
        int maxl = max(word1.length(), word2.length());

        for (int i = 0; i < maxl; i++) {
            if (i < word1.length()) {
                newstr += word1[i];
            }
            
            if (i < word2.length()) {
                newstr += word2[i];
            }
        }

        return newstr;        
    }
};