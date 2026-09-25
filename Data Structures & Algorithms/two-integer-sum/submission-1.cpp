class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int x=0;
        bool backup = false;
        int n1,n2;
        for(auto & i : nums)
  {
    if(mp.count(target - i) ){
        return {mp[target - i],x};
    }

    mp[i]=x++;
  }
  return {};
    }
};
