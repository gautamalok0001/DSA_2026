class Solution {
private:
      int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, vector<int> &dRow, vector<int>& dCol, int row, int col){
               int m = grid.size();
               int n = grid[0].size();
               vis[row][col] = 1;
               int area = 1;
               for(int i = 0; i< dRow.size(); i++){
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1 && vis[newRow][newCol] != 1){
                       area +=  dfs(grid, vis, dRow, dCol, newRow, newCol);
                }
               }
               return area;
      }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dRow = {-1,0,0,1};
        vector<int> dCol = {0,1,-1,0};
        int cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                      cnt = max(cnt,dfs(grid, vis, dRow, dCol, i, j));
                }
                
            }
        }
        return cnt;
    }
};