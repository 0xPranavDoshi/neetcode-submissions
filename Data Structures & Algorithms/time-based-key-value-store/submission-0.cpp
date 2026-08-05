class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        pair<int, string> val = {timestamp, value};
        if (m.count(key)) {            
            m[key].push_back(val);             
        } else {
            vector<pair<int, string>> vec = {val};
            m[key] = vec;
        }
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> val = m[key];

        if (val.empty() || val[0].first > timestamp) return "";

        int n = val.size();
        int l = 0, r = n-1;
        string res = "";

        while (l <= r) {
            int m = l + (r-l) / 2;
            pair<int, string> element = val[m];
            int t = element.first;

            if (t == timestamp) return element.second;

            if (t > timestamp) {
                r = m - 1;
            } else {
                res = element.second;
                l = m + 1;
            }
        }

        return res;
    }   
};
