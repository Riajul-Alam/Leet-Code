class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size(),ans=0;
        for(int i=0,j=0;i<n && j<n;i++,j++)ans+=mat[i][j];
        for(int j=n-1,i=0;j>=0;j--,i++)ans+=mat[j][i];
        if(n%2)ans-=mat[n/2][n/2];
        return ans;
    }
};