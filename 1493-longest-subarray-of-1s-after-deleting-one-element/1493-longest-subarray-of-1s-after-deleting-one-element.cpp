class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        vector<int>hash(2,0);
        int ans=0;
        int s=0;
        int l=0;

        while(l<nums.size())
        {
            hash[nums[l]]++;
            while(hash[0]>1)
            {
                ans=max(ans,hash[1]);
                hash[nums[s]]--;
                s++;
                

            }
        
            ans=max(ans,hash[1]);
                l++;
            
        }
        if(hash[0]==0)
        {
            return hash[1]-1;
        }
        else if(hash[0]==1)
        {
        return ans;
        }
        else
        {
            return 0;
        }
    }
};