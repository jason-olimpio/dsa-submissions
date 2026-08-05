class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        int result = r;

        while (l <= r) {
            int k = (r + l) / 2;
            long long hours = 0;

            for (int i = 0; i < piles.size(); i++) {
                hours += ceil(static_cast<double>(piles[i]) / k);
            }

            if (hours <= h) {
                result = min(result, k);
                r = k - 1;
            }

            else {
                l = k + 1;
            }
        }

        return result;
    }
};
