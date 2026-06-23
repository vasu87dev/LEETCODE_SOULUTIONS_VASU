class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;
        if (m == 1) return 0;
        if (n == 2) return 1LL * m * (m - 1) % MOD;

        vector<int> up(m), down(m), newUp(m), newDown(m), prefix(m + 1);

        // length = 2
        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {

            // prefix sums of down
            prefix[0] = 0;
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = (prefix[i] + down[i]) % MOD;
            }

            for (int i = 0; i < m; i++) {
                newUp[i] = prefix[i];
            }

            // prefix sums of up
            prefix[0] = 0;
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = (prefix[i] + up[i]) % MOD;
            }

            int totalUp = prefix[m];

            for (int i = 0; i < m; i++) {
                newDown[i] = (totalUp - prefix[i + 1] + MOD) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans += up[i];
            ans += down[i];
            ans %= MOD;
        }

        return ans;
    }
};