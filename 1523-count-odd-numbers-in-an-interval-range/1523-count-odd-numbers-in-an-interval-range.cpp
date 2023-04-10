class Solution {
public:
    int countOdds(int low, int high) {
        int n=(high-low),ans=0;
        if(low%2){
            ans=(high-low+2)/2;
        }else{
            ans=(high-low+1)/2;
        }
        return ans;
    }
};