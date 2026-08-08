class Solution {
private:
  void dfs(vector<vector<int>>& rooms, vector<bool> & vis, int r){
    vis[r] = true;
    for(int next : rooms[r]){
        if(!vis[next]) dfs(rooms, vis, next);
    }
  }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int m = rooms.size();
        vector<bool> vis(m,false);
        dfs(rooms, vis, 0);
        return count(vis.begin(), vis.end(), true) == m;
    }
};