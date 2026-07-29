class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        unordered_map<int, int> f;
        for (int i = 0; i < n; i++) {
            f[people[i]]++;
        }

        unordered_map<int, int> used;

        // 1, 2, 2, 3, 3
        int i = 0;
        int j = n - 1;
        int boat_count = 0;
        while (i <= j) {
            if (i == j) {
                boat_count++;
                break;
            }
            if (people[i] + people[j] > limit) {
                cout << people[j] << " takes the boat\n";
                boat_count++;
                j--;
            } else {
                cout << people[i] << " and " << people[j] << " share the boat\n";
                boat_count++;
                i++; j--;
            }
        }

        return boat_count;
    }
};