class Solution {
public:
    int bulbSwitch(int n) {
        int x=0;
        while((x+1)*(x+1)<=n){
            x++;
        }
        return x;
    }
};