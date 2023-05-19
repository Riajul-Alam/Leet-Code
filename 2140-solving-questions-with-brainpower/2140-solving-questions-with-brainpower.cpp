#define ll long long

class Solution {
public:

    ll solveMemo(vector<vector<int>>& q, int index, vector<ll>& dp)    {
        if(index >= q.size()) return 0;
        if(dp[index] != -1)   return dp[index];

        // include
        ll pointsIn = q[index][0] + solveMemo(q, index + q[index][1] + 1, dp);

        // exclude
        ll pointsEx = solveMemo(q, index + 1, dp);

        return dp[index] = (pointsIn > pointsEx) ? pointsIn : pointsEx;
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<ll> dp(questions.size() , -1);
        return solveMemo(questions, 0, dp);
    }
};