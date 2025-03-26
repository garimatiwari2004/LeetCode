class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>newgrid;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                newgrid.push_back(grid[i][j]);
                
            }
        }
        int a=newgrid[0]%x;
        for(int i=1;i<newgrid.size();++i){
            if(newgrid[i]%x!=a) return -1;
        }
        sort(newgrid.begin(),newgrid.end());
        int median=newgrid[newgrid.size()/2];
        
        int operations=0;
        for(auto n:newgrid){
            operations+=abs(n-median)/x;
        }


        return operations;
    }
};