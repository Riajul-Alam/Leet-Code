#define sz(cont) (int)(cont).size()
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vi>
#define vvb vector<vector<bool>>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
// Grid direction array [4]
int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
class Solution {
public:
    
    void dfs(vvi &matrix,int i,int j,int prev,vvi &ocean){
        if(i<0 || j<0 || i>=sz(matrix) || j>=sz(matrix[0]))return;
        if(ocean[i][j]==1)return;
        if(matrix[i][j]<prev)return;
        ocean[i][j]=1;
        for(int k=0;k<4;k++){
            dfs(matrix,X[k]+i,Y[k]+j,matrix[i][j],ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;int n,m;
        n=sz(heights);m=sz(heights[0]);
        if(n<1)return ans;
        vvi pacific(n,vi(m,0));
        vvi atlantic(n,vi(m,0));
        
        for(int i=0;i<m;i++){
            dfs(heights,0,i,INT_MIN,pacific);
            dfs(heights,n-1,i,INT_MIN,atlantic);
        }
        for(int i=0;i<n;i++){
            dfs(heights,i,0,INT_MIN,pacific);
            dfs(heights,i,m-1,INT_MIN,atlantic);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.pb({i,j});
                }
            }
        }
        return ans;
    }
};