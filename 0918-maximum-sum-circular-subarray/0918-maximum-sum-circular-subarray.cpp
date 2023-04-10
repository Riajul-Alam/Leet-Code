// dp
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
    int maxSubarraySumCircular(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
        	for(int j=0;j<2;j++)
        		dp[i][j]=-1;
        }
        int nocirculer=f(0,nums,0),sum=0;
        if(nocirculer<0)nocirculer;
        for(int i=0;i<nums.size();i++)
        {
        	for(int j=0;j<2;j++)
        		dp[i][j]=-1;
        }

        int totalSum=0,mn=1e9,allMinus=0;
        for(int i=0;i<nums.size();i++)
        {
        	if(nums[i]<0)allMinus++;sum+=nums[i];
        	nums[i]=(-nums[i]);totalSum+=nums[i];
        	mn=min(nums[i],mn);
        }
        if(allMinus==nums.size()){
        	return -*min_element(nums.begin(),nums.end());
        }
        else if(allMinus==0){
        	return sum;
        }
        int circuler=sum+f(0,nums,0);
        return max(circuler,nocirculer);
    }
};
//iterative
class Solution2 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int current , sum , maximum,n=nums.size(),mn=1e9;
        vector<int>pre(n+5,0),suf(n+5,-1e9);
        sum = maximum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            current = nums[i];
            sum += current;
            sum = max(sum , current);
            
            maximum = max(maximum , sum);
        }
        int ans=maximum;
        sum = maximum = nums[0];
        pre[0]=sum;
        for(int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            maximum = max(maximum , sum);
            pre[i]=maximum;
        }
        sum = maximum = nums[n-1];
        pre[n-1]=sum;
        for(int i = n-2; i >=0; i--)
        {
            sum += nums[i];
            maximum = max(maximum , sum);
            suf[i]=maximum;
        }
        for(int i=0;i<n;i++){
            int x,y;
            x=pre[i];
            y=suf[i+1];
            //cout<<x<<" "<<y<<endl;
            ans=max({ans,x+y,x,y});
        }
        return ans;
    }
};