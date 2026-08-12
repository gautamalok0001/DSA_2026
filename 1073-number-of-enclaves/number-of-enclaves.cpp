class Solution {
private:
    void dfs(int row, int col, vector<vector<bool>>&vs, vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n || vs[row][col] == true || grid[row][col] == 0) return;
        vs[row][col] = true;

        dfs(row+1,col, vs, grid);
        dfs(row-1, col, vs, grid);
        dfs(row, col+1, vs, grid);
        dfs(row, col-1, vs, grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vs(m, vector<bool>(n,false));
        //Left and right boundary
        for(int i = 0; i < m; i++){
             dfs(i, 0, vs, grid);
             dfs(i,n-1, vs, grid);
        }

        //Top and bottom boundary
        for(int i = 0; i<n; i++){
             dfs(0, i, vs, grid);
             dfs(m-1,i, vs, grid);
        }
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(!vs[i][j] && grid[i][j]) cnt++;
            }
        }
        return cnt;
    }
};