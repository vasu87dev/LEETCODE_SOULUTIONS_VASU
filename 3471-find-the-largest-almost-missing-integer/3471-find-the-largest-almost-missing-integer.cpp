class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {


        int l=0;
        int r=l+k-1;
        int hash[51]={0};
        int ans=-1;
        int count=0;
        while(r<nums.size())
        {
            for(int i=l;i<=r;i++)
            {
                hash[nums[i]]++;

            }
            count++;
            l++;
            r++;
        }
        
        for(int i=0;i<51;i++)
        {
           if(count==1 && hash[i]>0)
           {
            ans=max(ans,i);
           }
            else if(hash[i]==1)
             {
                ans=max(ans,i);
             }
             
        }
        if(ans==-1)
        {
            return -1;
        }
        return ans;
        
    }
};