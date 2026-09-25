class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0;
        int i = 0, j = n-1;
        int ans = (j-i-1) * min(height[i],height[j]);
        int left = i, right = j;
        while(i < j)
        {
            if(height[left] < height[right])
            {
                i++;
                if(i>=right) break;
                if(height[i] <= height[left])
                    ans -= height[i];
                else
                {
                    ans -=height[left];
                    ans += (right - i - 1) * min(height[i],height[right]); 
                    ans -= (right - i - 1) * min(height[left],height[right]);
              
                    left = i;

                }
            }
            else
            {
                j--;
                if(j<=left) break;
                if(height[j] <= height[right])
                    ans -= height[j];
                else
                {
                    ans -=height[right];
                    ans += (j - left - 1) * min(height[left],height[j]); 
                    ans -= (j - left - 1) * min(height[left],height[right]);
              
        // cout << ans << " : " << left << " : " << right << " : " << j << " : "   << i << endl;
                    right = j;
                }
                
            }
                //   cout << ans << " : " << left << " : " << right << " : " <<j << " : "   << i << endl;
        }
        return ans;
    }
};
