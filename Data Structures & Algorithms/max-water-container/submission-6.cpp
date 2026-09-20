class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int maxA = INT_MIN;        
        
        int i = 0, j = n-1;
        while (i < j) {
            int area = min(heights[j], heights[i]) * (j-i);

            maxA = max(maxA, area);

            if (heights[i] < heights[j]) i++;
            else j--;
        }

        return maxA;
    }
};
