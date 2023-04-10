class Solution {
public:
    int rangeBitwiseAnd(int n, int m) {
        int shift=0;
        while(n!=m){
            m>>=1;n>>=1;shift++;
        }
        return n<<shift;
    }
};
//16 -- 100|00
//19 -- 100|11
//---------------
//      10000

// 421
// 100=4
// 4 left shift by 2 = 16