int n;
bool flag;
char board[14][14];
bool isValid(int x,int y,char val)
{
    //return true;
    for(int i=0;i<n;i++)
    {
        if(board[x][i]==val || board[i][y]==val)
        return false;
    }
    // given an (x,y) we need to determine the starting index (x1,y1) of the block if belongs to 
    int start_x = (x/3)*3;
    int start_y = (y/3)*3;
    for(int i=start_x ; i < start_x + 3; i++)
    {
        for(int j=start_y ; j< start_y + 3 ; j++)
        {
            if(board[i][j]==val)
            return false;
        }
    }
    return true;
}

void solve(int r,int c)
{
    if(r==n)
    {
        flag = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
            cout<<endl;
        }
        return;
    }
    if(flag == true)
    return;
    int next_r;
    int next_c;
    if(c==n-1)
    {
        next_r = r + 1;
        next_c = 0;
    }
    else
    {
        next_r = r;
        next_c = c + 1;
    }
    if(board[r][c]!='.')
    solve(next_r,next_c);
    else
    {
        for(char ch='1';ch<='9';ch++)
        {
            if(isValid(r,c,ch))
            {
                board[r][c]=ch;
                solve(next_r,next_c);
                if(flag == true)
                return;
                board[r][c]='.';
            }
        }
    }
}
class Solution {
public:
    void solveSudoku(vector<vector<char>>& b) 
    {
        n = b.size();
        flag = false;
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<n;j++)
            board[i][j] = b[i][j];
        }
        solve(0,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
            cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            b[i][j]=board[i][j];
        }
        return;
    }
};
