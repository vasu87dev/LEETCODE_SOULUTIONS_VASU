class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;

        // Count white blocks in the first window
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                count++;
            }
        }

        int ans = count;

        // Slide the window
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                count++;
            }

            if (blocks[i - k] == 'W') {
                count--;
            }

            ans = min(ans, count);
        }

        return ans;
    }
};