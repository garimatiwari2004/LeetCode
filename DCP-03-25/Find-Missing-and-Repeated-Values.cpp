class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int  n=grid.size();
        int size=n*n;
        vector<int>count(size+1,0);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                count[grid[i][j]]++;
            }
        }
        int missing=-1;
        int duplicate=-1;
        for(int num=1;num<=size;num++){
            if(count[num]==0) missing=num;
            if(count[num]==2) duplicate=num;
        }
        return {duplicate,missing};
    }
};