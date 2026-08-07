class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> timeMap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({ value, timestamp });
    }
    
    string get(string key, int timestamp) {
        auto& values = timeMap[key];

        int l = 0, r = values.size() - 1;

        string result;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (values[m].second <= timestamp) {
                result = values[m].first;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return result;
    }
};
