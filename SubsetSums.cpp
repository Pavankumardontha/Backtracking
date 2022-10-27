int n;
vector<int> ans,a;
void solve(int i,int sum)
{
    if(i==n)
    {
        ans.push_back(sum);
        return;
    }
    // take and move forward
    solve(i+1,sum + a[i]);
    // do not take and move forward
    solve(i+1,sum);
}

class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        ans.clear();
        a.clear();
        n = N;
        for(int i=0;i<arr.size();i++)
        a.push_back(arr[i]);
        solve(0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
