class Solution {
public:
    // void dfs(int row  , int col ,int color , vector<vector<int>>& image , vector<vector<int>>& hash,vector<int>& di , vector<int>& dj){
    //     int n=image.size();
    //     int m=image[0].size();
    //     int ini=image[row][col];
    //     image[row][col]=color;
    //     hash[row][col]=1;
    //     int newrow;
    //     int newcol;
    //     for(int i=0;i<=3;i=i+1){
    //         newrow=row+di[i];
    //         newcol=col+dj[i];
    //         if(newrow>=0 && newrow<=n-1 && newcol>=0 && newcol<=m-1 && hash[newrow][newcol]==0 && clone[newrow][newcol]==ini){
    //             dfs(newrow,newcol,color,image,hash,di,dj);
    //         }
    //     }

    // }

    void bfs(int row  , int col ,int color , vector<vector<int>>& image , vector<vector<int>>& hash,vector<int>& di , vector<int>& dj , vector<vector<int>>& clone){
        int n=image.size();
        int m=image[0].size();
        int newrow;
        int newcol;
        queue<pair<int,int>>q;
        q.push({row,col});
        int ini=image[row][col];
        clone[row][col]=color;
        hash[row][col]=1;
        while(q.empty()==false){
            auto p = q.front();
            int roww=p.first;
            int coll=p.second;
            q.pop();
            for(int i=0;i<=3;i=i+1){
                newrow=roww+di[i];
                newcol=coll+dj[i];
                if(newrow>=0 && newrow<=n-1 && newcol>=0 && newcol<=m-1 && hash[newrow][newcol]==0 && clone[newrow][newcol]==ini){
                    clone[newrow][newcol]=color;
                    hash[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int ini=image[sr][sc];
        vector<int>di={-1,0,1,0};
        vector<int>dj={0,1,0,-1};
        vector<vector<int>>hash(n,vector<int>(m,0));
         vector<vector<int>>clone(n,vector<int>(m,0));
         for(int i=0;i<=n-1;i=i+1){
            for(int j=0;j<=m-1;j=j+1){
                clone[i][j]=image[i][j];
            }
         }
        bfs(sr,sc,color,image,hash,di,dj,clone);
        return clone;
    }
};