class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        if(s.empty()) return 0;
       int n = s.length();
        int i=0,j=1;
        mp[s[i]]++;
        int ans = 1;
        while(j<n)
        {
            while(mp[s[j]]  > 0)
            {
                mp[s[i++]]--;
            }
            mp[s[j]]++;
            ans = max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};
