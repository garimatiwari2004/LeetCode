class Solution {
public:
    string reverseWords(string s) {
        std::stringstream ss(s);
        std::string reversed; 
        std::string wordvar;   
        vector<string>word;
        while(ss >> wordvar){
            word.push_back(wordvar);
        }
        int n=word.size();
        for(int i=n-1;i>=0;--i){
            if(!reversed.empty()){
                reversed+=" ";
            }
            reversed+=word[i];
        }
        return reversed;

        
    }
};