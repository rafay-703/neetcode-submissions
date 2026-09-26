class Solution {
public:
    bool check(unordered_map<char,int>& mp1,unordered_map<char,int>& mp2)
    {
        for(auto [i,j]: mp1)
        {
            // cout << i << ": mp1: "<<j <<" mp2: "<<mp2[i] << endl;
            if(mp2[i] < j)  return false;
        }
        return true;
    }
    void test(unordered_map<char,int>& mp1,unordered_map<char,int>& mp2){
        cout << "test called" << endl;
        for(auto [i,j]: mp1)
        {
            cout << i << ": mp1: "<<j <<" mp2: "<<mp2[i] << endl;
            // if(mp2[i]!=j)  
        }
    }    
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        int n = s.length();
    
        for(auto&i : t)
        {
            mp1[i]++;
        }
        int l=0,r=0;
        int ans =INT_MAX;
        string best="";
        while(r<n)
        {
            while(r<n && !check(mp1,mp2))
            {
                mp2[s[r]]++;
                r++;
            }
            while(check(mp1,mp2))
            {
                mp2[s[l]]--;
                // test(mp1,mp2);
                if(!check(mp1,mp2))
                {
                    // cout << s.substr(l,r-l)<<endl;
                    if((r-l)<ans)
                    {
                        ans = r-l;
                        best = s.substr(l,ans);
                    }
                }
                l++;
            }
            
        }
        return best;
    }
};
