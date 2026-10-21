class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s=0;
        double maxi=-DBL_MAX;
        int l=0;
        double sum=0;
        while(l<nums.size() )
        {
        
           sum=sum+nums[l];
           if(l==s+k-1)
           {
                        maxi=max(sum/k,maxi);
              sum=sum-nums[s];
              s=s+1;
              l=l+1;

           }
           else

           {
            
           l++;
        
           }
if(s+k>nums.size())
{
    break;
}

        }
       
            return maxi;
          
    }

};