class Solution {
private:
 int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col){
    int m = grid.size();
    int n = grid[0].size();
  

    if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) return 1;
    if(vis[row][col] == 1) return 0;
     vis[row][col] = 1;
    static int const rd[] = {-1,1,0,0};
    static int const cd[] = {0,0,1,-1};
    int perimeter = 0;
    for(int i = 0; i < 4; i++){
          perimeter += dfs(grid, vis, row+rd[i], col+cd[i]);
    }
    return perimeter;
}
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis (m, vector<int>(n,0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                     if(grid[i][j] == 1 && vis[i][j] != 1 ){
                        perimeter += dfs(grid, vis, i, j);
                     }
            }
        }
        return perimeter;
    }
};