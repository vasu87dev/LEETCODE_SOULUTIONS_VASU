class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minpos = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxpos = max_element(nums.begin(), nums.end()) - nums.begin();

        if (minpos > maxpos)
            swap(minpos, maxpos);

        // 1. Both from left
        int left = maxpos + 1;

        // 2. Both from right
        int right = n - minpos;

        // 3. Min from left, max from right
        int both = (minpos + 1) + (n - maxpos);

        return min({left, right, both});
    }
};