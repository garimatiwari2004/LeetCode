class Solution {
public:
 int dfs(vector<vector<int>>& grid, int x, int y, int islandId) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1) {
            return 0;
        }

        grid[x][y] = islandId; // Mark the cell with the island ID
        int size = 1;

        // Directions for moving up, right, down, and left
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (const auto& dir : directions) {
            size += dfs(grid, x + dir[0], y + dir[1], islandId);
        }

        return size;
 }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int id=2;
        unordered_map<int,int>islandsize;
        vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;++i){   
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    int size=dfs(grid,i,j,id);
                    islandsize[id]=size;
                    id++;
                }
            }
        }
        int maxIslandSize = islandsize.empty() ? 0 : max_element(islandsize.begin(), islandsize.end(), [](const auto& a, const auto& b) { return a.second < b.second; })->second;
        
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> connectedIslands;
                    int potentialSize = 1; // Start with the current cell being changed to 1

                    // Check all four directions
                    for (const auto& dir : dirs) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            connectedIslands.insert(grid[ni][nj]);
                        }
                    }
                     for (const auto& id : connectedIslands) {
                        potentialSize += islandsize[id];
                    }
                     maxIslandSize = max(maxIslandSize, potentialSize);
                }
            }
        }

        return maxIslandSize;
    }
};