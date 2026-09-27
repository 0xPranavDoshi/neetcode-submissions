class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i = 0, j = n-1;

        int max = 0;

        while (i < j) {
            int area = min(heights[i], heights[j]) * (j-i);

            if (area > max) max = area;

            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max;
    }
};
