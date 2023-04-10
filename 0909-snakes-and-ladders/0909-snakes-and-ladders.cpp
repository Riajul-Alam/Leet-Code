class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int>v(n*n,-1);int cnt = 0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n && cnt<v.size();j++)
        {
            if(board[i][j]!=-1)
            {
                v[cnt] = board[i][j]-1;
            }
            cnt++;
        }
        i--;
        for(int j=n-1;j>=0 && cnt<v.size();j--)
        {
            if(board[i][j]!=-1)
            {
                v[cnt] = board[i][j]-1;
            }
            cnt++;
        }
        
    }
    for(auto x:v)
    cout << x << " ";
    cout << endl << endl;
    
    vector<int>dis(n*n,INT_MAX);
    queue<int>q;
    q.push(0);
    dis[0]=0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=1;i<=6 && (x+i)<v.size();i++)
        {
            int next; 
            if(v[x+i]!=-1)next = v[x+i];
            else next = x+i;
            if(dis[next]==INT_MAX)
            {
                q.push(next);
                dis[next] = dis[x]+1;
            }
        }
    }

    return dis[n*n-1]==INT_MAX ? -1:dis[n*n-1];

    }
};