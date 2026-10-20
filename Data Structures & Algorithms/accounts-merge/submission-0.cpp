class DSU{
    vector<int> rank,parent;
public:
    DSU(int n){
        rank.resize(n),parent.resize(n);
        for(int i=0;i<n;i++){
            rank[i]=1;parent[i]=i;
        }
    }
    int find(int n){
        if(parent[n]==n)return n;
        return parent[n]=find(parent[n]);
    }
    void Union(int u, int v){
        int pu=find(u);int pv=find(v);
        if(pu!=pv){
            if(rank[pu]<rank[pv])parent[pu]=pv;
            else if(rank[pu]>rank[pv])parent[pv]=pu;
            else{parent[pv]=pu;rank[pu]++;}
        }
    }

};
class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU ds(n);
        unordered_map<string,int> mapEmail;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapEmail.find(mail)==mapEmail.end()){
                    mapEmail[mail]=i;
                }else{
                    ds.Union(i,mapEmail[mail]);
                }
            }
        }
        vector<string> merged[n];
        for(auto it:mapEmail){
            int root=ds.find(it.second);
            merged[root].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged[i].empty())continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};