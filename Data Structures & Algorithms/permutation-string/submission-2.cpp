class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        vector<int> a(26,0);
        vector<int> b(26,0);
        int n1= s1.length(),n2 = s2.length();
        if(n1>n2) return 0;
        for(auto & i : s1) a[i-'a']++;
        for(int i=0;i<s1.length();i++) b[s2[i]-'a']++;
        
        for(int i=n1;i<n2;i++)
        {
            if(a==b) return true;
            
            b[s2[i-n1]-'a']--;
            b[s2[i]-'a']++;
            // cout << b[s2[i]-'a'] << " : "<<b[s2[i-n1]-'a'] << endl; 
        }
        return (a==b);

    }
};
