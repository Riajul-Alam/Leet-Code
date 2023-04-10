class Solution {
public:
    bool check(vector<int>& piles, int h, int k) {
        if (k == 0) {
            return false;
        }
        
        int i = 0;
        while (h >= 0 && i < piles.size()) {
            h -= ceil((double)piles[i] / k);
            i++;
        }
        
        return h >= 0 && i == piles.size();
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0;
        int r = piles[0];
        for (int i = 0; i < piles.size(); i++) {
            r = max(r, piles[i]);
        }
        r++;
        
        int ans = -1;
        while (l+1<r) {
            int m = (l + r)/2;
            if (check(piles,h,m)) {
                r=m;
                ans=m;
            } else {
                l = m;
            }
        }
        
        return ans;
    }
};
