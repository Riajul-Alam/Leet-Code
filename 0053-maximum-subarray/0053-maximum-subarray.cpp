class Solution {
public:
	int dp[100005][2];
	int f(int i,vector<int>&nums,int pick)
	{
		if(i>=nums.size())return (pick ? 0 : -1e9);
		if(dp[i][pick]!=-1)return dp[i][pick];
		if(pick){
			dp[i][pick]=max(0,nums[i]+f(i+1,nums,pick));
		}else{
			int x=-1e9,y=-1e9;
			//pick
			x=nums[i]+f(i+1,nums,1);
			// not pick
			y=f(i+1,nums,0);
			dp[i][pick]=max(x,y);
		}
		return dp[i][pick];
	}
    int maxSubArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
        	for(int j=0;j<2;j++)
        		dp[i][j]=-1;
        }
        return f(0,nums,0);
    }
};