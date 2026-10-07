class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            {
                if(nums[nums[i]-1]==nums[i]) return nums[i];       
                swap(nums[i],nums[nums[i]-1]);
                i--;
            }
            
        }
        return -1;
    }
};
