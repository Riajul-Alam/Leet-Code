class Solution {
public:
	int dp[50];
    int f(int n)
    {
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int x=0,y=0;
        if(n-1>=0)x=f(n-1);
        if(n-2>=0)y=f(n-2);
        dp[n]=x+y;
        return dp[n];
    }
    int climbStairs(int n) {
        for(int i=0;i<=n;i++)dp[i]=-1;
        return f(n);
    }
};