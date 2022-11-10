string s;
vector<vector<string>> ans;
int n;

bool IsPalindrome(string s1)
{
    string temp = s1;
    reverse(temp.begin(),temp.end());
    return temp == s1;
}
void solve(int index,vector<string> choices)
{
    if(index == n)
    {
        ans.push_back(choices);
        return;
    }
    int left_over_length = n - index ; // left over length including character at index i 
    for(int i=1; i<=left_over_length; i++)
    {
        string temp = s.substr(index,i);
        if(IsPalindrome(temp))
        {
            choices.push_back(temp);
            solve(index + i,choices);
            choices.pop_back();
        }
    }

}

class Solution {
public:
    vector<vector<string>> partition(string s1) 
    {
        s = s1;
        n = s.length();
        ans.clear();
        vector<string> choices;
        solve(0,choices);
        return ans;
    }
};
