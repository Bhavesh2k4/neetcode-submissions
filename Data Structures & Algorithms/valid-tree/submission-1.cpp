class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,int> parent;
        unordered_map<int,bool> vis;
        queue<int> q;
        q.push(0);
        parent[0]=-1;
        vis[0]=true;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto i:adj[top]){
                if(vis[i]==false){
                    vis[i]=true;
                    parent[i]=top;
                    q.push(i);
                }
                else if(parent[top]!=i){
                    return false;
                }
            }
        }
        return vis.size()==n;
    }
};
