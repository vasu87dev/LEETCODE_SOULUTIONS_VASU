class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<int, int> hash;
        long long maxi = 0;

        int l = 0;
        int s = 0;

        while (l < nums.size()) {
            hash[nums[l]]++;
            sum += nums[l];

            if (l - s + 1 == k) {
                if (hash.size() == k) {
                    maxi = max(maxi, sum);
                }

                sum -= nums[s];
                hash[nums[s]]--;

                if (hash[nums[s]] == 0) {
                    hash.erase(nums[s]);
                }

                s++;
            }

            l++;
        }

        return maxi;
    }
};