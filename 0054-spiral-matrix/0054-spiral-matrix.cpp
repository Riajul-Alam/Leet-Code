class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n,m;vector<int>ans;
        n=matrix.size(),m=matrix.begin()->size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int up,right,down,left,c1=0,total=n*m;
        up=0;right=m-1;
        down=n-1,left=0;
        while(1)
        {
        	c1=0;
            for(int i=up;i<right;i++){
            	if(ans.size()>=total)break;c1++;
                ans.push_back(matrix[up][i]);
                vis[up][i]=1;
            }
            for(int i=up;i<down;i++){
            	if(ans.size()>=total)break;c1++;
                ans.push_back(matrix[i][right]);
                vis[i][right]=1;
            }
            for(int i=right;i>left;i--){
            	if(ans.size()>=(total))break;c1++;
                ans.push_back(matrix[down][i]);
                vis[down][i]=1;
            }
            for(int i=down;i>up;i--){
            	if(ans.size()>=total)break;c1++;
                ans.push_back(matrix[i][left]);
                vis[i][left]=1;
            }
            up++;right--;
            down--;left++;
            if(c1==0){
            	break;
            }
            if(ans.size()>=total)break;
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		if(vis[i][j]==0){
        			ans.push_back(matrix[i][j]);	
        		}
        	}
        }
        return ans;
    }
};