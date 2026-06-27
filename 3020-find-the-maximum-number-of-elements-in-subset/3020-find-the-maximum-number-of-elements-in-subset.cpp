class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 1;

        // Handle 1 separately
        if (cnt.count(1)) {
            int c = cnt[1];
            ans = max(ans, (c % 2 == 0) ? c - 1 : c);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!cnt.count(cur)) {
                    len--;
                    break;
                }

                if (cnt[cur] == 1) {
                    len++;
                    break;
                }

                // Need two copies of every non-center element
                len += 2;

                // cur^2 exceeds maximum possible value
                if (cur > 31622) {
                    len--;
                    break;
                }

                cur *= cur;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};