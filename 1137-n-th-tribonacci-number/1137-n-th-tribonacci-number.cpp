class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        else if(n==1)return 1;
        else if(n==2)return 1;
        else if(n==3)return 2;
        
        int sum=0,sum1=1,sum2=1;
        for(int i=3;i<=n;i++){
            int tmp=sum2;
            sum2=sum+sum1+sum2;
            sum=sum1;
            sum1=tmp;
        }
        return sum2;
    }
};