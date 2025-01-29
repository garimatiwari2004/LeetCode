class Solution {
public:
    bool isPalindrome(int x) {
        long temp=x;
        long reversed=0;
        if(x<0) return false;
        while(temp!=0){
            int digit=temp%10;
            reversed=reversed*10+digit;
            temp/=10;

        }
        return (reversed==x);
    }
};