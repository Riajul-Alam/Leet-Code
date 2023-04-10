class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int c1=0,m=a.size();
        for(int i=0;i<m;i++){
            if(i==0){
                if(i+1<m && a[i]==0 && a[i+1]==0){
                    c1++;a[i]=1;
                }
                else if(m==1 && a[i]==0)c1++;
            }else if(i==m-1){
                if(i-1>=0 && a[i]==0 && a[i-1]==0){
                    c1++;a[i]=1;
                }                
            }
            else{
                if(a[i+1]==0 && a[i-1]==0 && a[i]==0){
                    c1++;a[i]=1;
                }
            }
        }
        return c1>=n;
    }
};