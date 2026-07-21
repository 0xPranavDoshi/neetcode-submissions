class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        vector<int> p(n);
        vector<int> s(n);

        p[0] = nums[0];
        for (int i = 1; i < n; i++) {        
            p[i] = p[i-1] * nums[i];
        }

        s[n-1] = nums[n-1];
        for (int i = n-2; i > 0; i--) {        
            s[i] = s[i+1] * nums[i];
        }

        output[0] = s[1];
        output[n-1] = p[n-2];
        for (int i = 1; i < n-1; i++) {
            output[i] = p[i-1] * s[i+1];
        }

        return output;
    }
};
