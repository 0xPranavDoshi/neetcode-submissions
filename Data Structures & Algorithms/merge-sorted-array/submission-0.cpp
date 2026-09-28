class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < m; i++) {
            min_heap.push(nums1[i]);
        }

        for (int i = 0; i < n; i++) {
            min_heap.push(nums2[i]);
        }

        for (int i = 0; i < m + n; i++) {
            nums1[i] = min_heap.top();
            min_heap.pop();
        }        
    }
};