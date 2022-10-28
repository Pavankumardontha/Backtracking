bool board[10][10];
bool d1[20];
bool d2[20];
int ans;
int n;
bool isValid(int r,int c)
{
    for(int i=0;i<n;i++)
    {
        if(board[i][c]==true)
            return false;
    }
    for(int i=0;i<n;i++)
    {
        if(board[r][i]==true)
            return false;
    }
    if(d1[r+c]==true || d2[r-c+n-1]==true)
        return false;
    return true;
}
void solve(int r)
{
    if(r==n)
    {
        ans++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isValid(r,i))
        {
            board[r][i]=true;
            d1[r+i] = true;
            d2[r-i+n-1] = true;
            solve(r+1);
            board[r][i]=false;
            d1[r+i] = false;
            d2[r-i+n-1] = false;
        }
    }
}
class Solution {
public:
    int totalNQueens(int N1) 
    {
        ans = 0;
        n = N1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                board[i][j]=false;
        for(int i=0;i<2*n-1;i++)
        {
            d1[i]=false;
            d2[i]=false;
        }
        solve(0);
        return ans;
    }
};
