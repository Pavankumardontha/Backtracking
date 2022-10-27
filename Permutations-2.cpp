vector<vector<int>> ans;
vector<int> a;
int n;

void solve(vector<int> choices, vector<bool> vis)
{
    if(choices.size() == n)
    {
        ans.push_back(choices);
        return;
    }
    // store the list of unused characters used to fill up the current position in a set
    unordered_set<char> s;
    for(int i=0;i<n;i++)
    {
        if(!vis[i] and s.find(a[i])==s.end())
        {
            vis[i] = true;
            choices.push_back(a[i]);
            solve(choices,vis);
            choices.pop_back();
            vis[i]=false;
            s.insert(a[i]);
        }
    }
}
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        n = nums.size();
        ans.clear();
        a.clear();
        for(int i=0;i<n;i++)
            a.push_back(nums[i]);
        vector<bool> vis(n);
        for(int i=0;i<n;i++)
            vis[i]==false;
        vector<int> choices;
        solve(choices,vis);
        return ans;
        
        
    }
};
