class Solution {
public:
    bool isPalindrome(string s) {
        string n;
        for(char c:s){
            if(isalnum(c)){
                n+=tolower(c);
           }
        }
        int left=0;
        int right=n.size()-1;
        while(left<right){
            if(n[left]!=n[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};