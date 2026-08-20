class Solution {
private:
 bool dfs(int node, vector<int>&state, vector<vector<int>>&graph){
    if(state[node] == 1) return false;

    if(state[node] == 2) return true;

    state[node] = 1;

    for(int neighbourNode : graph[node])
    {
        if(!dfs(neighbourNode, state, graph)) return false;
    }
    state[node] = 2;
    return true;
 }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>state(v,0);
        vector<int>result;
        for(int i = 0; i < v; i++){
            if(dfs(i, state, graph)){
               result.push_back(i);
            }
        }
        return result;
    }
};