class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return{0};
        vector<vector<int>> adj(n);
        vector<int> degree(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }
        int rem = n;
        while (rem > 2) {
            int qs = q.size();
            rem -= qs;
            for (int i = 0; i < qs; i++) {
                int l = q.front();
                q.pop();
                for (auto& node : adj[l]) {
                    if (--degree[node] == 1)
                        q.push(node);
                }
            }
        }
        vector<int> ans;
        int a=q.size();
        for (int i = 0; i < a; i++) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};