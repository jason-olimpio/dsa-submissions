class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pairs;
        stack<double> fleetTimes;

        for (int i = 0; i < position.size(); i++) {
            pairs.push_back({ position[i], speed[i] });
        }

        sort(pairs.rbegin(), pairs.rend());

        for (auto &p : pairs) {
            double timeToTarget = static_cast<double>(target - p.first) / p.second;

            if (fleetTimes.empty() || timeToTarget > fleetTimes.top()) {
                fleetTimes.push(timeToTarget);
            }
        }

        return fleetTimes.size();
    }
};