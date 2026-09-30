
class Solution {
    public:
        set<vector<int>> ans;
            void dfs(vector<int>& nums,vector<int> a,int target,int curr)
                {
                        for(int i=curr;i<nums.size();i++)
                                {
                                    if(i>curr && nums[i]==nums[i-1]) continue;
                                            if(nums[i]<=target)
                                                        {
                                                                        // target-=nums[i];
                                                                                        a.push_back(nums[i]);
                                                                                                        if((target-nums[i])==0)
                                                                                                                        {
                                                                                                                                            ans.insert(a);
                                                                                                                                                            }
                                                                                                                                                                            dfs(nums,a,target-nums[i],i+1);
                                                                                                                                                                                            // dfs(nums,a,target-nums[i],i+1);
                                                                                                                                                                                                            a.pop_back();
                                                                                                                                                                                                                            // dfs(nums,a,target,i+1);
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                   }
                                                                                                                                                                                                                                                       }
                                                                                                                                                                                                                                                           vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
                                                                                                                                                                                                                                                                   sort(nums.begin(),nums.end());
                                                                                                                                                                                                                                                                           dfs(nums,{},target,0);
                                                                                                                                                                                                                                                                                   vector<vector<int>> res;
                                                                                                                                                                                                                                                                                            for(auto i : ans)
                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                               res.push_back(i);
                                                                                                                                                                                                                                                                                                                   }
                                                                                                                                                                                                                                                                                                                           return res;
                                                                                                                                                                                                                                                                                                                               }
                                                                                                                                                                                                                                                                                                                               };


