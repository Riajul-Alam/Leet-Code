class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int l=lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
            if(l!=matrix[i].size() && matrix[i][l]==target){
                return 1;
            }
        }
        return false;
    }
};