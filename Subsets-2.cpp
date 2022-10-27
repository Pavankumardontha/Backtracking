vector<vector<int>> ans;
vector<int> a;
int n;
void solve(int i,vector<int> choices)
{
    if(i==n)
    {
        for(int j=0;j<ans.size();j++)
        {
            if(ans[j]==choices)
                return;
        }
        ans.push_back(choices);
        return;
    }
    // do not take and move forward 
    solve(i+1,choices);
    // take and move forward
    choices.push_back(a[i]);
    solve(i+1,choices);
    choices.pop_back();
}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        // similar to combination sum - 2 problem 
        ans.clear();
        a.clear();
        n = nums.size();
        for(int i=0;i<n;i++)
            a.push_back(nums[i]);
        sort(a.begin(),a.end());
        vector<int> choices;
        solve(0,choices);
        return ans;
        
    }
};
