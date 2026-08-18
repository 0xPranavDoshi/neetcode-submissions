class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;

        int max = -1;      
        while (l < r) {
            int area = (r-l) * min(heights[l], heights[r]);
            if (area > max) max = area;

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max;
    }
};
