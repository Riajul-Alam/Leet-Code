#define INF 1e9


class Solution {
public:
  int dp[10005];
  int f(int i,int n,vector<int>& nums)
  {
    if(i+1==n){
      return 0;
    }
    else if(i+1>n)return 0;
    if(nums[i]==0)return INF;
    if(dp[i]!=-1)return dp[i];
    int x=INF,y=1e9;
    for(int j=1;j<=nums[i];j++){
      x=min(x,1+f(i+j,n,nums));//if(x>0){x=1;break;}
    }
    dp[i]=x;
    return dp[i];
  }
    int jump(vector<int>& nums) {
      //if(nums.size()==1)return true;
        for(int i=0;i<nums.size();i++){
          dp[i]=-1;
        }
        return f(0,nums.size(),nums);
    }
};