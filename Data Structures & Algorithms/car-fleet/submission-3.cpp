class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> a(n);
        for(int i=0;i<position.size();i++)
        {
            a[i]={position[i],speed[i]};
        }   
        sort(a.begin(),a.end());
        vector<double> times(n,0);
        for(int i=0;i<n;i++)
        {
            int d = target-a[i].first;
            times[i]=(double)d/(double)a[i].second;
            // cout << times[i] <<" , ";
        }
        cout<<endl;
        int count =n;
        // int mx = times[0];
        stack<double> stk;
        stk.push(times[0]);
        for(int i=1;i<n;i++)
        {
            while(!stk.empty() && times[i] >=stk.top())
            {
                stk.pop();
            }
            stk.push(times[i]);
        }
        return stk.size();
        // 0 1 4 7
        // 1 2 2 1
        // 10 5 3 3 4 2 1
        // 
    }
};
