class Solution {
public:
    bool check(vector<int>& piles,int h, int k)
    {
        for(auto & i : piles)
        {
            h -= i/k + !(i%k==0);
        }
        return ((h>=0)?1:0);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(n>h) return -1;
        int left = 1, right = INT_MAX;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(check(piles,h,mid))
            {
                right=mid;
            }
            else
                left=mid+1;
            cout <<left<<" : "<< right << endl;
        }
        return right;
    }
};
