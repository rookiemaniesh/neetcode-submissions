class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n,false);
        int res=0;
        for(int node=0;node<n;node++){
            if(!vis[node]){
                dfs(adj,vis,node);
                res++;
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& adj,vector<bool>& vis,int node){
        vis[node]=true;
        for(auto nei:adj[node]){
            if(!vis[nei])dfs(adj,vis,nei);
        }
    }
};
