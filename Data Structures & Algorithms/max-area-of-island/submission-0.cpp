class Solution {
public:
    int bfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        int curr=1;
        queue<pair<int,int>> q;
        q.push({i,j}); 
        vector<pair<int,int>> dir={{0,-1},{1,0},{0,1},{-1,0}};
        while(!q.empty()){
            pair<int,int> top=q.front();
            int x=top.first;
            int y=top.second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx=x+dir[i].first;
                int dy=y+dir[i].second;
                if( dx>=0 && dx<n && dy>=0 && dy<m  && grid[dx][dy]==1 && vis[dx][dy]==false){
                    vis[dx][dy]=true;
                    q.push({dx,dy});
                    curr++;
                }
            }
        }
        return curr;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size(); 
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    vis[i][j]=true;
                    int curr=bfs(i,j,grid,vis);
                    ans=max(ans,curr);
                }
            }
        }
        return ans;
    }
};
