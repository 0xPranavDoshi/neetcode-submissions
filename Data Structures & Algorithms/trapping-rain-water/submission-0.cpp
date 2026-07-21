class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;

        vector<int> p(n);
        vector<int> s(n);

        p[0] = 0;
        for (int i = 1; i < n; i++) {
            p[i] = max(p[i-1], height[i-1]);
        }

        s[n-1] = 0;
        for (int i = n-2; i > 0; i--) {
            s[i] = max(s[i+1], height[i+1]);
        }

        for (int i = 0; i < n; i++) {
            int w = min(p[i], s[i]) - height[i];
            if (w > 0) total += w;
        }

        return total;
    }
};
