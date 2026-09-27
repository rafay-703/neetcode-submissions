class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // move from the left most column to decide which row then apply binary search to that partucular row
        //
        int r = matrix.size(),c= matrix[0].size();
        int left = 0,right = r-1;
        int cs =-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(matrix[mid][0]<=target && matrix[mid][c-1]>=target)
            {
                cs = mid;
                break;
            }
            if(matrix[mid][0]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        if(cs==-1) return false;
         left = 0,right=c-1;
        while(left<=right)
        {

            int mid = (left+right)/2;
            if(matrix[cs][mid]==target) return true;
            if(matrix[cs][mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }

        }
        return false;

    }
};
