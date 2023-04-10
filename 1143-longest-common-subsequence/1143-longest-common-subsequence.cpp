class Solution {
public:
    int dp[1000][1000];
    
    int f(string &a,string &b,int x,int y)
    {
        if(x<0 || y<0)return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        dp[x][y]=0;
        if(a[x]==b[y])
        {
            return dp[x][y]=1+f(a,b,x-1,y-1);
        }
        else if(a[x]!=b[y])
        {
            return dp[x][y] = max(f(a,b,x,y-1),f(a,b,x-1,y));
        }
        dp[x][y]=0;
        return dp[x][y];
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return f(text1,text2,text1.size()-1,text2.size()-1);
    }
};