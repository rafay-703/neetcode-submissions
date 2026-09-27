class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        // 30,38,30,36,35,40,28
        // 0,0,0,0,0,1,0,0
        stack<pair<int,int>> stk;
        int n = t.size();
        vector<int> res(n,0);
        for(int i=0;i<t.size();i++)
        {
            while(!stk.empty() && t[i] > stk.top().first )
            {
                auto pair = stk.top();stk.pop();
                res[pair.second]=i-pair.second;
            }
            stk.push({t[i],i});
        }
        return res;
    }
};
