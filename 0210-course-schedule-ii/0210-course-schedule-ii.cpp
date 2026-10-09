class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0); 
        vector<int> order;
        for(auto &edge: edges){
            int u=edge[1];
            int v=edge[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            order.push_back(curr);
            for(auto it:adj[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(order.size()!=V){
            return {};
        }
        return order;
    }
};