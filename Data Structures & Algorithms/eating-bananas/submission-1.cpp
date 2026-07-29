class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1;
        int max = *max_element(piles.begin(), piles.end());
        int k = max;

        while (min <= max) {
            int mid = min + (max - min) / 2;
            cout << "Mid is " << mid << "\n";
            int hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                int h_per_pile = ceil(static_cast<double>(piles[i]) / static_cast<double>(mid));
                hours += h_per_pile;
            }

            cout << "hours needed - " << hours << "\n";

            if (hours > h) {
                min = mid + 1;
            } else {
                cout << "Set k to " << mid << "\n";
                k = std::min(k, mid);
                max = mid - 1;
            }
        }

        return k;
    }
};
