class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool a=true;
        for(int i=0;i<ransomNote.size();i++){
            if(magazine.find(ransomNote[i])==string::npos){
                a=false;
                break;
            }
            else{
            size_t g=magazine.find(ransomNote[i]);
            magazine.erase(g,1);    
            } 
        }
        return a;
    }
};