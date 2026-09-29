class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums,vector<int> a,int target,int curr)
    {
        for(int i=curr;i<nums.size();i++)
        {
            if(nums[i]<=target)
            {
                // target-=nums[i];
                a.push_back(nums[i]);
                if((target-nums[i])==0)
                {
                    ans.push_back(a);
                    return;
                }
                dfs(nums,a,target-nums[i],i);
                // dfs(nums,a,target-nums[i],i+1);
                a.pop_back();
                // dfs(nums,a,target,i+1);
            }
            else
            {
                return;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        dfs(nums,{},target,0);
        // vector<vector<int>> res;
        // for(auto i : ans)
        // {
        //     res.push_back(i);
        // }
        return ans;
    }
};
