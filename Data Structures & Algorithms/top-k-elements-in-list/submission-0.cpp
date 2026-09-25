class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        for(auto & i : nums)
 {
    mp[i]++;
 }
 for(auto [i,j] : mp)
 {
    pq.push({j,i});
 }
 vector<int> ans;
 while(k-->0)
  ans.push_back(pq.top().second),pq.pop();
return ans;

    }
};
