class Solution {
private:
    double bfs(string& src,string& tgt,unordered_map<string,vector<pair<string,double>>>& adj){
        if(!adj.count(src)||!adj.count(tgt))return -1.0;
        queue<pair<string,double>> q;
        unordered_set<string> vis;
        q.push({src,1.0});
        while(!q.empty()){
            auto[node,weight]=q.front();q.pop();
            if(node==tgt)return weight;
            for(auto& [nei,neiwgt]:adj[node]){
                if(!vis.count(nei)){
                    vis.insert(nei);
                    q.push({nei,weight*neiwgt});
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<e.size();i++){
            string a=e[i][0];
            string b=e[i][1];
            adj[a].push_back({b,v[i]});
            adj[b].push_back({a,1.0/v[i]});
        }
        vector<double> ans;
        for(auto& it:queries){
            string src=it[0];
            string tgt=it[1];
            ans.push_back(bfs(src,tgt,adj));
        }
        return ans;
    }
};