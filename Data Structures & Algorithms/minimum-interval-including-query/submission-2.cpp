class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> qs;
        for (int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }

        sort(qs.begin(), qs.end());

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> res(queries.size(), -1);

        int i = 0;

        for (auto [q, index] : qs) {

            // Add every interval that starts <= q
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];

                int length = r - l + 1;

                pq.push({length, r});

                i++;
            }

            // Remove intervals that ended before q
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            // Smallest valid interval
            if (!pq.empty()) {
                res[index] = pq.top().first;
            }
        }

        return res;
    }
};