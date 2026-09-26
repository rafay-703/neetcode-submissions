class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1,0);
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }
        ans[0]=pq.top().first;
        for(int i=k;i<n;i++)
        {
            while(!pq.empty() && pq.top().second <= i-k) pq.pop();
            pq.push({nums[i],i});
            ans[i-k+1]=pq.top().first;
        }
        return ans;
    }
};
