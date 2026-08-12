class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>hash(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m));
        vector<int>di={-1,0,1,0};
        vector<int>dj={0,1,0,-1};
        int nr;
        int nc;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<=n-1;i=i+1){
            for(int j=0;j<=m-1;j=j+1){
                if(mat[i][j]==0){
                    hash[i][j]=1;
                    dist[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }

        while(q.empty()==false){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[row][col]=steps;
            for(int i=0;i<=3;i=i+1){
                nr = row + di[i] ;
                nc = col + dj[i] ;
                if(nr>=0 && nc>=0 && nr<=n-1 && nc <=m-1 && mat[nr][nc]==1 && hash[nr][nc]==0){
                    hash[nr][nc]=1;
                    q.push({{nr,nc},steps+1});

                }
            }
        }  
        return dist;
    }

};