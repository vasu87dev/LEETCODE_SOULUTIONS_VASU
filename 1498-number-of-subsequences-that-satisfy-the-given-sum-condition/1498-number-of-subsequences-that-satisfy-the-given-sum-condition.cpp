#include<cmath>
class Solution {
public:

    int numSubseq(vector<int>& nums, int target) {



sort(nums.begin(),nums.end());
long long count=0;
const long long MOD = 1e9 + 7;
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            long long sum=nums[l]+nums[r];
if(sum<=target)
{
     count = (count + power(2, r - l, MOD)) % MOD;
    l++;
}
else 
{
    r--;
}



        }    
        return count%MOD;    
    }
       long long power(long long base, long long exp, long long MOD) {

        long long ans = 1;

        while (exp > 0) {

            if (exp % 2 == 1) {
                ans = (ans * base) % MOD;
            }

            base = (base * base) % MOD;
            exp /= 2;
        }

        return ans;
    }
};