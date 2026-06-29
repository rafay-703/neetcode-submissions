class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pd = 1
        zero_exist = 0
        for i in nums:
            if i==0:
                zero_exist+=1
            else:
                pd*=i
        if zero_exist>1:
            return [0] * len(nums)
        if zero_exist == 1:
            for i in range(len(nums)):
                if(nums[i]==0):
                    nums[i]=pd
                else:
                    nums[i]=0
                # nums[i]=pd // nums[i]
            return nums
            
        for i in range(len(nums)):
            nums[i]=pd // nums[i]
        return nums
        