class Solution {
public:
    int arraySign(vector<int>& a) {
        int c1=0,c2=0,n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]<0)c1++;
            if(a[i]==0)c2++;
        }
        if(c2){
            return 0;
        }
        else if(c1%2){
            return -1;
        }else{
            return 1;
        }
    }
};