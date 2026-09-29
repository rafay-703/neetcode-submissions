class Solution {
public:
    vector<string> ans;
    void dfs(string digits,vector<string>& mp,string curr,int i)
    {
        
        if(curr.length()==digits.length())
        {
            ans.push_back(curr);
            return;
        }
        if(i>=digits.length()) return;
        for(auto j : mp[digits[i]-'0'])
        {
            // cout << j << endl;
         
                // curr = curr + k;
                dfs(digits,mp,curr+j,i+1);
            
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mp
        {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        dfs(digits,mp,"",0);
        return ans;
    }
};
