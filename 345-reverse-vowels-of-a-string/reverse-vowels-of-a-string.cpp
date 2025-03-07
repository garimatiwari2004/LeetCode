class Solution {
public:
bool isvowel(char c){
    c=tolower(c);
    return c=='a'|| c=='e'||c=='i'||c=='o'||c=='u';
}
    string reverseVowels(string s) {
        int low=0;
        int high=s.size()-1;
        while(low<high){
            if(isvowel(s[low])&& isvowel(s[high])){
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else if(isvowel(s[low])==false){
                low++;
            }
            else high--;
        }
        return s;
    }
};