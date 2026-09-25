class Solution {
public:
    int maxProfit(vector<int>& prices) {

     int n = prices.size();
     int l = 0,r = 1;
     int ans =0;
     for( ;r<n;r++)

     {
        if(prices[l] < prices[r])
        {
            int p = prices[r]-prices[l];
            ans = max ( ans , p);
        }
        else{
            l = r;
        }
        // cout << l << " : " << r << endl;
     }
     return ans;   
    }
};
