class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
         my_dict = defaultdict(list)
         for i in strs:
            my_dict["".join(sorted(i))].append(i)
         ans = []
         for i in my_dict:
            ans.append(my_dict[i])
         return ans