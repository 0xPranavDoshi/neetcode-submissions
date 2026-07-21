class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i = 0;
        int j = n-1;
        int max = 0;

        while (i < j) {
            int a = (j-i) * min(heights[i], heights[j]);
            if (a > max) max = a;

            if (heights[i] < heights[j]) i++;
            else j--;
        }

        return max;
    }
};
