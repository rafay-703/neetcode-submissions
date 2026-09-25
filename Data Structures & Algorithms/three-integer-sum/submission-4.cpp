class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {

            int target = -nums[i];
            int left = i+1,right = n-1;
            while (left < right)
            {
                if((nums[left]+nums[right]) > target)
                {
                    right--;
                }
                else if (nums[left]+nums[right] < target)
                {
                    left++;
                }
                else {
                    cout<< " i: "<< i  << " left: " << left << "  right: " << right << endl;
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right --;
                    while(left < right && nums[left]==nums[left-1]) left++;
                    while(left < right && nums[right]==nums[right+1]) right--;
                }
            }
            while(i < n -1 && nums[i]==nums[i+1]) i++;
            
        }
        return ans;
    }
};
