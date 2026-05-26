class Solution {
public:
    void bfs(vector<vector<int>>& grid,vector<vector<bool>> &vis,int n,int m,int i,int j,int &p){
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            pair<int,int> top=q.front();
            int x=top.first;
            int y=top.second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx=x+dir[i][0];
                int dy=y+dir[i][1];
                if(dx>=0 && dy>=0 && dx<n && dy<m && grid[dx][dy]==1 && vis[dx][dy]==0){
                    vis[dx][dy]=1;
                    q.push({dx,dy});
                }
                if(dx<0 || dx >=n || dy <0 || dy>=m || grid[dx][dy]==0){
                    p++;
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int perimeter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false && grid[i][j]==1){
                    vis[i][j]=true;
                    bfs(grid,vis,n,m,i,j,perimeter);
                }
            }
        }
        return perimeter;
    }
};