class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int m = *max_element(people.begin(), people.end());
        int n = people.size();
        vector<int> count(m+1, 0);

        for (int p : people) count[p]++;

        vector<int> out;
        for (int i = 1; i <= m; i++) {
            while (count[i] > 0) {
                out.push_back(i);
                count[i]--;
            }
        }

        int i = 0;
        int j = n-1;
        int boats = 0;

        while (i <= j) {
            boats++;
            if (i == j) break;
            if (out[i] + out[j] <= limit) {
                i++;
            }
            j--;
        }

        return boats;
    }
};