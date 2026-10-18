class DSU{
    vector<int> rank,parent;
public:    
    DSU(int n){
        rank.resize(n);parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;rank[i]=1;
        }
    }
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }
    bool Union(int u,int v){
        int pu=find(u);int pv=find(v);
        if(pu==pv)return false;
        if(rank[pv]>rank[pu]){
            swap(pu,pv);
        }
        parent[pv]=pu;
        rank[pu]+=rank[pv];
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res=n;
        for(auto e:edges){
            if(dsu.Union(e[0],e[1])){
                res--;
            }
        }
        return res;
    }
};
