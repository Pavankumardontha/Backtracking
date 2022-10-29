vector<string> ans;
int board[6][6];
bool vis[6][6];
int n;

bool isValid(int x, int y)
{
    if(x>=0 and x<n and y>=0 and y<n)
    {
        if(vis[x][y]==false and board[x][y]==1)
        return true;
    }
    return false;
}
void solve(int i, int j, string choices)
{
    if(i==n-1 and j==n-1)
    {
        ans.push_back(choices);
        return;
    }
    
    /* make visited of current node true */
    vis[i][j]=true;
    /* At any given location we have 4 choices
    a) UP 
    b) DOWN
    c) RIGHT
    d) LEFT
    */
    // up (i-1,j)
    if(isValid(i-1,j))
    solve(i-1,j,choices + 'U');
    // down (i+1,j)
    if(isValid(i+1,j))
    solve(i+1,j,choices + 'D');
    // left (i,j-1)
    if(isValid(i,j-1))
    solve(i,j-1,choices + 'L');
    // right (i,j+1)
    if(isValid(i,j+1))
    solve(i,j+1,choices + 'R');
    
    // un-visit
    vis[i][j]=false;
}

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n1) 
    {
        ans.clear();
        n = n1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            board[i][j]=m[i][j];
        }
        string choices="";
        memset(vis,false,sizeof(vis));
        if(board[0][0]==0)
        return ans;
        solve(0,0,choices);
        return ans;
        
        
    }
};
