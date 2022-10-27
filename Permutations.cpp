# Permutations with no array duplicates !!
vector<vector<int>> ans;
int n;
vector<int> a;
void solve(vector<int> choices, vector<bool> vis)
{
    if(choices.size() == n)
    {
        ans.push_back(choices);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            choices.push_back(a[i]);
            solve(choices,vis);
            choices.pop_back();
            vis[i]=false;
        }
    }
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        ans.clear();
        a.clear();
        n = nums.size();
        vector<bool> vis(n);
        for(int i=0;i<n;i++)
            vis[i]=false;
        for(int i=0;i<n;i++)
            a.push_back(nums[i]);
        sort(a.begin(),a.end());
        vector<int> choices;
        solve(choices,vis);
        return ans;
    }
};
