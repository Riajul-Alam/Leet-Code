class Solution {
public:
	int dp[10005];
	int f(int i,int n,vector<int>& nums)
	{
		if(i+1==n){
			return 1;
		}
		else if(i+1>n)return 1;
		if(nums[i]==0)return 0;
		if(dp[i]!=-1)return dp[i];
		int x=0;
		for(int j=1;j<=nums[i];j++){
			x+=f(i+j,n,nums);if(x>0){x=1;break;}
		}
		dp[i]=x;
		return dp[i];
	}
    bool canJump(vector<int>& nums) {
    	//if(nums.size()==1)return true;
        for(int i=0;i<nums.size();i++){
        	dp[i]=-1;
        }
        if(f(0,nums.size(),nums)){
        	return true;
        }else return false;
    }
};