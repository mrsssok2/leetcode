class Solution {
public: 

    int  bfs(int t, vector<vector<int>>& grid,vector<vector<int>>& hash , vector<int>& di , vector<int>& dj){
        int n=grid.size();
        int m=grid[0].size();
        int newrow;
        int newcol;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<=n-1;i=i+1){
            for(int j=0;j<=m-1;j=j+1){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    hash[i][j]=1;

                }
            }
        }
        while(q.empty()==false){
            auto p=q.front();
            auto row=p.first.first;
            auto col=p.first.second;
            auto time=p.second;
            t=max(t,time);
            q.pop();
            for(int i=0;i<=3;i=i+1){
                newrow=row+di[i];
                newcol=col+dj[i];
                if(newrow>=0 && newrow<=n-1 && newcol>=0 && newcol<=m-1 && grid[newrow][newcol]==1 && hash[newrow][newcol]==0){
                grid[newrow][newcol]=2;
                hash[newrow][newcol]=1;
                q.push({{newrow,newcol},time+1});
                }
            }
        }
        
        for(int i=0;i<=n-1;i=i+1){
            for(int j=0;j<=m-1;j=j+1)
            if(grid[i][j]==1 && hash[i][j]==0){
                return -1;
            }
        }
        return t;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int t=0;
        vector<int>di={-1,0,1,0};
        vector<int>dj={0,1,0,-1};
        vector<vector<int>>hash(n,vector<int>(m,0));
        return bfs(t,grid,hash,di,dj);
    }
};