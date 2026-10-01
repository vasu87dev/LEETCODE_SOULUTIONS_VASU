class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> ans;

        while(!nums.empty())
        {
            set<int> s;

            // Get all distinct values
            for(auto it : nums)
            {
                s.insert(it);
            }

            // Add them in ascending order
            for(auto it : s)
            {
                ans.push_back(it);
            }

            // Remove one occurrence of every value
            for(auto it : s)
            {
                auto pos = find(nums.begin(), nums.end(), it);
                nums.erase(pos);
            }
        }

        return ans;
    }
};