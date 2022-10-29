vector<vector<int>> ans;
int a[20];
int n;
void solve(int i, vector<int> choices)
{
    if(i==n)
    {
        ans.push_back(choices);
        return;
    }
    // take and move forward 
    choices.push_back(a[i]);
    solve(i+1,choices);
    choices.pop_back();
    // do not take and move forward
    solve(i+1,choices);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        ans.clear();
        n = nums.size();
        for(int i=0;i<n;i++)
            a[i]=nums[i];
        vector<int> choices;
        solve(0,choices);
        return ans;
    }
};
