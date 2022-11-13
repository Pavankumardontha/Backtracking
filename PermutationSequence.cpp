int cnt;
string ans,s;
int k;
int n;
bool vis[10];
void permute(string s1)
{
    if( s1.length() == n)
    {
        cnt = cnt + 1; // keeps the count of the permutations
        if(cnt == k)
        {
            // if it is the kth permutation , then store the permutation in the answer
            ans = s1;
        }
        return;
    }
    if(ans.length() == n)
    {
        // if we already have the answer we need not explore other permutations !!
        return;
    }
    for(int i=0;i<n;i++)
    {
        // since we are visiting in order , the permutations always comes in order !!
        if(vis[i]==false)
        {
            vis[i]=true;
            permute(s1+s[i]);
            vis[i]=false;
        }
    }
}


class Solution {
public:
    string getPermutation(int n1, int k1) 
    {
        s = "";
        n = n1;
        k = k1;
        // constructing the string
        for(int i=1;i<=n;i++)
        s = s + to_string(i);
        for(int i=0;i<s.length();i++)
        vis[i]=false;
        cnt = 0; // current count of the permutation
        ans.clear();
        string s1="";
        permute(s1);
        return ans;        
    }
};
