class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mp = set()
        for i in nums:
            mp.add(i);
        # mn = min(nums)
        sc =0
        bc = 0
        for i in nums:
            while i in mp:
                print(i)
                sc+=1
                i+=1
            bc = max(bc,sc)
            sc = 0
        return bc
        