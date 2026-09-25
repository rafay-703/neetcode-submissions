class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left =0,right = n-1;
        int ans =0;
        while(left < right)
        {
            int curr = (right-left ) * min(heights[left],heights[right]);
             cout << left <<":" << right<< endl;
            ans = max( ans , curr);
            if(heights[left] < heights[right]) left++;
            else if(heights[right] <= heights[left])
                right--;
        }
        return ans;
    }
};
