class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n,m;n=grid.size(),m=grid[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++){
        	int x=i,y;
        	for(int j=0;j<n;j++){
        		y=x+grid[j][x];
        		if(y<0 || y>=m || grid[j][x]!=grid[j][y]){
        			x=-1;break;
        		}
        		x=y;
        	}
        	ans.push_back(x);
        }
        return ans;
    }
};