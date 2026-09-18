class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
public:    
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key)) return "";
        vector<pair<int, string>>& val_array = m[key];
        int n = val_array.size();

        string value = "";
        int l = 0, r = n-1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int ts = val_array[mid].first;

            if (ts <= timestamp) {
                value = val_array[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return value;
    }
};
