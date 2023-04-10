class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int sum=0,ans=0,n=costs.size();
        sort(costs.begin(),costs.end());
        for(int i=0;i<n;i++){
            if(sum+costs[i]<=coins){
                sum+=costs[i];ans++;
            }else break;
        }
        return ans;
    }
};