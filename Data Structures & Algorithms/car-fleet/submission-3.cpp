class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, float>> cars;
        stack<float> s;
        int fleet_count = 1;

        cout << "Car | Pos | Time\n";
        for (int i = 0; i < n; i++) {
            float time = (target - position[i]) / (speed[i] * 1.0);            
            cars.push_back({position[i], time});            
        }

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        for (int i = 0; i < n; i++) {
            cout << " " << i << "  |  " << cars[i].first << "  |  " << cars[i].second << "\n";            
        }

        s.push(cars[0].second);

        for (int i = 0; i < n; i++) {            
            if (cars[i].second > s.top()) {
                fleet_count++;
                cout << "Increasing fleet count at " << i << "\n";
                // cout << "Fleet time is " << fleet_time << "\n";
                s.push(cars[i].second);
            }
        }

        return fleet_count;
    }
};
