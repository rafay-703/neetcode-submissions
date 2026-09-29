class Solution {
public:
    void creation(set<vector<int>>& ans,vector<int> res
        ,vector<int>& nums,int i,int n)
    {
        if(i==n) return;
        auto tmp = res;
        res.push_back(nums[i]);
        ans.insert(res);
        ans.insert(tmp);
        creation(ans,tmp,nums,i+1,n);
        creation(ans,res,nums,i+1,n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> ans;
        creation(ans,{},nums,0,nums.size());
        vector<vector<int>> res;
        for(auto i: ans)
        {
            res.push_back(i);
        }
        return res;
    }
};
