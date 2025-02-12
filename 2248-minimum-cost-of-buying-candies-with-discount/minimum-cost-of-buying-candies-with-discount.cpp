class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n=cost.size();
        int res=0;
        for(int i=0;i<cost.size();++i){
            if(i%3!=n%3){
                res+=cost[i];
            }
        }
        return res;
        
    }
};