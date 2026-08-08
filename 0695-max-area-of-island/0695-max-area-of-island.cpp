class Solution {
private:
      int dfs(vector<vector<int>>& grid, int row, int col){
               int m = grid.size();
               int n = grid[0].size();
               if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) return 0;
               int area = 1;
               static const int dr[] = {-1,0,0,1};
               static const int dc[] = {0,1,-1,0};
               grid[row][col] = 0;
               for(int i = 0; i< 4; i++)
                  area += dfs(grid, row + dr[i], col + dc[i]);

               return area;
      }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j]){
                      cnt = max(cnt,dfs(grid, i, j));
                }
                
            }
        }
        return cnt;
    }
};