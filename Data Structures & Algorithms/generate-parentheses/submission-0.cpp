class Solution {
public:
    vector<string> res;
    void dfs(int i,int n,string s)
    {
        if(i==0 && n ==0)
        {
            res.push_back(s);
        }
        if(n>0)
        {
            dfs(i+1,n-1,s+'(');
        }
        if(i>0)
        {
            dfs(i-1,n,s+')');
        }
    }
    vector<string> generateParenthesis(int n, string s="") {
        // n i+1,i-1
        // n-1
        dfs(0,n,s);
        return res;

    }
};
