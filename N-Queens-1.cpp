bool board[10][10];
bool d1[20];
bool d2[20];
vector<vector<string>> ans;
int n;
/*
DIAGONAL ARRAYS EXPLAINATION :-
We have 2 types of diagonals in the square board. For every cell of the board , calculate (r+c) and (r-c). In case of (r-c) we get negative values and to overcome that we add (n-1) to (r-c). 
- if you have a (n*n) board , no of diagonals is 2*n-1.Each diagonal will have its corresponding cross diagonal which can be obtained by rotating the diagonal by 90 degrees. 
- if your diagonal is at index = r + c , then your corresponding cross diagonal is at index = r - c + n - 1. 
*/

/*
Can we put a Queen at position (r,c) in our current state ? The below function will answer to this question.We have to check for 3 conditions.whether we have alread kept a queen in this column or whether we have already kept a queen in this row.And also if any of
the diagonals of type d1 and d2 are already blocked.
*/
bool isValid(int r,int c)
{
    /* column check.keep the row fixed and check all the columns.*/
    for(int i=0;i<n;i++)
    if(board[r][i]==true)
    return false;
    
    /*row check.keep the column fixed and check all the rows.*/
    for(int i=0;i<n;i++)
    if(board[i][c]==true)
    return false;
    
    /*we will now check for diagonals whether any of the diagonal is blocked or not.We will
    return false,if any of the 2 diagonals are bloacked.*/
    if(d1[r+c]==true || d2[r-c+n-1]==true)
    return false;
    
    return true;
    
}


void solve(int r,vector<string> &choices)
{
    if(r==n)
    {
        // append the choices vector into ans vector
        ans.push_back(choices);
        return;
    }
    // iterating on all the columns of the current row r
    for(int i=0;i<n;i++)
    {
        if(isValid(r,i))
        {
            board[r][i]=true; // keeping queen at (r,i)
            d1[r+i]=true; // block board indexes present on diagonal one type.
            d2[r-i+n-1]=true; // block board indexes present on diagonal two type.
            choices[r][i]='Q'; 
            
            solve(r+1,choices);
            
            // undo all the above changes. 
            board[r][i]=false;
            d1[r+i]=false;
            d2[r-i+n-1]=false;
            choices[r][i]='.';            
        }
    }
}


class Solution {
public:
    vector<vector<string>> solveNQueens(int N) 
    {
        ans.clear();
        n = N;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                board[i][j]=false;
        for(int i=0;i<2*n-1;i++)
        {
            d1[i]=false;
            d2[i]=false;
        }
        // push empty dot strings into choices of length n-1.
        vector<string> choices(n);
        string empty = "";
        for(int i=0;i<n;i++)
            empty = empty + ".";
        for(int i=0;i<n;i++)
            choices[i]=empty;
        
        solve(0,choices);
        return ans;
        
        
    }
};
