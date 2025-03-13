class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map;
        for(auto x:s){
            map[x]++;
        }
        for(auto y:t){
            map[y]--;
        }
        for(auto x:map){
            if(x.second!=0){
                return false;
            }
        }

        return true;
    }
};