class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1)return false;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_set<int> vs;
        queue<pair<int,int>> q;
        q.push({0,-1});
        vs.insert(0);
        while(!q.empty()){
            auto [node,parent]=q.front();q.pop();
            for(auto n:adj[node]){
                if(n==parent)continue;
                if(vs.count(n))return false;
                vs.insert(n);
                q.push({n,node});
            }
        }
        return vs.size()==n;
    }
};
