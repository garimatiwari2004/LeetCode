class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(auto dig:num){
            while(!st.empty() && k>0 && st.top()>dig){
                st.pop();
                k--;
            }
            st.push(dig);
            if(st.size()==1 && dig=='0' ) st.pop();
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string result;
        while(!st.empty()){
            result+=st.top();
            st.pop();

        }
        reverse(result.begin(),result.end());
        if(result.length() == 0)
            return "0";
        
        return result;
        


    }
};