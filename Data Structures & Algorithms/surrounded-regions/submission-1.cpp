class Solution {
public:
    void solve(vector<vector<char>>& board) {
     //ig push all 'O' at edge to queue
     int n=board.size();
     int m=board[0].size();
     queue<pair<int,int>> q;
     for(int i=0;i<n;i++){
        if(board[i][0]=='O'){
            board[i][0] = 'Y';
            q.push({i,0});
        }
        if(board[i][m-1]=='O'){
            board[i][m-1] = 'Y';
            q.push({i,m-1});
        }
     }
     for(int j=0;j<m;j++){
        if(board[0][j]=='O'){
            board[0][j] = 'Y';
            q.push({0,j});
        }
        if(board[n-1][j]=='O'){
            board[n-1][j] = 'Y';
            q.push({n-1,j});
        }
     }
     vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
     while(!q.empty()){
        pair<int,int> top=q.front();
        int x=top.first;
        int y=top.second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            if(dx>=0 && dy>=0 && dx<n && dy<m && board[dx][dy]=='O'){
                board[dx][dy]='Y';
                q.push({dx,dy});
            }
        }
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='Y'){
                board[i][j]='O';
            }
            else{
                board[i][j]='X';
            }
        }
     }
     return;
    }
};
