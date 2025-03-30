class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lastindex(26,0);
        for (int i=0;i<s.size();++i){
            lastindex[s[i]-'a']=i;
        }
        int start=0,end=0;
        vector<int>partitions;
        for(int i=0;i<s.size();++i){
            end=max(end,lastindex[s[i]-'a']);
            if(i==end){
                partitions.push_back(end-start+1);
                start=i+1;

            }
        }

        return partitions;
    }
};