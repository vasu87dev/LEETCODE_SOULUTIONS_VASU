class Solution {
public:
    const long long LIM = 1000001;

    long long cntWays(vector<int>& a1) {
        int a2 = 0;
        for (int x : a1) a2 += x;

        long long a3 = 1;
        int a4 = 0;

        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= a1[i]; j++) {
                a4++;
                a3 = a3 * a4 / j;
                if (a3 > LIM) a3 = LIM;
            }
        }
        return a3;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> a1(26, 0);

        for (char c : s) a1[c - 'a']++;

        string a2 = "";
        char a3 = 0;

        for (int i = 0; i < 26; i++) {
            if (a1[i] % 2) a3 = char('a' + i);
            a1[i] /= 2;
        }

        if (cntWays(a1) < k) return "";

        int a4 = s.size() / 2;

        while ((int)a2.size() < a4) {
            for (int i = 0; i < 26; i++) {
                if (a1[i] == 0) continue;

                a1[i]--;

                long long a5 = cntWays(a1);

                if (a5 >= k) {
                    a2.push_back(char('a' + i));
                    break;
                }

                k -= a5;
                a1[i]++;
            }
        }

        string a6 = a2;
        reverse(a6.begin(), a6.end());

        if (a3) return a2 + string(1, a3) + a6;
        return a2 + a6;
    }
};