class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
int c1=numSubarray(nums,goal);
int c2=numSubarray(nums,goal-1);
return c1-c2;


    }
    int numSubarray(vector<int>& nums, int goal) {

int count =0;
        int l=0;int r=0;
        int sum=0;
        if(goal<0)
        {
            return 0;
        }
        while(r<nums.size())
        {
           
           sum=sum+nums[r];
            while(sum>goal)
            {
                
                sum=sum-nums[l];
                l++;

            }
            count=count+(r-l+1);
            r++;
        }







        return count ;


    }
};